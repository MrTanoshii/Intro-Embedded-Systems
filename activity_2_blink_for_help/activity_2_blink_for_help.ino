#define DOT 100
#define DASH 300
#define DOT_DASH_SPACE 100
#define LETTER_SPACE 300
#define WORD_SPACE 700

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600); // Open the Serial Port with speed 9600 bps

  pinMode(LED_BUILTIN, OUTPUT); // Set the digital pin for the built-in led to output mode
  digitalWrite(LED_BUILTIN, LOW);    // Turn LED OFF
  digitalWrite(LED_BUILTIN, HIGH);   // Turn LED ON
}

void loop()
{
  // put your main code here, to run repeatedly:
  Serial.print("SOS ");

  blink_letter_s();
  blink_letter_o();
  blink_letter_s();

  delay(WORD_SPACE - LETTER_SPACE);
  Serial.println(); // New line
}

void blink_letter_o()
{
  int i;

  // Send letter 'O'
  for (i = 0; i < 3; i++)
  {
    digitalWrite(LED_BUILTIN, HIGH); // Turn LED ON
    Serial.print("-");
    delay(DASH);                    // Wait for the duration of a dash
    digitalWrite(LED_BUILTIN, LOW); // Turn LED OFF
    delay(DOT_DASH_SPACE);          // Wait between dots and dashes
  }
  delay(LETTER_SPACE - DOT_DASH_SPACE); // Wait between letters
                                        // Note: remove dot_dash_space because it was already done before!
}

void blink_letter_s()
{
  int i;

  // Send letter 'S'
  for (i = 0; i < 3; i++)
  {
    digitalWrite(LED_BUILTIN, HIGH); // Turn LED ON
    Serial.print(".");
    delay(DOT);                     // Wait for the duration of a dot
    digitalWrite(LED_BUILTIN, LOW); // Turn LED OFF
    delay(DOT_DASH_SPACE);          // Wait between dots and dashes
  }
  delay(LETTER_SPACE - DOT_DASH_SPACE); // Wait between letters
                                        // Note: remove dot_dash_space because it was already done before!
}