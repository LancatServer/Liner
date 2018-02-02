#include <SimpleTimer.h>
SimpleTimer timer;
//LCD 設定
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

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
//演算法參數
#define range 100
#define MT 0.4  //轉彎比重（現在）
#define MR 0.5  //記憶比重（過去）
#define MF 20
float H = 400; //黑線
float L = 400; //
float MID;
float remenber;
float last_error;
int SPEED = 60;

long score;
long num_of_time;

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

void set_score() {
  float y = getvalue();
  score += abs(y);
  num_of_time ++;
}

void setup() {
  pinMode(B1, INPUT);
  digitalWrite(B1, HIGH); //上拉電阻
  Serial.begin(9600);
  Serial.println("begin");
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Welcome");
  timer.setInterval(500, output_score);
  timer.setInterval(10, set_score);
  while (digitalRead(B1)) {}
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  float error = getvalue(); //讀到的數值
  set_remenber(error);
  float future = error - last_error;
  float turn = MT * error + MR * remenber + MF * future;
  setmotor(SPEED + turn, SPEED - turn);
  last_error = error;
  timer.run();
  if (!digitalRead(B1)) {
    setmotor(0, 0);
    while (1 == 1) {}
  }
}



