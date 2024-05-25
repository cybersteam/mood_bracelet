//Capabilities we want
//overall brightness
// button press number of times
// states:
//   warm
//   cool
//   crystal
//   etc.


// Assign PWM pins
const int pwmPin = 13;
const int pwmPin2 = 11;

// Pulse widths for each state
int state00 = 25;  // 10% duty cycle
int state01 = 75;  // 30% duty cycle
int state10 = 128; // 50% duty cycle (half of 256)
int state11 = 182; // 70% duty cycle
void setup() {
  // Set PWM pin as output
pinMode(pwmPin, OUTPUT);
pinMode(pwmPin2, OUTPUT);
}

void loop() {
  // Transmit each state with a delay
analogWrite(pwmPin, state00);
delay(1000);  
analogWrite(pwmPin, state01);
delay(1000);
analogWrite(pwmPin, state10);
delay(1000);
analogWrite(pwmPin, state11);
delay(1000);
analogWrite(pwmPin2, state01);
delay(1000);  
analogWrite(pwmPin2, state10);
delay(1000);
analogWrite(pwmPin2, state01);
delay(1000);
analogWrite(pwmPin2, state00);
delay(1000);

// Adjust delay to ensure stable PWM...
}
