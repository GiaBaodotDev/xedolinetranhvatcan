int lineSensor1 = A0;
int lineSensor2 = A1;
int obstacleSensor = 8;
int ena = 2;
int motorPin1 = 3;
int motorPin2 = 4;
int motorPin3 = 5;
int motorPin4 = 6;
int enb = 7;

void setup() {
  pinMode(lineSensor1, INPUT);
  pinMode(lineSensor2, INPUT);
  pinMode(obstacleSensor, INPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
}

void loop() {
  int leftSensorValue = digitalRead(lineSensor1);
  int rightSensorValue = digitalRead(lineSensor2);
  
  if (obstacleDetection()) {
    avoidObstacle();
  } else if (leftSensorValue == LOW && rightSensorValue == LOW) {
    forward();
  } else if (leftSensorValue == LOW && rightSensorValue == HIGH) {
    turnLeft();
  } else if (leftSensorValue == HIGH && rightSensorValue == LOW) {
    turnRight();
  } else {
    delay(1000);
    backward();
  }
}

void forward() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  digitalWrite(ena, 200);
  digitalWrite(enb, 200);
}

void backward() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  digitalWrite(ena, 200);
  digitalWrite(enb, 200);
}

void turnLeft() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  digitalWrite(ena, 200);
  digitalWrite(enb, 200);
}

void turnRight() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  digitalWrite(ena, 200);
  digitalWrite(enb, 200);
}

void stop() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);  
  digitalWrite(ena, 0);
  digitalWrite(enb, 0);
}

void avoidObstacle() {
  int sensorValue = digitalRead(8);
  if (sensorValue == HIGH) {
    forward();
    delay(1000);
  } else {
    backward();
  }
}

int obstacleDetection() {
  int sensorValue = digitalRead(8);
  if (sensorValue == HIGH) {
    return 1;
  } else {
    return 0;
  }
}
