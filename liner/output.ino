//擷取數字的某一位數
int cut(int num,int a){
  int b = num/pow(10,a);
  //num / 10**a
  return b%10;
}

void set_score() {
  float y = getvalue();
  score += abs(y);
  error_list[num_of_time][0] = millis() - startTime;
  error_list[num_of_time][1] = int(y);
  if (num_of_time >= 200){
    done = true;
  }else{
    done = false;
  }
  num_of_time ++;
}

void output_score(){  
  lcd.clear();
  lcd.setCursor(0,0);
  String output = String(millis());
  lcd.print("t:"+output);

  output = "e:" + String(score / num_of_time);
  lcd.setCursor(0,1);
  lcd.print(output);
}


