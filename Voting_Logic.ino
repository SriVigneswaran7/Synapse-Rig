const int SW1 = 8;
const int SW2 = 9;
const int SW3 = 10;
const int SW4 = 11;
const int LED = 6;

int switchesPressed = 0;

void setup() {
  // Set switches as inputs
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  pinMode(SW3, INPUT);
  pinMode(SW4, INPUT);

  // Set LED as output
  pinMode(LED, OUTPUT);

  // Unused inputs (safe state)
  pinMode(5, INPUT);
  pinMode(3, INPUT);

  // LED initially OFF (active LOW)
  digitalWrite(LED, HIGH);
}

void loop() {
  switchesPressed = 0;

  // Count pressed switches
  if (digitalRead(SW1) == HIGH) switchesPressed++;
  if (digitalRead(SW2) == HIGH) switchesPressed++;
  if (digitalRead(SW3) == HIGH) switchesPressed++;
  if (digitalRead(SW4) == HIGH) switchesPressed++;

  // Turn LED ON if >= 3 switches pressed
  if (switchesPressed >= 3) {
    digitalWrite(LED, LOW);  // LED ON
  } else {
    digitalWrite(LED, HIGH); // LED OFF
  }

  delay(100); // debounce delay
}