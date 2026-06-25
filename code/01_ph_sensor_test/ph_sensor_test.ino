#define PH_PIN 34

// Your reference voltage for normal water / neutral reference
float neutralVoltage = 2.40;   // pH 7 reference

// Estimated voltage change per pH level
// Adjust this later after calibration with pH 4 and pH 10 buffer
float slope = 0.18;

// Noise tolerance around normal
float normalTolerance = 0.10;  // +/- 0.10V around 2.40V

void setup() {
  Serial.begin(115200);

  analogReadResolution(12);       // ESP32 ADC: 0-4095
  analogSetAttenuation(ADC_11db); // ADC range around 0-3.3V
}

void loop() {
  const int samples = 100;
  long sum = 0;

  int minRaw = 4095;
  int maxRaw = 0;

  for (int i = 0; i < samples; i++) {
    int raw = analogRead(PH_PIN);
    sum += raw;

    if (raw < minRaw) minRaw = raw;
    if (raw > maxRaw) maxRaw = raw;

    delay(10);
  }

  float rawAvg = sum / (float)samples;
  float voltage = rawAvg * (3.3 / 4095.0);

  /*
import ang pag-check ng neutral a naka-base sa calibration liquid mo at sa voltage na output nya
pwede mo i-adjust ang reference voltage gamit ang maliit na potentionmeter
 ph sensor                esp32
 v+                         3.3v
 G                          GND
 PO                         GPIO34
  */
  float pH = 7.0 - ((voltage - neutralVoltage) / slope);

  String status;

  if (voltage > neutralVoltage + normalTolerance) {
    status = "ACIDIC";
  }
  else if (voltage < neutralVoltage - normalTolerance) {
    status = "BASIC / ALKALINE";
  }
  else {
    status = "NORMAL / NEUTRAL";
  }

  Serial.print("Raw Avg: ");
  Serial.print(rawAvg, 1);

  Serial.print(" | Voltage: ");
  Serial.print(voltage, 3);
  Serial.print(" V");

  Serial.print(" | Estimated pH: ");
  Serial.print(pH, 2);

  Serial.print(" | Status: ");
  Serial.print(status);

  Serial.print(" | Min: ");
  Serial.print(minRaw);

  Serial.print(" | Max: ");
  Serial.print(maxRaw);

  if (maxRaw >= 4090) {
    Serial.print(" | WARNING: ADC TOO HIGH");
  }

  Serial.println();

  delay(1000);
}
