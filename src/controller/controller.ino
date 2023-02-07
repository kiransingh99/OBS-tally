// --- START EDITATBLE PARAMETERS ---
const int STREAM_LED = 13;
const int RECORD_LED = 13;
// --- END EDITABLE PARAMETERS---

#define Events.NONE `0`
#define Events.STREAMING `1`
#define Events.RECORDING `2`
#define Events.STREAMING_AND_RECORDING `3`

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  delay(1000);
}

void loop() {
  if (Serial.available()) {
    char state = Serial.read();
    if (state == '0') {
      digitalWrite(STREAM_LED, LOW);
      digitalWrite(RECORD_LED, LOW);
    } else if (state == '1') {
      digitalWrite(STREAM_LED, HIGH);
      digitalWrite(RECORD_LED, LOW);
    } else if (state == '2') {
      digitalWrite(STREAM_LED, LOW);
      digitalWrite(RECORD_LED, HIGH);
    } else if (state == '3') {
      digitalWrite(STREAM_LED, HIGH);
      digitalWrite(RECORD_LED, HIGH);
    }
  }
}
