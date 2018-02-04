
//馬達控制函數
void setmotor(int B, int A) {
  //如果要停車，忽略最高與最低限制
  if(A==0 && B==0){
    digitalWrite(R1, LOW);
    digitalWrite(R2, LOW);
    digitalWrite(L1, LOW);
    digitalWrite(L2, LOW);
  }else{
    //將兩個馬達的值控制在30到170
    A = max(A, 30);
    B = max(B, 30);
    A = min(A, 170);
    B = min(B, 170);
    //紀錄馬達值，供其他函數運用
    Rmotor = A;
    Lmotor = B;
    //控制馬達
    if (A < 0) {
      A += FIX;   //加上修正值
      analogWrite(R1, A);
      digitalWrite(R2, LOW);
    } else if (A > 0) {
      A += FIX;
      digitalWrite(R1, LOW);
      analogWrite(R2, A);
    } else {
      digitalWrite(R1, LOW);
      digitalWrite(R2, LOW);
    }
    if (B > 0) {
      B -= FIX;
      analogWrite(L1, B);
      digitalWrite(L2, LOW);
    } else if (B < 0) {
      B -= FIX;
      digitalWrite(L1, LOW);
      analogWrite(L2, B);
    } else {
      digitalWrite(L1, LOW);
      digitalWrite(L2, LOW);
    }
  }
}

