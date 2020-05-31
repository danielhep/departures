#ifndef DISPLAY_H
#define DISPLAY_H
#include <PxMatrix.h>
#include <U8g2_for_Adafruit_GFX.h>

#define P_LAT 22
#define P_A 19
#define P_B 23
#define P_C 18
#define P_D 5
#define P_E 15
#define P_OE 0

#define TIMES_TO_SHOW 3

typedef enum
{
    ON_TIME,
    EARLY,
    LATE,
    NO_LIVE
} status_t;

// PxMATRIX display(64,32,P_LAT, P_OE,P_A,P_B,P_C,P_D);

// U8G2_FOR_ADAFRUIT_GFX u8g2;
class Transit {
    public:
        Transit(PxMATRIX &display, U8G2_FOR_ADAFRUIT_GFX &u8g2) : display(display), u8g2(u8g2){};
        void displayRoute(String route, uint8_t *times, status_t *status, uint8_t row);
        PxMATRIX &display;
        U8G2_FOR_ADAFRUIT_GFX &u8g2;
};

#endif