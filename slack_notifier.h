#ifndef SLACK_NOTIFIER_H
#define SLACK_NOTIFIER_H
#include <Arduino.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>

class SlackNotifier {
  private:
    char* token;
    String last_mode;
    WiFiClientSecure client;
    HTTPClient http;

  public:
    SlackNotifier(char* token);

    void resolve(String mode);
};

#endif
