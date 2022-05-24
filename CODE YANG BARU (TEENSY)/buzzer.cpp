int buzzerPin = 13;

void setup() {
  Serial.begin(115200);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  if (some_altitude_function() == 0) {
    // buzzes for 5 seconds 
    digitalWrite(buzzerPIN, HIGH);
    delay(5000);
    digitalWrite(buzzerPIN, LOW);
    delay(2000);
  }
}

// placeholder function
int some_altitude_function() {
  return 0;
}
