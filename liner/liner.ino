//liner.ino

//SD模組
#include <SPI.h>
#include <SD.h>
File myFile;

//motor setting 馬達設定（依據車子狀況）
#define R1 6
#define R2 5
#define L1 4
#define L2 3
#define FIX -5

#define RIR A1  //sensor
#define B1 45   //開關
#define LED 24
//演算法參數
#define Kp 0.4  //轉彎比重（現在）
#define Ki 0.5  //記憶比重（過去）
#define Kd 40
float H = 400;  //黑線
float L = 400;  //白線
float Integral;
float last_error;
int SPEED = 60;

unsigned int num_of_time;
unsigned int startTime;
unsigned int Time;

#define len 200
int error_list[len][2];
boolean done = false;

float get_value() {
  float x = analogRead(RIR);
  float MID = (H + L) / 2;
  if (x < L) {
    //覆寫最高值
    L = x;
    return -100;
  } else if (x > H) {
    H = x;
    return 100;
  } else {
    return (x - MID) / (H - L) * 200;
  }
}

boolean set_score(int error, int t) {
  error_list[num_of_time][0] = t;
  error_list[num_of_time][1] = error;
  if (num_of_time > len){
    return true;
  }else{
    num_of_time ++;
    return false;
  }
}

float PID(float error) {
  float p = error * Kp;
  Integral *= 3 / 4;
  Integral += error;
  float i = Integral * Ki;
  float d = (error - last_error) * Kd;
  last_error = error;
  return p + i + d;
}

void setup() {
  pinMode(B1, INPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(B1, HIGH); //上拉電阻
  if(!SD.begin(53)){
    digitalWrite(LED, HIGH);
  }
  myFile = SD.open("data.txt", FILE_WRITE);
  while (digitalRead(B1)) {}
  while (!digitalRead(B1)) {}
  delay(500);
  startTime = millis();
}

void loop() {
  float error = get_value();
  float turn = PID(error);
  setmotor(SPEED + turn, SPEED - turn);
  
  if(millis() - Time > 50){
    Time = millis();
    done = set_score(error, Time - startTime);
  }else if(done || !digitalRead(B1)) {
    setmotor(0, 0);
    digitalWrite(LED, HIGH);
    myFile.println(String("Kp: ") + Kp + "\tKi: " + Ki + "\tKd: " + Kd);
    for(int i=0;i<len;i++){
      String line = String("")+error_list[i][0]+"\t"+error_list[i][1];
      myFile.println(line);
    }
    myFile.close();
    delay(1000);
    digitalWrite(LED, LOW);
    while (1) {}
  }
}

