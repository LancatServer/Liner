void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

  boolean 左 = 數位輸入();
  boolean 右 = 數位輸入();
  if (左 && !右){
    向右修正;
  }else if (右 && !左){
    向左修正;
  }else{  
    前進;
  }

  全域變數 H = 過去紀錄的最高值;
  全域變數 L = 過去紀錄的最低值;
  
  float get_value(){
    float x = 類比輸入();
    if (x > H){
      H = x;    //覆寫最高值
      return 100;
    }else if(x < L){
      L = x;    //覆寫最低值
      return -100;
    }else{
      float MID = H與L的平均值
      //將x縮放到正負100之間
      return (x - MID) / (H - L) * 200
    }
  }

  常數 SPEED = 60;

  void loop(){
    float error = 取得正規劃誤差值();
    float turn = PID運算(error);
    設定馬達轉速(SPEED+turn, SPEED-turn);
  }

  常數 Kp = 0.4;

  float P運算(float error){
    return error * Kp;
  }

  全域變數 Integral;
  常數 Ki = 0.5;

  float I運算(float error){
    Integral *= 3/4;
    Integral += error;
    return Integral * Ki;
  }

  全域變數 last_error;
  常數 Kd = 40;

  float D運算(float error){
    float 差 = error - last_error;
    last_error = error;
    return 差 * Kd;
  }

  常數 range 30

  void loop(){
    float error = get_value();
    if(error > range){
      向右修正;
    }else if(error < -range){
      向左修正;
    }else{
      直走;
    }
  }
  
