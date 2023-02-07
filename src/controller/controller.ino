// --- START EDITATBLE PARAMETERS ---
const int STREAM_LED = 13;
const int RECORD_LED = 13;
const int TIMEOUT = 5000 // if no message is received in TIMEOUT milliseconds, turn off light(s)
// --- END EDITABLE PARAMETERS---

#define NONE '0'
#define STREAMING '1'
#define RECORDING '2'
#define STREAMING_AND_RECORDING '3'

long int last_message = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    char state = Serial.read();
    if (state == NONE) {
      digitalWrite(STREAM_LED, LOW);
      digitalWrite(RECORD_LED, LOW);
    } else if (state == STREAMING) {
      digitalWrite(RECORD_LED, LOW);
      digitalWrite(STREAM_LED, HIGH);
    } else if (state == RECORDING) {
      digitalWrite(STREAM_LED, LOW);
      digitalWrite(RECORD_LED, HIGH);
    } else if (state == STREAMING_AND_RECORDING) {
      digitalWrite(STREAM_LED, HIGH);
      digitalWrite(RECORD_LED, HIGH);
    }
    last_message = millis();
  } else {
    if (millis() - last_message > TIMEOUT) {
      digitalWrite(STREAM_LED, LOW);
      digitalWrite(RECORD_LED, LOW);
    }
  }
}
