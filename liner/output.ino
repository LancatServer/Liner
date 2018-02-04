//擷取數字的某一位數
int cut(int num,int a){
  int b = num/pow(10,a);
  //num / 10**a
  return b%10;
}

void output_score(){
  lcd.clear();
  lcd.setCursor(0,0);
  float ave = score / num_of_time;
  String output = String(ave);
  lcd.print("score:"+output);

}


