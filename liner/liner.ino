//motor setting 馬達設定（依據車子狀況）
#define R1 6
#define R2 5
#define L1 4
#define L2 3
#define FIX -5
//Sensor right and left IR receiver
//感測器目前只用RIR（右邊的感測器）
#define RIR A1
//button （開始開關）
#define B1 45
//演算法參數
float H = 400; //黑線
float L = 400; //
float MID = (H+L)/2;
#define range 100
float MT = 0.3;
int SPEED = 50;

//取得尋線資料（黑白線的參數要改）
float getvalue(){
  float x = analogRead(RIR);
  MID = (H+L)/2;
  //讓回傳值介於0到100，設比例s
  float s = 100 / (H-MID);
  if(x < L){
    //覆寫最高質
    L = x;
    return 0;
  }else if(x > H){
    H = x;
    return 0;
  }else{
    return (x-MID)*s;
  }
}

void setup() {
  pinMode(B1, INPUT);
  digitalWrite(B1, HIGH); //上拉電阻
  Serial.begin(9600);
  Serial.println("begin");
  while(digitalRead(B1)){}
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  float error = getvalue(); //讀到的數值
  float turn = MT*error;
  setmotor(SPEED+turn, SPEED-turn);
}

