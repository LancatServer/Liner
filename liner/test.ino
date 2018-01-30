void test(){
  setmotor(80,80);
  delay(1000);
  for(int i=10;i>=0;i--){
    setmotor(20+i, 20+i);
    set_number(i);
    delay(1000);
  }
  setmotor(0,0);
}

