//motor setting
#define R1 6
#define R2 5
#define L1 4
#define L2 3
#define FIX 0
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
  return !digitalRead(B1);
}

float getvolue(){
  float x = analogRead(RIR);
  if(x < 50){
    return 50;
  }else if(x > 750){
    return 750;
  }
  return x - MID;
}

void setup() {
  // put your setup code here, to run once:
  //pinMode(RIR, INPUT);
  pinMode(LIR, INPUT);
  pinMode(B1, INPUT);
  digitalWrite(B1, HIGH);
  Serial.begin(9600);
  Serial.println("begin");
  while(!button()){}
}

void loop() {
  // put your main code here, to run repeatedly:
  float error = getvolue();
  Serial.print("right:");
  Serial.println(error);
  delay(1000);
  float turn = error * MT;
  setmotor(SPEED+turn, SPEED-turn);
}



