//SISTEMA DE RIEGO AUTOMATICO CON LOGICA DIFUSA
//INTEGRANTES
//LORENA SANCHEZ, ELKIN RAMIREZ, YENIFER VALENCIA, JUAN FELIPE MARIN


//LIBRERIAS 
#include <LiquidCrystal.h>


const int sensorPin= A0; //Sensor de humedad 
const int relay = 10; //Bomba de agua

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  pinMode(relay, OUTPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
  

}

void loop() {
  
  lcd.setCursor(0, 1);
  int value = analogRead(sensorPin);
  lcd.begin(16, 2);
  int humedad = analogRead(sensorPin);
  lcd.print(humedad);
  if( humedad <= 130) 
     {
        digitalWrite(relay, HIGH);
        lcd.setCursor(0,0);
        lcd.print(" Esta Mojado o  ");
        lcd.setCursor(0,1);
        lcd.print("   Muy humedo   ");
     }
      else
       {
         if(humedad <= 250)
          {
            digitalWrite(relay, HIGH);
            lcd.setCursor(0,0);
            lcd.print("  Se Encuentra  ");
            lcd.setCursor(0,1);
            lcd.print("   SemiHumedo    ");  
        
         }
           if(humedad > 245 and humedad <= 310)
             {
                digitalWrite(relay, LOW);
                delay(1000);
                digitalWrite(relay, HIGH);
                delay(1000);
                digitalWrite(relay, LOW);
                delay(1000);
                lcd.setCursor(0,0);
                lcd.print("Semi seco Salida");  
                lcd.setCursor(0,1);
                lcd.print("de agua 1 sg x 2");
        
             }
               if(humedad > 300) 
                 {
                   digitalWrite(relay, LOW);
                   delay(3000);
                   lcd.setCursor(0,0);
                   lcd.print("Seco Encendida  ");  
                   lcd.setCursor(0,1);
                   lcd.print("La Bomba de agua");
        
                 }
        }
     
    delay(1000);
}
