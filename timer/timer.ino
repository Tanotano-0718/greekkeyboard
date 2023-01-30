#include <DigiUSB.h>

const uint8_t MODE = 0b00000001;      //5桁7セグメント
const uint8_t DSET1 = 0b01000100;     //固定アドレス
const uint8_t DSET2 = 0b01000000;     //移動アドレス
const uint8_t ADRS = 0b11000000 | 0;  //アドレス00H
const uint8_t DISP = 0b10001001;      //表示設定：2/16
const int TimerControl = A0;

uint8_t DIO = 0;
uint8_t CLK = 1;
uint8_t STB = 2;
uint16_t num = 0;
uint8_t d[10] = { 0b01111110, 0b00001100, 0b10110110, 0b10011110, 0b11001100, 0b11011011, 0b11111010, 0b01001110, 0b11111110, 0b11011110 };
uint8_t th, h, tm, m;
float volt0;
float timer_switch;
int isActive;


void setup() {
  pinMode(TimerControl, INPUT);
  pinMode(DIO, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(STB, OUTPUT);
  digitalWrite(STB, HIGH);
  digitalWrite(DIO, LOW);
  digitalWrite(CLK, LOW);
  analogReference(DEFAULT);
  DigiUSB.begin();
}

void TM1630(uint8_t i, uint8_t j, uint8_t k, uint8_t l) {
  digitalWrite(STB, LOW);
  shiftOut(DIO, CLK, LSBFIRST, MODE);
  digitalWrite(STB, HIGH);

  digitalWrite(STB, LOW);
  shiftOut(DIO, CLK, LSBFIRST, DSET1);
  digitalWrite(STB, HIGH);
  //一桁目
  digitalWrite(STB, LOW);
  shiftOut(DIO, CLK, LSBFIRST, ADRS);
  shiftOut(DIO, CLK, LSBFIRST, d[i]);
  digitalWrite(STB, HIGH);
  //二桁目
  digitalWrite(STB, LOW);
  shiftOut(DIO, CLK, LSBFIRST, ADRS | 2);
  shiftOut(DIO, CLK, LSBFIRST, d[j]);
  digitalWrite(STB, HIGH);
  //三桁目
  digitalWrite(STB, LOW);
  shiftOut(DIO, CLK, LSBFIRST, ADRS | 4);
  shiftOut(DIO, CLK, LSBFIRST, d[k]);
  digitalWrite(STB, HIGH);
  //三桁目
  digitalWrite(STB, LOW);
  shiftOut(DIO, CLK, LSBFIRST, ADRS | 6);
  shiftOut(DIO, CLK, LSBFIRST, d[l]);
  digitalWrite(STB, HIGH);

  digitalWrite(STB, LOW);
  shiftOut(DIO, CLK, LSBFIRST, DISP);
  digitalWrite(STB, HIGH);
}

void loop() {
  volt0 = analogRead(TimerControl);
  timer_switch = volt0 * 4.6 / 1023;

  //何も押してないとき:5V, スタート・ストップを押したとき:0V, リセットを押したとき:2.5V
  //タイマースタート・ストップ
  if (timer_switch >= 2.0 && timer_switch <= 3.0) {
    if (isActive == LOW) {
      isActive = HIGH;
      delay(100);
    }else if (isActive == HIGH) {
      isActive = LOW;
      delay(100);
    }
  }


  if (isActive == HIGH) {
    th = num / 600;       //4桁目
    h = (num / 60) % 10;  //3桁目
    tm = (num / 10) % 6;  //2桁目
    m = num % 10;         //1桁目
    num++;
    TM1630(th, h, tm, m);
    DigiUSB.delay(1000);  // (20221121) 100 -> 1000に変更
  }

  DigiUSB.println(isActive);
  DigiUSB.delay(100);
}