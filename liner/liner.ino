//時間管理設定
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
int Rmotor; //紀錄馬達值
int Lmotor;
//Sensor right and left IR receiver
//感測器目前只用RIR（右邊的感測器）
#define RIR A1
//button （開始開關）
#define B1 45
//演算法參數
float KP = 0.4;  //轉彎比重（現在）
float Ki = 0.5;  //記憶比重（過去）
float Kd = 40;   //趨勢比重（未來）

#define range 50
float H = 400; //黑線
float L = 400; //白線
float remenber;
float last_error;
int SPEED = 60;

long score;
long num_of_time;

int time_of_out;

//取得尋線資料（黑白線的參數要改）
float getvalue() {
  float x = analogRead(RIR);
  float MID = (H + L) / 2;
  //讓回傳值介於0到100，設比例s
  float s = 100 / (H - L) * 2;
  if (abs(x-L) < range) {
    //覆寫最高值
    time_of_out ++;
    return -100;
  } else if (x > H) {
    return 100;
  } else {
    time_of_out = 0;
    return (x - MID) * s;
  }
}

//I
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
  float turn = KP * error + Ki * remenber + Kd * future;
  setmotor(SPEED + turn, SPEED - turn);
  last_error = error;
  timer.run();
  learn();
  if (!digitalRead(B1)) {
    setmotor(0, 0);
    while (1 == 1) {}
  }
}



