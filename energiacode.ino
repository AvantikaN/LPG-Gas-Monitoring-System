/*
  AnalogReadSerial
  Reads an analog input on pin A3, prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A3, and the outside pins to ~3V and ground.
  
  Hardware Required:
  * MSP-EXP430G2 LaunchPad
  * 10-kilohm Potentiometer
  * hook-up wire

  This example code is in the public domain.
*/
const int BUZZER = P8_2;
const int THRESHOLD = 800;
const int RELAY = P3_7;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600); // msp430g2231 must use 4800
  pinMode(BUZZER, OUTPUT);
  pinMode(RELAY, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin A3:
  int sensorValue = analogRead(A3);
  // print out the value you read:
  if (sensorValue > THRESHOLD) {
    Serial.print(" LPG detected  :");
    Serial.println(sensorValue);
    delay(1000);
    buzzer_beep();   // turn the LED on (HIGH is the voltage level)
    ac_fan();
  }
  else {
    digitalWrite(BUZZER,LOW);
    digitalWrite(RELAY,HIGH); 
  }
}
void buzzer_beep(){
    digitalWrite(BUZZER, HIGH);
    delay(1000);
    digitalWrite(BUZZER, LOW);
    delay(500);

    return;
}
void ac_fan(){
    digitalWrite(RELAY, HIGH);
    delay(1000); 
    return;
}
