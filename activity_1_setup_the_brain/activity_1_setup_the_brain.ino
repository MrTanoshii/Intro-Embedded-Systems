void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Open the Serial Port with speed 9600 bps
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Hello "); // Print "Hello "
  Serial.println("World!"); // Print "World!" and add a new line

  delay(2000);  // Wait for 2000 milliseconds
}
