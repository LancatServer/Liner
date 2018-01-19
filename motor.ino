void setmotor(int B, int A) {
  A += 0;
  B += 30;
  if (A > 0) {
    //analogWrite(rs, A);
    analogWrite(R1, A);
    digitalWrite(R2, LOW);
  } else if (A < 0) {
    //analogWrite(rs, abs(A));
    digitalWrite(R1, LOW);
    analogWrite(R2, A);
  } else {
    //analogWrite(rs, 0);
    digitalWrite(R1, LOW);
    digitalWrite(R2, LOW);
  }
  if (B > 0) {
    //analogWrite(ls, B);
    analogWrite(L1, B);
    digitalWrite(L2, LOW);
  } else if (B < 0) {
    //analogWrite(ls, abs(B));
    digitalWrite(L1, LOW);
    analogWrite(L2, B);
  } else {
    //analogWrite(ls, 0);
    digitalWrite(L1, LOW);
    digitalWrite(L2, LOW);
  }
}
void easymotor(int A,int B,int t){
  setmotor(A,B);
  delay(t);
}


