
#include <LiquidCrystal_I2C.h>  // download from https://github.com/ELECTROALL/Codigos-arduino/blob/master/LiquidCrystal_I2C.zip

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {

    lcd.init();
    lcd.backlight();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("<-- Evasora de"); 
    lcd.setCursor (0,1);
    lcd.print("<-- Impuestos");

}

void loop() {

    lcd.display();
    delay(500);
    lcd.noDisplay();
    delay(500);

}
