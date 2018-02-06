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
  String output = "motor:" + String(Lmotor) + ", " + String(Rmotor);
  lcd.print("score:"+output);

  output = "angle:" + String(angle());
  lcd.setCursor(0,1);
  lcd.print(output);

  float error = getvalue();
  output += ", motor:" + String(Lmotor) + ", " + String(Rmotor);
  output += ", error:" + String(error);
  myfile = SD.open("file/text2.txt", FILE_WRITE);
  myfile.println(output);
  myfile.close();
  
}


