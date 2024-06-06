
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  // put your setup code here, to run once:
    lcd.init();
    lcd.backlight();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("<-- Evasora de"); 
    lcd.setCursor (0,1);
    lcd.print("<-- Impuestos");

}

void loop() {
  // put your main code here, to run repeatedly:
    lcd.display();
    delay(500);
    lcd.noDisplay();
    delay(500);

}
