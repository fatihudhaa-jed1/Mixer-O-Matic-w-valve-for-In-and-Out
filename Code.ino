#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

//Input Sensor
int potPin = A0;
int startButton = 7;
int emergencyButton = 2;
int resetButton = 3;

//Servo
Servo valveIn;
Servo valveOut;
int servoInPin = 6;
int servoOutPin = 4;

//Motor
int motorIN1 = 9;
int motorEN  = 5;

//LED
int ledReady   = 10;
int ledProcess = 8;
int ledDone    = 13;

//Status
bool running = false;
bool emergencyActive = false;

unsigned long lastBlink = 0;
bool ledState = false;

bool safeDelay(unsigned long duration) {
  unsigned long start = millis();
  while (millis() - start < duration) {

    if (digitalRead(emergencyButton) == LOW) {
      emergencyActive = true;
      return true; 
    }
  }
  return false;
}

void setup() {

  pinMode(startButton, INPUT_PULLUP);
  pinMode(emergencyButton, INPUT_PULLUP);
  pinMode(resetButton, INPUT_PULLUP);

  pinMode(motorIN1, OUTPUT);
  pinMode(motorEN, OUTPUT);

  pinMode(ledReady, OUTPUT);
  pinMode(ledProcess, OUTPUT);
  pinMode(ledDone, OUTPUT);

  valveIn.attach(servoInPin);
  valveOut.attach(servoOutPin);

  valveIn.write(0);
  valveOut.write(0);

  lcd.init();
  lcd.backlight();

  lcd.print("Mixer ON");
  delay(1500);
  lcd.clear();
}

void loop() {

  //Emergency
  if (emergencyActive) {

    digitalWrite(motorEN, LOW);
    valveIn.write(0);
    valveOut.write(0);

    digitalWrite(ledReady, LOW);
    digitalWrite(ledProcess, LOW);

    if (millis() - lastBlink > 100) {
      lastBlink = millis();
      ledState = !ledState;
      digitalWrite(ledDone, ledState);
    }

    lcd.setCursor(0,0);
    lcd.print("EMERGENCY !");
    lcd.setCursor(0,1);
    lcd.print("Press RESET ");

    if (digitalRead(resetButton) == LOW) {
      emergencyActive = false;
      running = false;
      digitalWrite(ledDone, LOW);
      lcd.clear();
      delay(300);
    }

    return;
  }

  int potValue = analogRead(potPin);
  int mixTime = map(potValue, 0, 1023, 5, 20);

  //First Posit Init
  if (!running) {

    digitalWrite(ledReady, HIGH);
    digitalWrite(ledProcess, LOW);
    digitalWrite(ledDone, LOW);

    digitalWrite(motorEN, LOW);

    valveIn.write(0);
    valveOut.write(0);

    lcd.setCursor(0,0);
    lcd.print("Ready        ");
    lcd.setCursor(0,1);
    lcd.print("Time:");
    lcd.print(mixTime);
    lcd.print("s   ");

    if (digitalRead(startButton) == LOW) {
      running = true;
      delay(200);
      lcd.clear();
    }
  }

  else {
    //Fill (Valve In)
    digitalWrite(ledProcess, HIGH);

    lcd.setCursor(0,0);
    lcd.print("Filling...   ");

    valveIn.write(90);
    if (safeDelay(3000)) return;

    //Mix
    lcd.clear();
    lcd.print("Mixing...    ");

    valveIn.write(0);

    digitalWrite(motorIN1, HIGH);
    digitalWrite(motorEN, HIGH);

    if (safeDelay(mixTime * 1000)) return;

    digitalWrite(motorEN, LOW);

    //Out (Valve Out)
    lcd.clear();
    lcd.print("Discharge... ");

    valveOut.write(90);
    if (safeDelay(3000)) return;

    valveOut.write(0);

    //DONE
    digitalWrite(ledProcess, LOW);
    digitalWrite(ledDone, HIGH);

    lcd.clear();
    lcd.print("Done");

    if (safeDelay(3000)) return;

    running = false;
    lcd.clear();
  }
}
