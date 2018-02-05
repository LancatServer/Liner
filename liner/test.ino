void test(){
  setmotor(150,150);
  delay(1000);
  setmotor(0, 0);
}

void test_lcd(){
  for(int i = 0; i < 3; i++){
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250);
  }
  lcd.backlight();

  //輸出文字
  lcd.setCursor(0, 0);
  lcd.print("Hello World!");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("Lancat Server");
  delay(8000);

  lcd.clear();
  lcd.noBacklight();
}



