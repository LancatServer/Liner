//擷取數字的某一位數
int cut(int num,int a){
  int b = num/pow(10,a);
  //num / 10**a
  return b%10;
}

/*void set_score() {
  float y = getvalue();
  score += abs(y);
  num_of_time ++;
}*/

void output_score(){
  String output;
  lcd.clear();
  lcd.setCursor(0,0);
  output = String(millis());
  lcd.print("t:"+output);

  output = "e:" + String(score / num_of_time);
  lcd.setCursor(8,1);
  lcd.print(output);
}


