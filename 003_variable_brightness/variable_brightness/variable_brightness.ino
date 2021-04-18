#define LED_PIN 9
#define POT_PIN A0

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  pinMode(POT_PIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int rotation = 0;
  int brightness = 0;

  rotation = analogRead(POT_PIN);
  brightness = rotation/4;

  analogWrite(LED_PIN, brightness);
}
