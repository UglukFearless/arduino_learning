
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial) {
    Serial.print("Hello, Iskra!");
  }

  pinMode(13, OUTPUT);

  
  digitalWrite(13, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, LOW);
  delay(700);

  digitalWrite(13, HIGH);
  delay(300);
}
