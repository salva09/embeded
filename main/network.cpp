#include "network.h"

void connect_wifi() {
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pwd);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}

char* get_time() {
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    char* error = "No timestamp";
    return error;
  }

  char timestamp[100];

  sprintf(timestamp, "%A, %B %d %Y %H:%M:%S", &timeinfo);

  return timestamp;
}
