// (c) Michael Schoeffler 2017, http://www.mschoeffler.de
//#include <Wire.h>
//#include <LiquidCrystal_I2C.h>

//LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); // initializes the LCM1602 IIC V1 (LCD module)
// 0x27 is the I2C address. This address might be different.

const int IN_A0 = A0; // analog input
const int IN_D0 = 8; // digital input

void setup() {
  Serial.begin(9600);
  pinMode (IN_A0, INPUT);
  pinMode (IN_D0, INPUT);
  
  //lcd.begin(16, 2); // begins connection to the LCD module
  //lcd.backlight(); // turns on the backlight
}

int value_A0;
bool value_D0;

void loop() {

  value_A0 = analogRead(IN_A0); // reads the analog input from the IR distance sensor
  value_D0 = digitalRead(IN_D0);// reads the digital input from the IR distance sensor
  Serial.println(value_A0);

  
  delay(1000);
}
