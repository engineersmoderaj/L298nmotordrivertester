// Define motor control pins
const int motorPin1 = 8; // IN1
const int motorPin2 = 9; // IN2
const int enablePin = 10; // ENA

void setup() {
  // Set motor control pins as outputs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  
  // Start with the motor off
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  analogWrite(enablePin, 0);
}

void loop() {
  // Rotate motor forward
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  for (int speed = 0; speed <= 255; speed += 5) {
    analogWrite(enablePin, speed); // Gradually increase speed
    delay(100); // Wait for 100 ms
  }
  
  // Hold at full speed for 2 seconds
  delay(2000);
  
  // Rotate motor backward
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  for (int speed = 255; speed >= 0; speed -= 5) {
    analogWrite(enablePin, speed); // Gradually decrease speed
    delay(100); // Wait for 100 ms
  }
  
  // Hold at full speed for 2 seconds
  delay(2000);
  
  // Stop the motor
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  analogWrite(enablePin, 0);
  
  // Wait for 2 seconds before repeating
  delay(2000);
}