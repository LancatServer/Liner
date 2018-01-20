void setmotor(int B, int A) {
  if (A > 0) {
    A += FIX;
    analogWrite(R1, A);
    digitalWrite(R2, LOW);
  } else if (A < 0) {
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
void easymotor(int A,int B,int t){
  setmotor(A,B);
  delay(t);
  setmotor(0,0);
}


