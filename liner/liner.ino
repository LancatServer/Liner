//motor setting
#define R1 6
#define R2 5
#define L1 4
#define L2 3
#define FIX -20
//Sensor
#define IR 22
int x;

void setup() {
  // put your setup code here, to run once:
  pinMode(IR, INPUT);
  Serial.begin(9600);
  Serial.println("begin");
  delay(5000);
  for (byte i = 0; i < 4; i++) {
    easymotor(200, 200, 1000);
    easymotor(100, -100, 1000);
  }
  setmotor(0, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  x = digitalRead(IR);
  Serial.println(x);
  delay(500);
}


