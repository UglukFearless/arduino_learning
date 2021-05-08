#define PLUS_PIN 2
#define MINUS_PIN 3
#define LED_PIN 9

int brightness = 100;
boolean plusDown = true;
boolean minusDown = true;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(PLUS_PIN, INPUT_PULLUP);
  pinMode(MINUS_PIN, INPUT_PULLUP);
}

void loop() {
  analogWrite(LED_PIN, brightness);
  plusDown = handleClick(PLUS_PIN, plusDown, +35);
  minusDown = handleClick(MINUS_PIN, minusDown, -35);
}

boolean handleClick(int pin, boolean wasDown, int delta) {
  boolean isDown = digitalRead(pin);
  if (wasDown && !isDown) {
    delay(10);
    isDown = digitalRead(pin);

    if (!isDown) {
      brightness = constrain(brightness + delta, 0, 255);
    }
  }
  return isDown;
}