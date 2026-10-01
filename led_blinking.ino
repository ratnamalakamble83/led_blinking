// Arduino Uno - LED Blinking

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH); // LED ON
  delay(500);                     // Wait 1 second

  digitalWrite(LED_BUILTIN, LOW);  // LED OFF
  delay(500);                     // Wait 1 second
}