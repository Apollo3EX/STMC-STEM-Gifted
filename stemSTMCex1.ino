//Experiment 1
//STMC STEM Gifted Program

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
String SID;
byte smile[8] = {
  B00000,
  B10001,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
};

void setup()
{
  Serial.begin(115200);
  lcd.noBacklight();
  lcd.begin();
  lcd.createChar(0, smile);
  lcd.backlight();
  lcd.home();
  lcd.write(0);
  lcd.print(" Hello! Welcome");
  Serial.print("Please enter your student number: \n");
}

void loop()
{
  if (Serial.available() > 0) {
    SID = Serial.readString();
    SID.remove(SID.length() - 1);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Your SID is ");
    lcd.setCursor(0, 1);
    lcd.print(SID);
    Serial.print("Your SID is " + SID + "\n");
    Serial.print("Please enter your student number: \n");
    delay(1000);
  }else{
    delay(1000);
  }
}
