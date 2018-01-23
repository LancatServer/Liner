//motor setting
#define R1 6
#define R2 5
#define L1 4
#define L2 3
#define FIX 0

#define SPEED 80
//Sensor right and left IR receiver
#define RIR 50
#define LIR 51
//button
#define B1 45
boolean r;
boolean l;

boolean button(){
  return !digitalRead(B1);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(RIR, INPUT);
  pinMode(LIR, INPUT);
  pinMode(B1, INPUT);
  Serial.begin(9600);
  Serial.println("begin");
  while(!button()){}
}

void loop() {
  // put your main code here, to run repeatedly:
  r = digitalRead(RIR);
  l = digitalRead(LIR);
  Serial.println(r, l);
  if(r && !l){
    setmotor(-1*SPEED, SPEED);
  }else if(!r && l){
    setmotor(SPEED, -1*SPEED);
  }else{
    setmotor(SPEED, SPEED);
  }
}



