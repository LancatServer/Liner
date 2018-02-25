//liner.ino

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
#define Ki 0.4  //記憶比重（過去）
#define Kd 40
float H = 400;  //黑線
float L = 400;  //白線
float Integral;
float last_error;
int SPEED = 60;

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
  while (digitalRead(B1)) {}
  delay(500);
}

void loop() {
  float error = get_value();
  float turn = PID(error);
  setmotor(SPEED + turn, SPEED - turn);
  
  if(!digitalRead(B1)) {
    setmotor(0, 0);
    while (1) {}
  }
}

