const int LED_PIN = 13;
const int BUTTON_PIN = 2;

bool blinking = false;

int lastButtonState = HIGH;

unsigned long previousMillis = 0;
const unsigned long blinkInterval = 500;

void setup()
{
  pinMode(LED_PIN, OUTPUT);

  // Button connected between pin 2 and GND
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  digitalWrite(LED_PIN, LOW);
}

void loop()
{
  int buttonState = digitalRead(BUTTON_PIN);

  // Detect button press
  if (lastButtonState == HIGH && buttonState == LOW)
  {
    blinking = !blinking;

    delay(50);   // simple debounce
  }

  lastButtonState = buttonState;

  // LED blinking
  if (blinking)
  {
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= blinkInterval)
    {
      previousMillis = currentMillis;

      digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    }
  }
  else
  {
    // Button pressed second time -> LED OFF
    digitalWrite(LED_PIN, LOW);
  }
}