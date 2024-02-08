#include <LiquidCrystal_I2C.h>

#include <Wire.h>


#define endereco  0x27 
#define colunas   16
#define linhas    2
#define pinSensorUSA A0
#define pinSensorUSD 7
int nivel;
float percentUS = 0;
float leituraSensorUS = 0;


LiquidCrystal_I2C lcd(endereco, colunas, linhas);


void setup() {
  Serial.begin (9600);
 
  lcd.init(); // INICIA A COMUNICAÇÃO COM O DISPLAY
  lcd.backlight(); // LIGA A ILUMINAÇÃO DO DISPLAY
  lcd.clear(); // LIMPA O DISPLAY

  lcd.setCursor (7,0);
  lcd.print ("Sensor");
  delay (3000);
  lcd.setCursor(3,2);
  lcd.print ("Umidade do solo");
  delay (2000);
  lcd.setCursor(5,3);
  lcd.print ("Higrometro");
  delay (5000);

  lcd.clear();

  lcd.setCursor (17,3);
  lcd.print (".");
  delay (2000);
  lcd.setCursor (18,3);
  lcd.print (".");
  delay (2000);
  lcd.setCursor (19,3);
  lcd.print (".");
  delay (2000);
  lcd.clear();


  

  lcd.noBacklight(); // DESLIGA A ILUMINAÇÃO DO DISPLAY
  delay(10); // DELAY DE 2 SEGUNDOS
  lcd.backlight(); // LIGA A ILUMINAÇÃO DO DISPLAY
  delay(100); // DELAY DE 2 SEGUNDOS
  
 
   
}


void loop() {

 
  Serial.print ( "Umidade: ");
  Serial.print (nivel);
  Serial.println ();

  leituraSensorUS  = analogRead (pinSensorUSA);
  percentUS = (1023-leituraSensorUS)/10,24;
  Serial.print ("Percentual: ");
  Serial.print (percentUS);
  Serial.println ();
  

 lcd.home();
 nivel = analogRead(pinSensorUSA);
 
 lcd.setCursor(0,0);
 lcd.print("Solo:");
 lcd.setCursor(0,2);
 lcd.print("Percentual:");
 lcd.setCursor (12,2);
 lcd.print (percentUS,0);
 lcd.setCursor (14,2);
 lcd.write (B00100101);


if (percentUS > 0 && percentUS <= 15)
{
  lcd.setCursor(6, 0);
  lcd.print("Muito Seco!  ");
  delay(1000);
}
else if (percentUS > 15 && percentUS <= 35)
{
  lcd.setCursor(6, 0);
  lcd.print("Seco!        ");
  delay(1000);
}
else if (percentUS > 35 && percentUS <= 65)
{
  lcd.setCursor(6, 0);
  lcd.print("Umido!       ");
  delay(1000);
}
else if (percentUS > 65 && percentUS <= 100)
{
  lcd.setCursor(6, 0);
  lcd.print("Enxarcado!   ");
  delay(1000);
}
}
