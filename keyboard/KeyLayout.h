#include "DigiKeyboard.h"
#include "string.h"

class KeyLayout {
private:
  float volt;
  char keys[13][5];
  float bias[13];
public:
  KeyLayout(float v, char k[][5], float b[]) {
    volt = v;
    for (int i = 0; i < 13; i++) {
      strcpy(keys[i], k[i]);
    }
    for (int j = 0; j < 13; j++) {
      bias[j] = b[j];
    }
  }

  //キーレイアウト
  void assign() {
    if (volt >= 0 && volt < bias[0]) {
      DigiKeyboard.sendKeyStroke(0);
      keyPrint(keys, 0);
      keyDelay();
    }
    // for (int i = 0; i < 13; i++) {
    //   if (volt >= bias[i] && volt < bias[i + 1]) {
    //     DigiKeyboard.sendKeyStroke(0);
    //     keyPrint(keys, i + 1);
    //     keyDelay();
    //   }
    // }
    if (volt >= bias[0] && volt < bias[1]) {
      DigiKeyboard.sendKeyStroke(0);
      keyPrint(keys, 1);
      keyDelay();
    }
    if (volt >= bias[1] && volt < bias[2]) {
      DigiKeyboard.sendKeyStroke(0);
      keyPrint(keys, 2);
      keyDelay();
    }
    if (volt >= bias[2] && volt < bias[3]) {
      DigiKeyboard.sendKeyStroke(0);
      keyPrint(keys, 3);
      keyDelay();
    }
    if (volt >= bias[3] && volt < bias[4]) {
      DigiKeyboard.sendKeyStroke(0);
      keyPrint(keys, 4);
      keyDelay();
    }
    if (volt >= bias[4] && volt < bias[5]) {
      DigiKeyboard.sendKeyStroke(0);
      keyPrint(keys, 5);
      keyDelay();
    }
    if (volt >= bias[5] && volt < bias[6]) {
      DigiKeyboard.sendKeyStroke(0);
      keyPrint(keys, 6);
      keyDelay();
    }
    if (volt >= bias[6] && volt < bias[7]) {
      DigiKeyboard.sendKeyStroke(0);
      keyPrint(keys, 7);
      keyDelay();
    }
    if (volt >= bias[7] && volt < bias[8]) {
      DigiKeyboard.sendKeyStroke(0);
      keyPrint(keys, 8);
      keyDelay();
    }
    if (volt >= bias[8] && volt < bias[9]) {
      DigiKeyboard.sendKeyStroke(0);
      keyPrint(keys, 9);
      keyDelay();
    }
    if (volt >= bias[9] && volt < bias[10]) {
      DigiKeyboard.sendKeyStroke(0);
      keyPrint(keys, 10);
      keyDelay();
    }
    if (volt >= bias[10] && volt < bias[11]) {
      DigiKeyboard.sendKeyStroke(0);
      keyPrint(keys, 11);
      keyDelay();
    }
    if (volt >= bias[11] && volt < bias[12]) {
      DigiKeyboard.sendKeyStroke(0);
      keyPrint(keys, 12);
      keyDelay();
    }
    if (volt >= bias[12] && volt < 4.60) {
      DigiKeyboard.sendKeyStroke(0);
      keyPrint(keys, 13);
      keyDelay();
    }
  }

  //キーの表示
  void keyPrint(char s[][5], int index) {
    DigiKeyboard.print(s[index]);
    DigiKeyboard.sendKeyStroke(KEY_X, MOD_ALT_LEFT);
  }

  //入力遅延
  void keyDelay() {
    DigiKeyboard.delay(200);
  }
};