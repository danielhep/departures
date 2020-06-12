#ifndef DISPLAY_H
#define DISPLAY_H
#include <PxMatrix.h>
#include <U8g2_for_Adafruit_GFX.h>
#include "DataLoader.h"

#define P_LAT 22
#define P_A 19
#define P_B 23
#define P_C 18
#define P_D 5
#define P_E 15
#define P_OE 0

#define TIMES_TO_SHOW 3

class Transit {
    public:
        Transit(PxMATRIX &display, U8G2_FOR_ADAFRUIT_GFX &u8g2) : display(display), u8g2(u8g2){};
        void loadAndDisplayRoute(String route, String stop, uint8_t row);
        void displayRoute(String route, uint16_t *times, status_t *status, uint8_t row);
        PxMATRIX &display;
        U8G2_FOR_ADAFRUIT_GFX &u8g2;
    private:
        DataLoader loader;
};

#endif