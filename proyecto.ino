#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


float Vd; 
float Id;
float fuente;
float escala=5; //Ajusta las mediciones

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
 
  // put your setup code here, to run once:
pinMode(2,INPUT); // Pin sensor LDR
pinMode(A1,INPUT); 
pinMode(A2,INPUT);
analogWrite(A1,0);
analogWrite(A2,0);
lcd.init();                     
lcd.backlight();
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
fuente=((analogRead(A1)*escala)/1024);
medir_Vd();
medir_Id();


Serial.print(Vd);
Serial.print("              ");
Serial.println(Id);
delay(500);
lcd.clear();

}

void medir_Vd()

{
  ;
  
  Vd=(analogRead(A1))- (analogRead(A2));
  Vd=((Vd*escala)/1024);
if(digitalRead(2)==0){
  lcd.setCursor(0,0);
  lcd.print("Vd(V):");
  lcd.setCursor(7,0);
  lcd.print(Vd);}
    }

void medir_Id()
{
  Id=((analogRead(A2)*escala)/1024);
  Id=((Id*1000)/240);
  if(digitalRead(2)==0){
  lcd.setCursor(0,1);
  lcd.print("Id(mA):");
  lcd.setCursor(7,1);
  lcd.print(Id);}
   
  }
