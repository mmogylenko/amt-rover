#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

int isUp = 0;

void setup()
{
  /* Start communication. */
  OneSheeld.begin();
  /* Set some pins as output. */
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.print("Setup done");

}

void loop()
{
  /* Always check the status of gamepad buttons. */
  if (GamePad.isUpPressed())
  {
    /* Turn on the LED on pin 13 when up is pressed. */
    digitalWrite(13, HIGH);
    isUp = 1;
  } else if (isUp == 1) {
    /* reset the LED if already on */
    digitalWrite(13, LOW);
    isUp = 0;
  }
  if (GamePad.isDownPressed())
  {
    /* Turn on the LED on pin 12 when down is pressed. */
    digitalWrite(12, HIGH);
    /* Turn off the other LEDs. */
    digitalWrite(13, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
  }
  if (GamePad.isUpPressed() && GamePad.isOrangePressed())
  {
    /* Turn on the LED on pin 11 when up and orange are pressed. */
    digitalWrite(11, HIGH);
    /* Turn off the other LEDs. */
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(10, LOW);
  }
  if (GamePad.isDownPressed() && GamePad.isRedPressed())
  {
    /* Turn on the LED on pin 10 when down and red are pressed. */
    digitalWrite(10, HIGH);
    /* Turn off the other LEDs. */
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
  }
}

