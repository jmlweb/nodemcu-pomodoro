#include <ESP8266WiFi.h>

#include "config.h";
#include "button.h";
#include "led_notifier.h";
#include "pomodoro.h";
#include "slack_notifier.h";

/*
 * config
 */
const byte start_button_pin = START_BUTTON_PIN;
const byte stop_button_pin = STOP_BUTTON_PIN;
const byte red_led_pin = RED_LED_PIN;
const byte green_led_pin = GREEN_LED_PIN;
const char* wifi_ssid = WIFI_SSID;
const char* wifi_password = WIFI_PASSWORD;

Button start_button(START_BUTTON_PIN);
Button stop_button(STOP_BUTTON_PIN);
LedNotifier led_notifier(RED_LED_PIN, GREEN_LED_PIN);
Pomodoro pomodoro;
SlackNotifier slack_notifier(SLACK_OAUTH_TOKEN);

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  start_button.config();
  stop_button.config();
  led_notifier.init();
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("*");
    delay(200);
  }
  Serial.print("connected to:\t");
  Serial.println(WiFi.SSID());
  Serial.print("IP Address:\t");
  Serial.println(WiFi.localIP());
}

void loop() {
  pomodoro.process();
  if (!pomodoro.is_pristine()) {
    led_notifier.resolve(pomodoro.current_mode());
    slack_notifier.resolve(pomodoro.current_mode());
  }
  if (start_button.is_active()) {
    pomodoro.start();
  } else if (stop_button.is_active()) {
    pomodoro.stop();
  }
}
