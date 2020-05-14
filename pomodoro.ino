int const TOTAL_MODES = 4;
String const WAIT_WORK = "waitWork";
String const WORK = "work";
String const WAIT_RELAX = "waitRelax";
String const RELAX = "relax";

String modes[TOTAL_MODES] = {WAIT_WORK, WORK, WAIT_RELAX, RELAX};
int current = 0;
int started_time;
int remaining_time;

String get_current_mode(){
  return modes[current];
}

void advance() {
  current++;
  if (current >= TOTAL_MODES) {
    current = 0;
  }
}

void start() {
  String current_mode = get_current_mode();
  if (current_mode != WORK && current_mode != RELAX) {
    advance();
    started_time = millis();
  }
}

void stop() {
  String current_mode = get_current_mode();
  if (current_mode == WAIT_WORK) {
    current = 2;
  } else if (current_mode == WAIT_RELAX) {
    current = 0;
  } else {
    advance();
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  start();
}

void loop() {
  String current_mode = get_current_mode();
  if (current_mode == WORK || current_mode == RELAX) {
    int current_time = millis();
    remaining_time = 25 * 60 * 1000 - (current_time - started_time);
    Serial.println(round(remaining_time / 1000));
    if (remaining_time <= 0) {
      advance();
    }
  };
  delay(100);
}
