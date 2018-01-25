#include <Servo.h>
//motor setting
#define R1 6
#define R2 5
#define L1 4
#define L2 3
#define FIX 0
#define SERMID 90
Servo Rservo;
Servo Lservo;
//Sensor right and left IR receiver
#define RIR A1
#define LIR 51
//button
#define B1 45
//run info
#define MID 400
const float MT = 0.2;
#define SPEED 70

boolean button(){
  return digitalRead(B1);
}

float getvolue(){
  float x = analogRead(RIR);
  if(x < 50){
    return MID;
  }else if(x > 750){
    return MID;
  }else{
    return x - MID;
  }
}

void setup() {
  // put your setup code here, to run once:
  //pinMode(RIR, INPUT);
  pinMode(LIR, INPUT);
  pinMode(B1, INPUT);
  digitalWrite(B1, HIGH);
  Rservo.attach(10);
  Lservo.attach(9);
  Serial.begin(9600);
  Serial.println("begin");
  while(button()){}
}

void loop() {
  // put your main code here, to run repeatedly:
  float error = getvolue();
  Serial.print("right:");
  Serial.println(error);
  float turn = error * MT;
  setservo(SPEED+turn, SPEED-turn);
}



