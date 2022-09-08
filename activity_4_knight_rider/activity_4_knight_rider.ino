// LED ON delay
int delay_time = 100;
const int delay_max = 150;
const int delay_min = 5;

// Delay increment when pressing pushbutton
const int increment = 5;

// LED pins
const int pin_led_one = 9;
const int pin_led_two = 8;
const int pin_led_three = 7;
const int pin_led_four = 6;
const int pin_led_five = 5;

// Pushbutton pins
const int pin_button_left = 3;
const int pin_button_right = 4;

void setup()
{
  // Set LED pins as output
  pinMode(pin_led_one, OUTPUT);
  pinMode(pin_led_two, OUTPUT);
  pinMode(pin_led_three, OUTPUT);
  pinMode(pin_led_four, OUTPUT);
  pinMode(pin_led_five, OUTPUT);

  // Set Pushbutton pins as input
  pinMode(pin_button_left, INPUT);
  pinMode(pin_button_right, INPUT);

  // Start Serial
  Serial.begin(9600);
}

void loop()
{
  handle_btn_press();
  switch_leds();
}

void handle_btn_press()
{
  // Read state of button (HIGH or LOW)
  const int button_left_state = digitalRead(pin_button_left);
  const int button_right_state = digitalRead(pin_button_right);

  Serial.print("Button states: ");
  Serial.print(button_left_state);
  Serial.println(button_right_state);

  // Ensure only one pushbutton is pressed
  if (button_left_state != button_right_state)
  {
    // Decrease delay if left button is pressed
    if (button_left_state == LOW)
    {
      delay_time -= increment;
      if (delay_time <= delay_min)
        delay_time = delay_min;
    }
    // Increase delay if left button is pressed
    if (button_right_state == LOW)
    {
      delay_time += increment;
      if (delay_time >= delay_max)
        delay_time = delay_max;
    }
    // Print new delay time
    Serial.print("New delay time: ");
    Serial.println(delay_time);
  }
}

void switch_leds()
{
  // Blink all leds sequentially
  blink_led(pin_led_one);
  blink_led(pin_led_two);
  blink_led(pin_led_three);
  blink_led(pin_led_four);
  blink_led(pin_led_five);
}

void blink_led(int pin_led)
{
  // Turn LED ON then back OFF after a delay
  digitalWrite(pin_led, HIGH);
  delay(delay_time);
  digitalWrite(pin_led, LOW);
}