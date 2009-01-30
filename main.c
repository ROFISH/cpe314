#include <AT89x51.h>

void delay_1_second();
void delay_max();

void main() {
  //stuff
top:
  P2_0 = 0;
  delay_1_second();
  P2_0 = 1;
  delay_1_second();
  goto top;
}

void delay_1_second() {
  int i;
  for (i = 0; i < 28; i++) { delay_max(); }
}

void delay_max() {
  long i;
  for (i = 0; i < 1000; i++) {}
}
