
#include <SoftwareSerial.h>
SoftwareSerial bt(2, 3);


#include <Temperature_LM75_Derived.h>  // download from https://downloads.arduino.cc/libraries/github.com/jeremycole/I2C_Temperature_Sensors_derived_from_the_LM75-1.0.3.zip
Generic_LM75 temperature;


float temp = 0;


#include <LiquidCrystal_I2C.h>  // download from https://github.com/ELECTROALL/Codigos-arduino/blob/master/LiquidCrystal_I2C.zip
LiquidCrystal_I2C lcd(0x27,16,2);

int ledGreen = 8;
int ledRed = 7;

void setup() {
  while(!Serial) {}
  Serial.begin(9600);
  bt.begin(9600);

  lcd.init();
  lcd.backlight();

  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);

  Wire.begin();
}
 

void loop() {
  lcd.clear();
  temp = temperature.readTemperatureC();

  Serial.println(temp);

  if (temp >= 30){
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledRed, LOW);

    lcd.setCursor(0,0);
    lcd.print(temp);
    lcd.setCursor(0,1);
    lcd.print("ON");
  }

  if (temp < 30){
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, HIGH);

    lcd.setCursor(0,0);
    lcd.print(temp);
    lcd.setCursor(0,1);
    lcd.print("OFF");
  }



  lcd.display();
  bt.print(temp);
  delay(1000);
}
