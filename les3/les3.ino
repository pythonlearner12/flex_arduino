// JSON libraries
#include <ArduinoJson.h>

JsonDocument doc;
char jsonOut[128];

// LDR pin
const int ldrPin = A0;

void setup() {
  
  pinMode(D6, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D3, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  CreateJSON();  
}

void CreateJSON() {
  // Read LDR value
  int ldrValue = analogRead(ldrPin);


  doc["key"] = "value";
  doc["key2"] = "value2";
  doc["ldrValue"] = ldrValue;

  if (ldrValue < 10) {

    serializeJson(doc, jsonOut);
    Serial.println(jsonOut);
    digitalWrite(D3, HIGH);
    digitalWrite(D5, HIGH);
    digitalWrite(D6, HIGH);
  } else {
    Serial.println("LDR value is above 500.");
    
    digitalWrite(D3, LOW);
    digitalWrite(D5, LOW);
    digitalWrite(D6, LOW);
  }
}
