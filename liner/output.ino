

int number[][8] = {
  {1,1,1,1,1,1,0,0}, //0
  {0,1,1,0,0,0,0,0}, //1
  {1,1,0,1,1,0,1,0}, //2
  {1,1,1,1,0,0,1,0}, //3
  {0,1,1,0,0,1,1,0}, //4
  {1,0,1,1,0,1,1,0}, //5
  {1,0,1,1,1,1,1,0}, //6
  {1,1,1,0,0,0,0,0}, //7
  {1,1,1,1,1,1,1,0}, //8
  {1,1,1,1,1,1,0,1}, //9
  {0,0,0,0,0,0,0,0}, //none
};

void set_number(int num){
  digitalWrite(ST_CP,LOW);
  for (int i = 0;i<=7;i++){
    digitalWrite(DS, number[num][7-i]);
    digitalWrite(SH_CP, HIGH);
    digitalWrite(SH_CP, LOW);
    }
  digitalWrite(ST_CP,HIGH);
}

int cut(int num,int a){
  int b = num/pow(10,a);
  return b%10;
}
