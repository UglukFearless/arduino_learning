#define CONTROL_PINE 9

int brightness = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(CONTROL_PINE, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // gradually increase the brightness (0 to 255 in cycle)
  brightness = (brightness + 1) % 256;

  analogWrite(CONTROL_PINE, brightness);

  delay(55 - (int)brightness/5);
}
