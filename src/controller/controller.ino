#include <LiquidCrystal.h> // includes the LiquidCrystal Library 
LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7) 

void setup() { 
  lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display }
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  lcd.clear();
  delay(1000);
}

void loop() {
  if (Serial.available()) {
    char state = Serial.read();
    lcd.print(state);
    if (state == '1' || state == '2' || state == '3') {
      digitalWrite(LED_BUILTIN, HIGH);
    } else if (state == '0') {
      digitalWrite(LED_BUILTIN, LOW);
    } else {
      lcd.write(state);
    }
  }
}
