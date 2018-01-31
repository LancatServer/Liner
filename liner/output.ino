//數字表
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

//七段顯示器輸出數字
/*void set_number(int num){
  digitalWrite(ST_CP,LOW);
  for (int i = 0;i<=7;i++){
    //設定內容
    digitalWrite(DS, number[num][7-i]);
    //推入一個內容
    digitalWrite(SH_CP, HIGH);
    digitalWrite(SH_CP, LOW);
    }
  digitalWrite(ST_CP,HIGH);
  //將所有資料推送到外部
}*/

//擷取數字的某一位數
int cut(int num,int a){
  int b = num/pow(10,a);
  //num / 10**a
  return b%10;
}

void output_score(){
  lcd.clear();
  lcd.setCursor(0,0);
  String output = String(score/num_of_time);
  lcd.print("score:"+output);
}


