//宣告Kp量
#define Kp 0.4

//in loop():
float error = getvalue();
float turn = Kp * error;
