#include <SimpleTimer.h>
SimpleTimer timer;
//LCD 設定
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#include <SPI.h>
#include <SD.h>

File myFile;

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
//motor setting 馬達設定（依據車子狀況）
#define R1 6
#define R2 5
#define L1 4
#define L2 3
#define FIX -5
int Rmotor;
int Lmotor;
//Sensor right and left IR receiver
//感測器目前只用RIR（右邊的感測器）
#define RIR A1
//button （開始開關）
#define B1 45
#define LED 24
//演算法參數
#define range 100
#define MT 0.4  //轉彎比重（現在）
#define MR 0.5  //記憶比重（過去）
#define MF 400
float H = 400; //黑線
float L = 400; //
float MID;
float remenber;
float last_error;
int SPEED = 60;

unsigned long score;
unsigned long num_of_time;
unsigned int startTime;
unsigned int Time;

int error_list[200][2];
boolean done = false;

//取得尋線資料（黑白線的參數要改）
float getvalue() {
  float x = analogRead(RIR);
  MID = (H + L) / 2;
  //讓回傳值介於0到100，設比例s
  float s = 100 / (H - MID);
  if (x < L) {
    //覆寫最高值
    L = x;
    return 0;
  } else if (x > H) {
    H = x;
    return 0;
  } else {
    float y = (x - MID) * s;
    return y;
  }
}

void set_remenber(float x) {
  remenber *= 3 / 4;
  remenber += x;
}

void setup() {
  pinMode(B1, INPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(B1, HIGH); //上拉電阻
  Serial.begin(9600);
  Serial.println("begin");
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Welcome");
  //timer.setInterval(1000, output_score);
  timer.setInterval(50, set_score);
  if(!SD.begin(53)){
    digitalWrite(LED, HIGH);
  }
  myFile = SD.open("data.txt", FILE_WRITE);
  while (digitalRead(B1)) {}
  delay(500);
  startTime = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  float error = getvalue(); //讀到的數值
  set_remenber(error);
  float future = error - last_error;
  float turn = MT * error + MR * remenber + MF * future;
  setmotor(SPEED + turn, SPEED - turn);
  last_error = error;
  if(millis() - Time > 50){
    Time = millis();
    done = set_score(Time - startTime);
  }
  if (done || !digitalRead(B1)) {
    setmotor(0, 0);
    myFile.println(String("MT: ") + MT + "\tMR: " + MR + "\tMF: " + MF);
    for(int i=0;i<200;i++){
      String line = String("")+error_list[i][0]+"\t"+error_list[i][1];
      myFile.println(line);
      //Serial.println(line);
    }
    myFile.close();
    digitalWrite(LED, HIGH);
    delay(3000);
    digitalWrite(LED, LOW);
    lcd.noBacklight();
    while (1 == 1) {}
  }
}



