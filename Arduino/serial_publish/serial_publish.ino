// Sketch to publish force or sensor data to serial to be read by pySerial in ROS
// or publish sensor value to ROS from Arduino using predefined calibration matrices

// #define ROS  //Publish forces to ROS as a publisher node
#define ReadSerial  //Read data from serial port

// #define FORCE  //Print calculated force data
#define SENSOR  //Print raw sensor data

// #define Test  //Print data to terminal
#define CAL  //Calibration with C++ and Nano 17

#define LEFT
// #define RIGHT

#include <BasicLinearAlgebra.h>
#include <ElementStorage.h>


#ifdef ROS
  #include <geometry_msgs/Wrench.h>
  #include "ros.h"
#endif

#ifdef Test
  bool zeroed_flag = false;
  BLA::Matrix<7> SL = { 0, 0, 0, 0, 0, 0, 1 };
  BLA::Matrix<7> SR = { 0, 0, 0, 0, 0, 0, 1 };

  BLA::Matrix<7> SLinit = { 0, 0, 0, 0, 0, 0, 1};
  BLA::Matrix<7> SRinit = { 0, 0, 0, 0, 0, 0, 1};

  BLA::Matrix<3> FL = { 0, 0, 0 };
  BLA::Matrix<3> FR = { 0, 0, 0 };

  BLA::Matrix<3, 7> leftCalMat = {1.2420, 0.0352, -0.0076, -1.2408, 0.3257, 0.1642, 0.0906, 
                                  0.2667, 0.9489, -0.4970, -0.2718, 0.2564, -1.3695, 0.0038, 
                                  3.7836, -2.3230, -1.5742, -4.1823, 2.0285, 2.2484, 0.0852};

  BLA::Matrix<3, 7> rightCalMat = {1.2420, 0.0352, -0.0076, -1.2408, 0.3257, 0.1642, 0.0906, 
                                  0.2667, 0.9489, -0.4970, -0.2718, 0.2564, -1.3695, 0.0038, 
                                  3.7836, -2.3230, -1.5742, -4.1823, 2.0285, 2.2484, 0.0852};


  const int pinRead[] = {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11};

  #ifdef ROS
  ros::NodeHandle nh;

  geometry_msgs::Wrench leftWrench;
  geometry_msgs::Wrench rightWrench;

  ros::Publisher leftWrench_pub("leftWrench", &leftWrench);
  ros::Publisher rightWrench_pub("rightWrench", &rightWrench);
  #endif
#endif

#ifdef CAL
  #define BAUD 256000
  #define delayTime 100

  #ifdef LEFT
    const int Read[] = {A0, A1, A2, A3, A4, A5};
  #endif
  #ifdef RIGHT
    const int Read[] = {A6, A7, A8, A9, A10, A11};
  #endif

  float V[] = {0, 0, 0, 0, 0, 0};
  bool receive_flag = true;
  bool send_flag = false;
  char char_flag = 'n';
#endif

void setup() {

#ifdef Test
  Serial.begin(57600);

  #ifdef ROS
    nh.initNode();
    nh.advertise(leftWrench_pub);
    nh.advertise(rightWrench_pub);
  #endif

    for (int i = 0; i < 12; i++) {
      if(i < 6){
        SLinit(i) = analogRead(pinRead[i]) * (3.3 / 1023.0);
      }
      else{
        SRinit(i-6) = analogRead(pinRead[i]) * (3.3 / 1023.0);
      }
    }


#endif

#ifdef CAL
    Serial.begin(BAUD);
    for (int i = 0; i < 6; i++){
      pinMode(Read[i], INPUT);
    }
#endif
}
void loop() {
#ifdef Test
  if (!zeroed_flag) {
    for (int i = 0; i < 12; i++) {
      if(i < 6){
        SLinit(i) = analogRead(pinRead[i]) * (3.3 / 1023.0);
      }
      else{
        SRinit(i-6) = analogRead(pinRead[i]) * (3.3 / 1023.0);
      }
    }
    zeroed_flag = true;
  }
  for (int i = 0; i < 12; i++) {
    if(i < 6){
      SL(i) = analogRead(pinRead[i]) * (3.3 / 1023.0);
    }
    else{
      SR(i-6) = analogRead(pinRead[i]) * (3.3 / 1023.0);
    }
  }
  FL = leftCalMat * (SL - SLinit);
  FR = rightCalMat * (SR - SRinit);
    
  #ifdef ReadSerial
    #ifdef SENSOR
      for (int i = 0; i < 6; i++) {
        Serial.print(SL(i));
        Serial.print(", ");
      }
      for (int i = 0; i < 6; i++) {
        Serial.print(SR(i));
        while (i < 5){
          Serial.print(", ");
          break;
        }
      }
      Serial.print('\n');
    #endif

    #ifdef FORCE
      for (int i = 0; i < 3; i++) {
        Serial.print(FL(i));
        Serial.print(", ");
      }
      for (int i = 0; i < 3; i++) {
        Serial.print(FR(i));
        while (i < 2){
          Serial.print(", ");
          break;
        }
      }
      Serial.print('\n');
    #endif
    delay(40);
  #endif

  #ifdef ROS
    leftWrench.force.x = FL(0);
    leftWrench.force.y = FL(1);
    leftWrench.force.z = FL(2);
    rightWrench.force.x = FR(0);
    rightWrench.force.y = FR(1);
    rightWrench.force.z = FR(2);

    leftWrench_pub.publish(&leftWrench);
    rightWrench_pub.publish(&rightWrench);

    nh.spinOnce();
  #endif
#endif

#ifdef CAL
  for (int i = 0; i < 6; i++){
    V[i] = analogRead(Read[i]) * (3.3 / 1023);
  }

  if (receive_flag && Serial.available() > 0) {
    char_flag = Serial.read();
    if (char_flag == 'x') {
      receive_flag = false;
    }
  }
  else if (!receive_flag) {
    for (int i = 0; i < 6; i++) {
      Serial.print(V[i], 2);
      if (i < 5) {
        Serial.print(",");
        }
      else Serial.println();
    }
    receive_flag = true;
  }
#endif
}