int latchPin = 8;
int clockPin = 12;
int dataPin = 11;
byte colDataMatrix[8] = {
  B01111111,
  B10111111,
  B11011111,
  B11101111,
  B11110111,
  B11111011,
  B11111101,
  B11111110};

byte rowDataMatrix[7][8] = {
  {B00000000,
   B00011000,
   B10111101,
   B01011010,
   B01111110,
   B00011000,
   B00100100,
   B01000010},
  {B00000000,
   B00000000,
   B00011000,
   B10111101,
   B01011010,
   B00111100,
   B01011010,
   B10100101},
  {B00000000,
   B00011000,
   B10111101,
   B01011010,
   B01111110,
   B00011000,
   B00100100,
   B01000010},
  {B00000000,
   B00000000,
   B00011000,
   B10111101,
   B01011010,
   B00111100,
   B01011010,
   B10100101},
  {B00000000,
   B00000000,
   B00011000,
   B11111110,
   B00011100,
   B01111100,
   B01011010,
   B10100101},
  {B00000000,
   B00000000,
   B00011000,
   B01111111,
   B00001111,
   B00001100,
   B00101101,
   B00110011},
  {B00000000,
   B00000001,
   B01111111,
   B00001111,
   B00001000,
   B00011000,
   B10011010,
   B11000010}
};

// 定義顯示器顯示的時間 (延遲時間), 預設 1ms
int delay_time = 1;

void setup() {
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
}


void loop() {
  for(int j = 0; j < 7; j++){
    for(int t = 0; t < 50; t++){
      for(int i = 0; i < 8 ; i++){
        byte colData = colDataMatrix[i];
        digitalWrite(latchPin,LOW);
        //pickDigit(i);
        shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
        shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix[j][i]);
        //shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
        digitalWrite(latchPin,HIGH);
        delay(1);
      }
    }
  }
}

void pickDigit(int x) {
  byte rowByte = 1 << x;
  shiftOut(dataPin, clockPin, MSBFIRST, rowByte);
}
