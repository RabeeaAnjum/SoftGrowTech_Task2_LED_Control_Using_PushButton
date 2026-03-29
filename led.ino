const int BUTTON_PIN = 3;      // Connect the Button to pin 3
const int LED_PIN = 7;         // Connect the LED to pin 7

int lastButtonState = LOW;    // tracks the previous state of button
int currentButtonState = LOW; // the current state of button

void setup() {
  Serial.begin(9600);          // initialize serial
  pinMode(BUTTON_PIN, INPUT);  // set Arduino pin to input mode
  pinMode(LED_PIN, OUTPUT);    // set Arduino pin to output mode
}

void loop() {
  lastButtonState = currentButtonState;      // save the last state
  currentButtonState = digitalRead(BUTTON_PIN); // read new state

  if (currentButtonState == HIGH && lastButtonState == LOW) {
    digitalWrite(LED_PIN, !digitalRead(LED_PIN)); // toggle LED state
    delay(200); // debounce delay
  }
}