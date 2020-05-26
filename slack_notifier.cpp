#include <Arduino.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>
#include "slack_notifier.h"

String working_json = "{\"profile\": { \"status_text\": \"On Pomodoro\", \"status_emoji\": \":tomato:\" } }";
String relaxing_json = "{\"profile\": { \"status_text\": \"Available\", \"status_emoji\": \":batsignal:\" } }";

SlackNotifier::SlackNotifier(char *token)
{
  this->token = token;
  this->last_mode = "waitingForWork";
}

void SlackNotifier::resolve(String mode)
{
  if (mode != last_mode && (mode == "working" || mode == "relaxing"))
  {
    std::unique_ptr<BearSSL::WiFiClientSecure>client(new BearSSL::WiFiClientSecure);
    client->setInsecure();
    HTTPClient http;
    last_mode = mode;
    if (http.begin(*client, "https://slack.com/api/users.profile.set")) //Iniciar conexión
    {
      http.addHeader("Content-Type", "application/json");
      http.addHeader("Authorization", strcat("Bearer ", token));
      String json = mode == "working" ? working_json : relaxing_json;
      int httpCode = http.POST(json); // Realizar petición

      if (httpCode > 0)
      {
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY)
        {
          String payload = http.getString(); // Obtener respuesta
          Serial.println("payload");
          Serial.println(payload);           // Mostrar respuesta por serial
        }
      }
      else
      {
        Serial.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    }
    else
    {
      Serial.println("[HTTP} Unable to connect");
    }
  }
}
