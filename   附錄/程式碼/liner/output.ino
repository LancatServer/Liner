//擷取數字的某一位數
int cut(int num,int a){
  int b = num/pow(10,a);
  //num / 10**a
  return b%10;
}

void set_score() {
  float y = getvalue();
  score += abs(y);
  distance += (Lmotor + Rmotor);
  num_of_time ++;
}

void output_score(){
  float ave = distance / score / 2;
  
  lcd.clear();
  lcd.setCursor(0,0);
  String output = String(distance * 100 / score);
  lcd.print("s:"+output + "%");

  lcd.setCursor(0,1);
  output = String(distance / num_of_time);
  lcd.print("d:"+output);

  output = "e:" + String(score / num_of_time);
  lcd.setCursor(8,1);
  lcd.print(output);
}


