void learn(){
  //學習黑線與白線值
  if(millis < 5000){
    float x = analogRead(RIR);
    if(x > H){
      H = x;
    }else if(x < L){
      L = x;
    }
  }else if(time_of_out > 0){
    path *= 1;
    time_of_out = 0;
    lcd.setCursor(0,1);
    lcd.print("Change");
  }
}

