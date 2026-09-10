#include <WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "nombre_red";
const char* password = "clave_red";
const int pinPIR = 27;
WiFiUDP udp;
const char* ipDestino = "192.168.1.100";
const int puerto = 5005;

void setup() {
  Serial.begin(115200);
  pinMode(pinPIR, INPUT);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(300);
  udp.begin(puerto);
}

void loop() {
  int movimiento = digitalRead(pinPIR);
  String estado = movimiento ? "occupied" : "free";
  String msg = "{\"type\":\"status_update\",\"node_id\":\"esp32-salon-302\","
               "\"room\":\"302\",\"status\":\"" + estado + "\"}";
  udp.beginPacket(ipDestino, puerto);
  udp.print(msg);
  udp.endPacket();
  delay(3000);
}
