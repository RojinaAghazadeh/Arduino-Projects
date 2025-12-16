int ledPin = 13;
void setup()                         // run once, when the sketch starts
{
pinMode(ledPin, OUTPUT);            // sets the digital pin as output
}
void loop()
{
flash(200); flash(200); flash(200);  // S
delay(300);                        // otherwise the flashes run together
flash(500); flash(500); flash(500);  // O
flash(200); flash(200); flash(200);  // S
delay(1000);                       // wait 1 second before we start again
}
void flash(int duration)
{
digitalWrite(ledPin, HIGH);
delay(duration);
digitalWrite(ledPin, LOW);
delay(duration);
}