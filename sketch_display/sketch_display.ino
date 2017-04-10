
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);   /* Задаем адрес и размерность дисплея. 
При использовании LCD I2C модуля с дисплеем 20х04 ничего в коде изменять не требуется, cледует только задать правильную размерность */
int a = 3;
char b = '-';
float c = 3.14;
char output_string[16];
int i;
char mes[16];
void setup()
{
  lcd.init();             
  lcd.backlight();                       
  /*Курсор находится в начале 1 строки
  lcd.setCursor(0, 1);
  lcd.print("");  */
}

void loop()
{
  i=rand()%11;
  
  sprintf(mes, "%3.d", i);
  lcd.setCursor(0, 0);
  lcd.print("current rand int:");
  lcd.setCursor(0, 1);
  lcd.print(mes);
  delay(1000);
  lcd.print("");
  }
