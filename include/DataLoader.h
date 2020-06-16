#ifndef DATALOADER_H
#define DATALOADER_H

#include "HTTPClient.h"
#include "ArduinoJson.h"

typedef enum
{
    ON_TIME,
    EARLY,
    LATE,
    NO_LIVE,
    NO_BUS
} status_t;
 
class DataLoader {
    public: 
        DataLoader() {};
        void loadData(String stop, String routeId, uint16_t *times, status_t *status, uint8_t qty);

    private:
        HTTPClient http;
        StaticJsonDocument<1024> doc;
};

#endif