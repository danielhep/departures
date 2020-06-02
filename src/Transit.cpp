#include "Transit.h"
#include "colors.h"

void Transit::displayRoute(String route, uint8_t *times, status_t *status, uint8_t row) {
  char buffer[20];
  uint8_t timewidth[TIMES_TO_SHOW];
  uint8_t spacewidth = u8g2.getUTF8Width(" ");

  u8g2.setCursor(0, row); // start writing at this position
  u8g2.print(route);

  String str = "";
  uint8_t prevWidth = 0;
  for (int i = 0; i < TIMES_TO_SHOW; i++)
  {
    if(times[i] != 255) {
      str += times[i];
      str += " ";
      str.toCharArray(buffer, 20);
      uint8_t newWidth = u8g2.getUTF8Width(buffer);
      timewidth[i] = newWidth - prevWidth - spacewidth;
      prevWidth = newWidth;
    }
  }
  u8g2.setCursor(64 - prevWidth, row);
  u8g2.print(str);
  // print boxes
  for (int i = 0; i < TIMES_TO_SHOW; i++) {
    if(times[i] != 255) {
      uint8_t tl_x = 64 - prevWidth -1;
      prevWidth -= timewidth[i] + spacewidth;
      uint8_t tl_y = row - u8g2.getFontAscent() - 1;
      uint16_t color;
      switch (status[i])
      {
      case ON_TIME:
        color = colOnTime;
        break;
      case LATE:
        color = colLate;
        break;
      case EARLY:
        color = colEarly;
        break;
      default:
        break;
      }
      display.drawRect(tl_x, tl_y, timewidth[i] + 1, u8g2.getFontAscent() + 2, color);
    }
  }
}