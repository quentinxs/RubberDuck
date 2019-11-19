#include "Keyboard.h"

void setup() {
  Keyboard.begin();
}

void loop() {
  delay(1000);

  // CTRL-ALT-DEL:
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_DELETE);
  delay(1000);
  Keyboard.releaseAll();
  // RIGHT nad Enter to confirm:
  Keyboard.write(KEY_RIGHT_ARROW);
  delay(100);
  Keyboard.write(KEY_RETURN);

  // do nothing:
  while (true);
}
