int led = 13;
int button = 2;

bool state = false;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop()
{
  if (digitalRead(button) == LOW)
  {
    state = !state;
    delay(300);
  }

  if (state == true)
  {
    digitalWrite(led, HIGH);
    delay(500);

    digitalWrite(led, LOW);
    delay(500);
  }
  else
  {
    digitalWrite(led, LOW);
  }
}