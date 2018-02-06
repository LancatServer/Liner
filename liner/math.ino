float angle(){
  float t = 0.5;
  cpu_time = 0;
  float pi = 3.1415926535897;
  float x = analogRead(RIR);
  float a = -12000 * t * (2*x - H - L) * Kp;
  float b = 11 * pi * (H-L);
  return a/b;
}

