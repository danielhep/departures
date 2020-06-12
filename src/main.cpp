
// This is how many color levels the display shows - the more the slower the update
#define PxMATRIX_COLOR_DEPTH 4

// Defines the buffer height / the maximum height of the matrix
//#define PxMATRIX_MAX_HEIGHT 64

// Defines the buffer width / the maximum width of the matrix
//#define PxMATRIX_MAX_WIDTH 64

// Defines how long we display things by default
//#define PxMATRIX_DEFAULT_SHOWTIME 30

// Defines the speed of the SPI bus (reducing this may help if you experience noisy images)
#define PxMATRIX_SPI_FREQUENCY 17000000

// Creates a second buffer for backround drawing (doubles the required RAM)
// #define PxMATRIX_double_buffer true

#define DISP_WIDTH 64
#define DISP_HEIGHT 32

#include <Wire.h>

//needed for library
#include <DNSServer.h>
#include <WiFiManager.h>         
#include "Transit.h"
#include "DataLoader.h"
#include "colors.h"

PxMATRIX display(64,32,P_LAT, P_OE,P_A,P_B,P_C,P_D);
U8G2_FOR_ADAFRUIT_GFX u8g2;

Transit transitScreen(display, u8g2);
DataLoader loader;

// Pins for LED MATRIX
#ifdef ESP32

hw_timer_t * timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

#endif


// This defines the 'on' time of the display is us. The larger this number,
// the brighter the display. If too large the ESP will crash
uint8_t display_draw_time=70; //30-70 is usually fine

#ifdef ESP8266
// ISR for display refresh
void display_updater()
{
  display.display(display_draw_time);
}
#endif

#ifdef ESP32
void IRAM_ATTR display_updater(){
  // Increment the counter and set the time of ISR
  portENTER_CRITICAL_ISR(&timerMux);
  display.display(display_draw_time);
  portEXIT_CRITICAL_ISR(&timerMux);
}
#endif


void display_update_enable(bool is_enable)
{
  if (is_enable)
  {
    timer = timerBegin(0, 80, true);
    timerAttachInterrupt(timer, &display_updater, true);
    timerAlarmWrite(timer, 4000, true);
    timerAlarmEnable(timer);
  }
  else
  {
    timerDetachInterrupt(timer);
    timerAlarmDisable(timer);
  }
}

static void configModeCallback (WiFiManager *myWiFiManager) {
  Serial.println("Entered config mode");
  Serial.println(WiFi.softAPIP());

  Serial.println(myWiFiManager->getConfigPortalSSID());
}

void setup() {
  Serial.begin(9600);
  delay(1000);
  WiFiManager wifiManager;

  wifiManager.setAPCallback(configModeCallback);
  wifiManager.autoConnect("transit setup");

  // Define your display layout here, e.g. 1/8 step, and optional SPI pins begin(row_pattern, CLK, MOSI, MISO, SS)
  display.begin(16);
  display.setBrightness(255);
  u8g2.begin(display);
  display.setFastUpdate(true);

  display.clearDisplay();
  u8g2.setFontMode(1);                 // use u8g2 transparent mode (this is default)
  u8g2.setFontDirection(0);            // left to right (this is default)
  u8g2.setForegroundColor(myORANGE);   // apply Adafruit GFX color
  u8g2.setFont(u8g2_font_baby_tf);     // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
  u8g2.setCursor(0,5);                 // start writing at this position
  u8g2.print(F("Inbound"));
  display_update_enable(true);


  u8g2.setForegroundColor(myWHITE);   // apply Adafruit GFX color
  transitScreen.loadAndDisplayRoute("E Line", "asd", 11);
  // uint8_t times2 [] = {21, 29, 46};
  // status_t status2 [] = {LATE, ON_TIME, ON_TIME};
  // transitScreen.displayRoute(F("62"), times2, status2, 18);
  // uint8_t times3 [] = {2, 12, 15};
  // status_t status3 [] = {EARLY, EARLY, ON_TIME};
  // transitScreen.displayRoute(F("E Line"), times3, status3, 25);
  // uint8_t times4 [] = {99, 11, 100};
  // status_t status4 [] = {LATE, EARLY, ON_TIME};
  // transitScreen.displayRoute(F("44"), times4, status4, 32);
}

void loop() {
  delay(15000);
  transitScreen.loadAndDisplayRoute("E Line", "asd", 11);
}
