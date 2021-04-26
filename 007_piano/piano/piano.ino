#define BUZZER_PIN 13
#define FIRST_KEY_PIN 7
#define KEY_COUNT 3 

void setup() {
  // put your setup code here, to run once:
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < KEY_COUNT; ++i) {
    int keyPin = i + FIRST_KEY_PIN;

    boolean keyUp = digitalRead(keyPin);

    if (!keyUp) {
      int frequency = 440 + i * 50;

      tone(BUZZER_PIN, frequency, 20);
    }
  }
}
