// --- START EDITATBLE PARAMETERS ---
const int STREAM_LED = 13;
const int RECORD_LED = 13;
// --- END EDITABLE PARAMETERS---

#define Events.NONE `0`
#define Events.STREAMING `1`
#define Events.RECORDING `2`
#define Events.STREAMING_AND_RECORDING `3`

long int last_message = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    char state = Serial.read();
    if (state == '0') {
      digitalWrite(STREAM_LED, LOW);
      digitalWrite(RECORD_LED, LOW);
    } else if (state == '1') {
      digitalWrite(RECORD_LED, LOW);
      digitalWrite(STREAM_LED, HIGH);
    } else if (state == '2') {
      digitalWrite(STREAM_LED, LOW);
      digitalWrite(RECORD_LED, HIGH);
    } else if (state == '3') {
      digitalWrite(STREAM_LED, HIGH);
      digitalWrite(RECORD_LED, HIGH);
    }
    last_message = millis();
  } else {
    if (millis() - last_message > 5000) {
      digitalWrite(STREAM_LED, LOW);
      digitalWrite(RECORD_LED, LOW);
    }
  }
}
