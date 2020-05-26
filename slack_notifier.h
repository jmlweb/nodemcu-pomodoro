#ifndef SLACK_NOTIFIER_H
#define SLACK_NOTIFIER_H
#include <Arduino.h>

class SlackNotifier {
  private:
    char* token;
    String last_mode;

  public:
    SlackNotifier(char* token);

    void resolve(String mode);
};

#endif
