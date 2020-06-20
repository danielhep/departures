#include "Transit.h"
#include "DataLoader.h"
void DataLoader::loadData(String stop, String routeId, uint16_t *times, status_t *status, uint8_t qty) {
    String str = String("http://headways-api.herokuapp.com/rt?stop=" + stop + "&route=" + routeId);
    http.begin(str);
    uint8_t code = http.GET();
    if (code != 200)
    {
        Serial.println("Error on HTTP: " + String(code));
    }
    else
    {
        char buffer[2048];
        http.getString().toCharArray(buffer, 2048);
        DeserializationError err = deserializeJson(doc, buffer);
        if(err) {
            Serial.print(F("deserializeJson() failed with code "));
            Serial.println(err.c_str());
        } else {
            JsonArray arr = doc.as<JsonArray>();
            for (int i = 0; i < arr.size(); i++) {
                if(i < qty) {
                    times[i] = (int16_t)doc[i]["predictedDepartureTime"];
                    int8_t deviation = doc[i]["deviation"];
                    if (!doc[i]["predicted"])
                        status[i] = NO_LIVE;
                    else if (deviation < 0)
                        status[i] = EARLY;
                    else if(deviation > 0 & deviation < 3)
                        status[i] = ON_TIME;
                    else if(deviation > 3)
                        status[i] = LATE;
                }
            }
        }
    }
}