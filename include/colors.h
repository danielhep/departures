#ifndef COLORS_H
#define COLORS_H
#include "Arduino.h"

static inline uint16_t color565(uint8_t r, uint8_t g, uint8_t b) {
  return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
}
extern uint16_t myRED;
extern uint16_t myGREEN;
extern uint16_t myBLUE;
extern uint16_t myWHITE;
extern uint16_t myYELLOW;
extern uint16_t myCYAN;
extern uint16_t myMAGENTA;
extern uint16_t myBLACK;
extern uint16_t myORANGE;
extern uint16_t colOnTime;
extern uint16_t colLate;
extern uint16_t colEarly;

#endif