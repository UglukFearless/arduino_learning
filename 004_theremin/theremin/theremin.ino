#define BUZZER_PIN 3
#define LDR_PIN A0

void setup() {
  // put your setup code here, to run once:
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(9600);
  while (!Serial) {
    Serial.println("Hello, Buzzer!");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = 0;
  int frequency = 0;

  // get input signal value (0 - 1023)
  val = analogRead(LDR_PIN);

  // convert value to another scale
  frequency = map(val, 0, 1023, 3500, 4500);

  Serial.println("input val: ");
  Serial.println(val);
  tone(BUZZER_PIN, frequency, 20);
}
