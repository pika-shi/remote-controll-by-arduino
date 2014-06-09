void setup(){
  Serial.begin(57600);
  pinMode(8, INPUT);
  Serial.println("Ready to receive");
}

void continueLow() {
  while (digitalRead(8) == LOW) {
    ;
  }
}

int continueHigh() {
  unsigned long start = micros();
  while (digitalRead(8) == HIGH) {
    if (micros() - start > 5000000) {
      return 1;
    }
  }
  return 0;
}

unsigned long now = micros();
unsigned long changed = micros();
int state = 1;

void loop() {
  if (state == 0) {
    continueLow();
  } else {
    int ret = continueHigh();
    if (ret == 1) {
      Serial.print('\n');
      return;
    }
  }

  now = micros();
  Serial.print((now - changed) / 10, DEC);
  Serial.print(",");
  changed = now;
  if (state == 1) {
    state = 0;
  } else {
    state = 1;
  }
}
