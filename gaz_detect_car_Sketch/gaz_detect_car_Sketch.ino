#include <MQ2.h> // Gas sensor uchun kutubhonani yuklash
#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);


int gasSensorPin = A0;
// MQ2 mq2(A1);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // gas sensor
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);


  // mq2.begin();
}

void loop() {
//   // put your main code here, to run repeatedly:
// if(Serial.available())
// {
// String control_value = Serial.readString();
// Serial.println(control_value);
// if(control_value == 'w'){
// motor1.run(FORWARD);
// }
// }
// float gasValue = mq2.readCO();
// String val = String(gasValue);
// Serial.println(gasValue);
// delay(1000);

int gasValue = analogRead(gasSensorPin);

  // Print gas sensor value
  Serial.print("Gaz Sensor qiymati: ");
  Serial.println(gasValue);

  // // Check for commands from the Android app
  // if (Serial.available() > 0) {
  //   char command = Serial.read();
while(Serial.available()){
if (Serial.available() > 0) {
    char command = Serial.read();

    // Perform the appropriate action based on the command received
    switch (command) {
      case 'w':
        moveForward();
        break;
      case 'x':
        moveBackward();
        break;
      case 'a':
        turnLeft();
        break;
      case 'd':
        turnRight();
        break;
      case 's':
        stopCar();
        break;
    }
  }}
// else {
// stopCar();
// }
}


void moveForward() {
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void moveBackward() {
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void turnLeft() {
  motor3.run(BACKWARD); 
  motor4.run(FORWARD);
}

void turnRight() {
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}

void stopCar() {
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
