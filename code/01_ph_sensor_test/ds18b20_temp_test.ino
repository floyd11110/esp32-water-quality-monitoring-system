/* search sa library ang onewire and  DallasTemperature  install mo lang

temp sensor                         driver module                   esp32
red                                    vcc                           3.3v
black                                  gnd                           gnd
yellow                                 data                          gpio4

 */

#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 4   // DS18B20 data pin connected to GPIO4

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(115200);
  sensors.begin();

  Serial.println("DS18B20 Temperature Sensor Test");
}

void loop() {
  sensors.requestTemperatures();

  float tempC = sensors.getTempCByIndex(0);
  float tempF = tempC * 9.0 / 5.0 + 32.0;

  if (tempC == DEVICE_DISCONNECTED_C) {
    Serial.println("Error: DS18B20 not detected!");
  } else {
    Serial.print("Temperature: ");
    Serial.print(tempC, 2);
    Serial.print(" °C | ");
    Serial.print(tempF, 2);
    Serial.println(" °F");
  }

  delay(1000);
}
