#define BUTTON_PIN 3
#define LED_PIN 13

boolean buttonWasDown = false;
boolean ledEnable = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  boolean buttonIsDown = digitalRead(BUTTON_PIN);

  if (buttonWasDown && !buttonIsDown) {
    delay(10);

    buttonIsDown = digitalRead(BUTTON_PIN);

    if (!buttonIsDown) {
      ledEnable = !ledEnable;

      digitalWrite(LED_PIN, ledEnable);
    }
  }
  buttonWasDown = buttonIsDown;
}
