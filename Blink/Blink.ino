void setup() {
  pinMode(13, OUTPUT);  // Enabling pin 13 for the output
}
void loop() {
  digitalWrite(13, HIGH);  // on
  delay(1000);             // 1 second
  digitalWrite(13, LOW);   // off
  delay(1000);             // 1 second
}
