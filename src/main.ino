// Motor A connections (right side)
int enA = 6;  // Enable pin for motor A (PWM)
int in1 = 12; // Input 1 for motor A
int in2 = 11; // Input 2 for motor A

// Motor B connections (left side)  
int enB = 5;  // Enable pin for motor B (PWM)
int in3 = 10; // Input 3 for motor B
int in4 = 9;  // Input 4 for motor B

char command;

void setup()
{
  // Initialize all motor control pins as outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  // Initialize Serial communication at 9600 baud rate
  Serial.begin(9600);
  
  // Stop the motors initially
  stopMotors();
}

void loop()
{
  if(Serial.available() > 0)
  {
    command = Serial.read();
    Serial.print("Received: "); // Debug feedback
    Serial.println(command);
    
    switch(command) {
      case 'F': // Move Forward
        moveForward();
        break;
      case 'B': // Move Backward
        moveBackward();
        break;
      case 'R': // Turn Right
        turnRight();
        break;
      case 'L': // Turn Left
        turnLeft();
        break;
      case 'S': // Stop
        stopMotors();
        break;
      case 'G': // Forward Left (often used in apps)
        forwardLeft();
        break;
      case 'I': // Forward Right (often used in apps)
        forwardRight();
        break;
      case 'H': // Backward Left (often used in apps)
        backwardLeft();
        break;
      case 'J': // Backward Right (often used in apps)
        backwardRight();
        break;
    }
  }
}

// Motor control functions
void moveForward() {
  // Right motor forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // Left motor forward
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // Set speed (0-255)
  analogWrite(enA, 200);
  analogWrite(enB, 200);
}

void moveBackward() {
  // Right motor backward
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // Left motor backward
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  // Set speed
  analogWrite(enA, 200);
  analogWrite(enB, 200);
}

void turnRight() {
  // Right motor stop (or backward for sharper turn)
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // Left motor forward
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // Set speed
  analogWrite(enA, 150);
  analogWrite(enB, 200);
}

void turnLeft() {
  // Right motor forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // Left motor stop (or backward for sharper turn)
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  // Set speed
  analogWrite(enA, 200);
  analogWrite(enB, 150);
}

void forwardRight() {
  // Right motor slower
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // Left motor faster
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 150);
  analogWrite(enB, 200);
}

void forwardLeft() {
  // Right motor faster
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // Left motor slower
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 200);
  analogWrite(enB, 150);
}

void backwardRight() {
  // Right motor slower backward
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // Left motor faster backward
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, 150);
  analogWrite(enB, 200);
}

void backwardLeft() {
  // Right motor faster backward
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // Left motor slower backward
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, 200);
  analogWrite(enB, 150);
}

void stopMotors() {
  // All motors stop
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}