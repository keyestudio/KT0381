/*
Keye New RFID Starter Kit
Project 37
RFID module
Edit By Keyes
*/

#include <SPI.h>

#define RST_PIN   5
#define SS_PIN    10
#define MAX_LEN   16   

// ================== Register Definition ==================
#define CommandReg     0x01
#define ComIrqReg      0x04
#define DivIrqReg      0x05
#define ErrorReg       0x06
#define FIFODataReg    0x09
#define FIFOLevelReg   0x0A
#define BitFramingReg  0x0D
#define ModeReg        0x11
#define TxControlReg   0x14
#define TxAutoReg      0x15
#define TModeReg       0x2A
#define TPrescalerReg  0x2B
#define TReloadRegL    0x2C
#define TReloadRegH    0x2D

#define PCD_IDLE       0x00
#define PCD_AUTHENT    0x0E
#define PCD_TRANSCEIVE 0x0C
#define PCD_RESETPHASE 0x0F

#define PICC_ANTICOLL  0x93
#define PICC_REQIDL    0x26

#define MI_OK          0
#define MI_ERR         2

// ================== Low-level SPI Read & Write ==================
void Write_MFRC522(byte addr, byte val) {
  digitalWrite(SS_PIN, LOW);
  SPI.transfer((addr << 1) & 0x7E);
  SPI.transfer(val);
  digitalWrite(SS_PIN, HIGH);
}

byte Read_MFRC522(byte addr) {
  byte val;
  digitalWrite(SS_PIN, LOW);
  SPI.transfer(((addr << 1) & 0x7E) | 0x80);
  val = SPI.transfer(0x00);
  digitalWrite(SS_PIN, HIGH);
  return val;
}

void SetBitMask(byte reg, byte mask) {
  Write_MFRC522(reg, Read_MFRC522(reg) | mask);
}

void ClearBitMask(byte reg, byte mask) {
  Write_MFRC522(reg, Read_MFRC522(reg) & (~mask));
}

void AntennaOn() {
  if (!(Read_MFRC522(TxControlReg) & 0x03)) {
    SetBitMask(TxControlReg, 0x03);
  }
}

void MFRC522_Reset() {
  Write_MFRC522(CommandReg, PCD_RESETPHASE);
}

void MFRC522_Init() {
  digitalWrite(RST_PIN, HIGH);
  MFRC522_Reset();
  
  Write_MFRC522(TModeReg, 0x8D);
  Write_MFRC522(TPrescalerReg, 0x3E);
  Write_MFRC522(TReloadRegL, 30);
  Write_MFRC522(TReloadRegH, 0);
  Write_MFRC522(TxAutoReg, 0x40);
  Write_MFRC522(ModeReg, 0x3D);
  AntennaOn();
}

// ================== Core Functions ==================
byte MFRC522_Request(byte reqMode, byte *TagType) {
  byte status;
  unsigned int backBits;
  Write_MFRC522(BitFramingReg, 0x07);
  TagType[0] = reqMode;
  status = MFRC522_ToCard(PCD_TRANSCEIVE, TagType, 1, TagType, &backBits);
  if ((status != MI_OK) || (backBits != 0x10)) status = MI_ERR;
  return status;
}

byte MFRC522_ToCard(byte command, byte *sendData, byte sendLen, byte *backData, unsigned int *backLen) {
  byte status = MI_ERR;
  byte irqEn = 0x00;
  byte waitIRq = 0x00;
  byte n;
  unsigned int i;
  
  if (command == PCD_AUTHENT) { irqEn = 0x12; waitIRq = 0x10; }
  if (command == PCD_TRANSCEIVE) { irqEn = 0x77; waitIRq = 0x30; }
  
  Write_MFRC522(ComIrqReg, 0x80);
  ClearBitMask(ComIrqReg, 0x80);
  SetBitMask(FIFOLevelReg, 0x80);
  Write_MFRC522(CommandReg, PCD_IDLE);
  
  for (i = 0; i < sendLen; i++) Write_MFRC522(FIFODataReg, sendData[i]);
  
  Write_MFRC522(CommandReg, command);
  if (command == PCD_TRANSCEIVE) SetBitMask(BitFramingReg, 0x80);
  
  i = 2000;
  do {
    n = Read_MFRC522(ComIrqReg);
    i--;
  } while ((i != 0) && !(n & 0x01) && !(n & waitIRq));
  
  ClearBitMask(BitFramingReg, 0x80);
  
  if (i != 0) {
    if (!(Read_MFRC522(ErrorReg) & 0x1B)) {
      status = MI_OK;
      if (n & irqEn & 0x01) status = MI_ERR;
      if (command == PCD_TRANSCEIVE) {
        n = Read_MFRC522(FIFOLevelReg);
        byte lastBits = Read_MFRC522(0x0C) & 0x07;
        if (lastBits) *backLen = (n - 1) * 8 + lastBits;
        else *backLen = n * 8;
        if (n == 0) n = 1;
        if (n > MAX_LEN) n = MAX_LEN;
        for (i = 0; i < n; i++) backData[i] = Read_MFRC522(FIFODataReg);
      }
    } else status = MI_ERR;
  }
  return status;
}

byte MFRC522_Anticoll(byte *serNum) {
  byte status;
  byte i;
  byte serNumCheck = 0;
  unsigned int unLen;
  Write_MFRC522(BitFramingReg, 0x00);
  serNum[0] = PICC_ANTICOLL;
  serNum[1] = 0x20;
  status = MFRC522_ToCard(PCD_TRANSCEIVE, serNum, 2, serNum, &unLen);
  if (status == MI_OK) {
    for (i = 0; i < 4; i++) serNumCheck ^= serNum[i];
    if (serNumCheck != serNum[i]) status = MI_ERR;
  }
  return status;
}

// ================== setup & loop ==================
void setup() {
  Serial.begin(9600);
  SPI.begin();
  
  pinMode(SS_PIN, OUTPUT);
  digitalWrite(SS_PIN, HIGH);
  pinMode(RST_PIN, OUTPUT);
  digitalWrite(RST_PIN, HIGH);
  
  MFRC522_Init();
  Serial.println("RFID reader ready. Please place card...");
}

void loop() {
  byte status;
  byte str[2];          // Stores card type, occupies 2 bytes
  byte serNum[5];       // Stores UID (5 bytes)
  
  // Search for card
  status = MFRC522_Request(PICC_REQIDL, str);
  if (status != MI_OK) {
    delay(100);
    return;
  }
  
  // Anti-collision and obtain UID
  status = MFRC522_Anticoll(serNum);
  if (status == MI_OK) {
    Serial.print("Card UID: ");
    for (byte i = 0; i < 5; i++) {
      if (serNum[i] < 0x10) Serial.print("0");
      Serial.print(serNum[i], HEX);
      if (i < 4) Serial.print(" ");
    }
    Serial.println();
  }
  
  delay(1000);
}
