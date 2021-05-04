#define MOTOR_PIN 9
#define FIRST_BUTTON_PIN 5
#define BUTTON_COUNT 3
#define SPEED_STEP (255/(BUTTON_COUNT - 1))

void setup() {
  // put your setup code here, to run once:
  pinMode(MOTOR_PIN, OUTPUT);

  for (int i = 0; i < BUTTON_COUNT; ++i) {
    pinMode(FIRST_BUTTON_PIN + i, INPUT_PULLUP);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < BUTTON_COUNT; ++i) {
    if (digitalRead(FIRST_BUTTON_PIN + i)) {
      continue;
    }

    int speed = i * SPEED_STEP;

    analogWrite(MOTOR_PIN, speed);
  }
}
