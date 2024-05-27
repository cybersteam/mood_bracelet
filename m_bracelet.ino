//Capabilities we want
//overall brightness
// button press number of times
// states:
//   warm
//   cool
//   crystal
//   etc.

// Define inputs
const int buttonPin = 8;  // Pin connected to the button
const unsigned long debounceDelay = 50;  // Debounce time in milliseconds
const unsigned long doublePressDelay = 400;  // Maximum time between presses for a double press

// Assign PWM pins
const int pwmPin = 11;
const int pwmPin2 = 12;
const int pwmPin3 = 13;

// Pulse widths for each state
// 256 can be the highest
int pwm_state01 = 1;
int pwm_state02 = 32;
int pwm_state03 = 64;
int pwm_state04 = 96;
int pwm_state05 = 128;
int pwm_state06 = 160;
int pwm_state07 = 192;
int pwm_state08 = 224;

// Variables to store button state
bool buttonState = LOW;  // Current state of the button
bool lastButtonState = LOW;  // Previous state of the button
unsigned long lastDebounceTime = 0;  // Last time the button state was toggled
unsigned long firstPressTime = 0;  // Time of the first button press
int pressCount = 0;  // Number of presses detected

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);  // Initialize serial communication for debugging
  // Set PWM pin as output
  pinMode(pwmPin, OUTPUT);
  pinMode(pwmPin2, OUTPUT);
  pinMode(pwmPin3, OUTPUT);
}

void loop() {
  // Read the state of the button
  bool reading = digitalRead(buttonPin);

  // Check if the button state has changed (debouncing)
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  // If the button state is stable for debounceDelay milliseconds
  if ((millis() - lastDebounceTime) > debounceDelay) {
  // If the button state has changed
    if (reading != buttonState) {
      buttonState = reading;

      // If the button is pressed (active LOW)
      if (buttonState == LOW) {
        pressCount++;
        if (pressCount == 1) {
          firstPressTime = millis();
        }
      }
    }
  }

  // If there was a press and the delay has passed, determine the action
  if (pressCount > 0 && (millis() - firstPressTime) > doublePressDelay) {
    if (pressCount == 1) {
      function1();
    } else if (pressCount == 2) {
      function2();
    } else if (pressCount == 3) {
      function3();
    }
    pressCount = 0;  // Reset the press count
  }

  // Update the last button state
  lastButtonState = reading;

}

// Define the functions to be called on button presses
void function1() {
  analogWrite(pwmPin, pwm_state01);
  delay(1000);  
  analogWrite(pwmPin, pwm_state02);
  delay(1000);
  analogWrite(pwmPin, pwm_state03);
  delay(1000);
  analogWrite(pwmPin, pwm_state04);
  delay(1000);
  analogWrite(pwmPin2, pwm_state05);
  delay(1000);  
  analogWrite(pwmPin2, pwm_state06);
  delay(1000);
  analogWrite(pwmPin2, pwm_state07);
  delay(1000);
  analogWrite(pwmPin2, pwm_state08);
  delay(1000);
}

void function2() {
  analogWrite(pwmPin, pwm_state01);
  delay(1000);  
  analogWrite(pwmPin, pwm_state02);
  delay(1000);
  analogWrite(pwmPin, pwm_state03);
  delay(1000);
  analogWrite(pwmPin, pwm_state02);
  delay(1000);
  analogWrite(pwmPin2, pwm_state01);
  delay(1000);  
  analogWrite(pwmPin2, pwm_state02);
  delay(1000);
  analogWrite(pwmPin2, pwm_state03);
  delay(1000);
  analogWrite(pwmPin2, pwm_state02);
  delay(1000);
}

void function3() {
  analogWrite(pwmPin, pwm_state01);
  delay(1000);  
  analogWrite(pwmPin, pwm_state03);
  delay(1000);
  analogWrite(pwmPin, pwm_state05);
  delay(1000);
  analogWrite(pwmPin, pwm_state08);
  delay(1000);
  analogWrite(pwmPin2, pwm_state01);
  delay(1000);  
  analogWrite(pwmPin2, pwm_state03);
  delay(1000);
  analogWrite(pwmPin2, pwm_state05);
  delay(1000);
  analogWrite(pwmPin2, pwm_state08);
  delay(1000);
}
