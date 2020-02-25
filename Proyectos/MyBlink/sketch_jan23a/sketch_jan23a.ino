  #define ledA 5
  #define ledB 6
void setup() {
  // put your setup code here, to run once:
 pinMode(ledA, OUTPUT);
 pinMode(ledB, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledA, HIGH);
  digitalWrite(ledB, LOW);
  delay(500);
  digitalWrite(ledA, LOW);
  digitalWrite(ledB, HIGH);
  delay(500);
}
