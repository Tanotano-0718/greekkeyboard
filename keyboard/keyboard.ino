#include "DigiKeyboard.h"
#include "KeyLayout.h"

const int VOL_PIN0 = A0;
const int VOL_PIN1 = A1;
const int VOL_PIN2 = 0;
const int VOL_PIN3 = 1;

char key0[][5] = { "03B1", "03B2", "03B3", "03B4", "03B5", "03B6", "03BC", "03BB", "03BA", "03B9", "03B8", "03B7", "03BD" };
char key1[][5] = { "03BE", "03BF", "03C0", "002B", "002D", "002F", "00D7", "03C5", "03C4", "03C3", "03C1", "03C6", "03C7" };  //{ξ, ο, π, +, -, /, ×, υ, τ, σ, ρ, φ, χ}
float bias0[13] = { 0.18, 0.54, 0.89, 1.25, 1.61, 1.97, 2.33, 2.68, 3.04, 3.40, 3.76, 4.11, 4.47 };

void setup() {
  pinMode(VOL_PIN0, INPUT);
  pinMode(VOL_PIN1, INPUT);
  analogReference(DEFAULT);
}

void loop() {
  float value0;
  float value1;
  float volt0;
  float volt1;

  value0 = analogRead(VOL_PIN0);
  value1 = analogRead(VOL_PIN1);
  float value2 = analogRead(VOL_PIN2);
  float value3 = analogRead(VOL_PIN3);

  volt0 = value0 * 4.76 / 1023.0;
  volt1 = value1 * 4.76 / 1023.0;
  //KeyLayout keylayout0(volt0, key0, bias0);
  KeyLayout keylayout1(volt1, key1, bias0);
  //keylayout0.assign();
  keylayout1.assign();
  
  // if (value2 = !0) {
  //   DigiKeyboard.sendKeyStroke(0);
  //   DigiKeyboard.print("03C8");  //ψ
  //   DigiKeyboard.sendKeyStroke(KEY_X, MOD_ALT_LEFT);
  //   DigiKeyboard.delay(200);
  // }

  // if (value3 = !0) {
  //   DigiKeyboard.sendKeyStroke(0);
  //   DigiKeyboard.print("03C9");  //ω
  //   DigiKeyboard.sendKeyStroke(KEY_X, MOD_ALT_LEFT);
  //   DigiKeyboard.delay(200);
  // }
}