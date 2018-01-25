//motor setting 馬達設定（依據車子狀況）
#define R1 6
#define R2 5
#define L1 4
#define L2 3
#define FIX 0
//Sensor right and left IR receiver
//感測器目前只用RIR（右邊的感測器）
#define RIR A1
#define LIR 51
//button （開始開關）
#define B1 45
//演算法參數
#define H 750 //黑線
#define L 50  //白線
#define MID (H+L)/2
#define MT 0.2;
#define SPEED 70

//取得尋線資料（黑白線的參數要改）
float getvolue(){
  float x = analogRead(RIR);
  if(x < L){
    return 0;
  }else if(x > H){
    return 0;
  }else{
    return x - MID;
  }
}

void setup() {
  pinMode(LIR, INPUT);
  pinMode(B1, INPUT);
  digitalWrite(B1, HIGH); //上拉電阻
  Serial.begin(9600);
  Serial.println("begin");
  while(digitalRead(B1)){}
}

void loop() {
  // put your main code here, to run repeatedly:
  float error = getvolue(); //讀到的數值
  Serial.print("right:");
  Serial.println(error);
  float turn = error * MT;
  setmotor(SPEED+turn, SPEED-turn); // 改成自己的
}

