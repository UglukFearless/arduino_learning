#define BUZZER_PIN 13
#define KEY_1_PIN 2
#define KEY_2_PIN 4
#define KEY_3_PIN 7
#define KEY_4_PIN 8
#define KEY_5_PIN 9

void setup() {
  // put your setup code here, to run once:
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // read input states
  boolean keyUp1 = !digitalRead(KEY_1_PIN);
  boolean keyUp2 = !digitalRead(KEY_2_PIN);
  boolean keyUp3 = !digitalRead(KEY_3_PIN);
  boolean keyUp4 = !digitalRead(KEY_4_PIN);
  boolean keyUp5 = !digitalRead(KEY_5_PIN);

  if (keyUp1) {
    // A
    int frequency = 440;
    tone(BUZZER_PIN, frequency, 20);
  } else if (keyUp2) {
    // G
    int frequency = 392;
    tone(BUZZER_PIN, frequency, 20);
  } else if (keyUp3) {
    // F
    int frequency = 349;
    tone(BUZZER_PIN, frequency, 20);
  } else if (keyUp4) {
    // E
    int frequency = 330;
    tone(BUZZER_PIN, frequency, 20);
  } else if (keyUp5) {
    // D
    int frequency = 294;
    tone(BUZZER_PIN, frequency, 20);
  }
}
