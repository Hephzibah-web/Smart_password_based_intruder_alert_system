int ledR = 2;
int ledG = 3;
int proximity = 4;
int buzz = 5;
int btn1 = 6;
int btn2 = 7;
int btn3 = 8;
int value = 3;
int password = 207;//31223
int pressed = 0;
int trial = 3;
int readings;


void setup() {
  Serial.begin(9600);
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(proximity, INPUT);
  pinMode(buzz, OUTPUT);
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(btn3, INPUT_PULLUP);
}

void loop() {
  readings = digitalRead(proximity);
  //Serial.println(readings);
  delay(300);
  if (readings == 0) {
    digitalWrite(buzz, HIGH);
    delay(300);
    digitalWrite(buzz, LOW);
    delay(300);
    digitalWrite(buzz, HIGH);
    delay(300);
    digitalWrite(buzz, LOW);
    delay(300);
    Serial.println("INTRUDER DETECTED");
  }
  else {
    digitalWrite(buzz, LOW);
  }

  if (trial > 0) {
    if (digitalRead(btn1) == 0) {
      value = value * 7;
      Serial.print("1");
      pressed++;
      delay(300);
    }
    else if (digitalRead(btn2) == 0) {
      value = value + 3;
      Serial.print("2");
      pressed++;
      delay(300);
    }

    else if (digitalRead(btn3) == 0) {
      value = value * 3;
      Serial.print("3");
      pressed++;
      delay(300);
    }

    if (pressed == 5) {
      if (value == password) {
        digitalWrite(ledG, HIGH);
        Serial.println("ACCESS GRANTED");
        delay(5000);
        pressed = 0;
        value = 3;
      }
      else {
        digitalWrite(ledG, LOW);
        digitalWrite(ledR, HIGH);
        Serial.println("WRONG PASSWORD");
        alert();
      }

    }



  }
  else {
    digitalWrite(buzz, HIGH);
    delay(200);
    digitalWrite(buzz, LOW);
    delay(200);
    digitalWrite(buzz, HIGH);
    delay(200);
    digitalWrite(buzz, LOW);
    delay(200);
    digitalWrite(buzz, HIGH);
    delay(200);
    digitalWrite(buzz, LOW);
    delay(200);
    digitalWrite(buzz, HIGH);
    delay(200);
    digitalWrite(buzz, LOW);
    delay(200);
    digitalWrite(buzz, HIGH);
    delay(200);
    digitalWrite(buzz, LOW);
    delay(200);
    Serial.println("INTRUDER DETECTED");
    digitalWrite(ledR, HIGH);

  }
}

void alert() {
  for (int i = 0; i < 2; i++) {
    digitalWrite(buzz, HIGH);
    delay(200);
    digitalWrite(buzz, LOW);
    delay(200);
    digitalWrite(buzz, HIGH);
    delay(200);
    digitalWrite(buzz, LOW);
    delay(200);

  }
  pressed = 0;
  value = 3;
  trial--;
  Serial.println("TRY AGAIN=");
  Serial.print(trial);
}
