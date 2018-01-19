#define R1 6
#define R2 5
#define L1 4
#define L2 3
#define IR 22
int x;

void setup() {
  // put your setup code here, to run once:
  pinMode(IR,INPUT);
  Serial.begin(9600);
  Serial.println("begin");
}

void loop() {
  // put your main code here, to run repeatedly:
  x = digitalRead(IR);
  Serial.println(x);
  delay(500);
}


