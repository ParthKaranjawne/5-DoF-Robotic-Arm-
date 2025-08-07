
#include <WiFi.h>
#include <WebSocketsServer.h>
#include <Servo.h>

Servo servos[5];
int pins[5] = {13, 12, 14, 27, 26};
int recordedMoves[100][5];
int moveCount = 0;
bool recording = false;

WebSocketsServer webSocket = WebSocketsServer(81);

void handleMessage(uint8_t * payload) {
  StaticJsonDocument<200> doc;
  deserializeJson(doc, payload);
  if (doc.containsKey("angles")) {
    for (int i = 0; i < 5; i++) {
      int angle = doc["angles"][i];
      servos[i].write(angle);
      if (recording) {
        recordedMoves[moveCount][i] = angle;
      }
    }
    if (recording) moveCount++;
  }
  if (doc["command"] == "start_recording") {
    moveCount = 0;
    recording = true;
  }
  if (doc["command"] == "replay") {
    recording = false;
    for (int i = 0; i < moveCount; i++) {
      for (int j = 0; j < 5; j++) servos[j].write(recordedMoves[i][j]);
      delay(500);
    }
  }
}

void setup() {
  WiFi.begin("YourSSID", "YourPassword");
  while (WiFi.status() != WL_CONNECTED) delay(1000);

  for (int i = 0; i < 5; i++) servos[i].attach(pins[i]);
  webSocket.begin();
  webSocket.onEvent([](uint8_t num, WStype_t type, uint8_t * payload, size_t length) {
    if (type == WStype_TEXT) handleMessage(payload);
  });
}

void loop() {
  webSocket.loop();
}
