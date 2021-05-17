#include "client.h"

TaskHandle_t Task1;
HTTPClient http;
StaticJsonDocument<200> doc;
String buffer = "";
String ServerIP = "http://192.168.0.3:44388/";

// voltage
void postVoltage() {
  http.begin(ServerIP + "voltage");
  http.addHeader("Content-Type", "application/json");
  String requestData = "";
  float V_pin = map(analogRead( PANEL_PIN ), 0, 4095, 0, 3); // Puede que sea necesario cambiar el voltaje máximo
  float V_panel = 4 * V_pin;
  doc["voltage"] = V_panel;
  serializeJson( doc, buffer );

  Serial.println(buffer);
  
  int responseCode = http.POST( buffer );
  doc.clear();
  Serial.println("Código de salida: " + responseCode);
}

void delete_client() {
  //vTaskDelete(Task1);
}
