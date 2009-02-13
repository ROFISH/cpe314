#include <AT89x51.h>

typedef unsigned char u8;

void delay_1_second();
void delay_max();
void init_serial();
void send_serial(u8 input);

static const u8 displayText[2][16] = {
  "THIS IS A TEST1 ",
  "THIS IS A TEST2 "
};

void main() {
  int i;
  init_serial();
  // send init code for serial display
  send_serial(0x1B);
  send_serial(0x40);

top:
  //reset cursor to top
  send_serial(0x0C);
  send_serial(0x0B);
  // send text 1
  for (i = 0; i < 16; i++) {
    send_serial(displayText[0][i]);
  }
  delay_1_second();

  //reset cursor to top
  send_serial(0x0C);
  send_serial(0x0B);
  //send text 2
  for (i = 0; i < 16; i++) {
    send_serial(displayText[1][i]);
  }
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

void init_serial() {
  PCON = 0x80;
  TMOD = 0x20;
  SCON = 0x40;
  TH1 = 0xFD;
  TF1 = 0;
  TR1 = 1;
  TI = 1;
  //ET = 0;
  //TS1 = 0;
  EA = 0;
}

void send_serial(u8 input) {
  TI = 0;
  SBUF = input;
  while (TI == 0);
}
