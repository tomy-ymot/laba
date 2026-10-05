#include <DHT11.h>
DHT11 dht11(2);

#include <Servo.h>
Servo m2_servo;
//12121
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int butt1=16;
int butt2 = 17;
int buz = 12;
int led = 8;

//gde?

void func_buz(void)
{
  tone(buz, 500);
  delay(250);
  noTone(buz); 
}

void setup() {
  lcd.init();          
  lcd.backlight();
  Serial.begin(9600);
  m2_servo.attach(9);
  pinMode(butt2, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  pinMode(butt1,INPUT_PULLUP);
  pinMode(A1, INPUT);
  pinMode(A0,INPUT);
  digitalWrite(led,1);
  m2_servo.write(0);
  delay(1000);


  m2_servo.write(0);


}

void loop() {
  bool f2 = digitalRead(butt2);
  bool f1 = digitalRead(butt1);
  int t = dht11.readTemperature();
  int n = analogRead(A1);
  int g = analogRead(A0);
  Serial.print("газ: ");
  Serial.println(g);
  Serial.print("Вологість: ");
  Serial.println(n);
  Serial.print("tem: ");
  Serial.println(t);

  if (f1==0){
  lcd.setCursor(0,0);
  delay(500);
  lcd.print(1);
  func_buz();
  delay(500);
  lcd.clear(); 
  lcd.print(2);
  func_buz();
  delay(500);
  lcd.clear(); 
  lcd.print(3);
  func_buz();
  delay(500);
  lcd.clear(); 
  lcd.print(4);// display number 4
  func_buz();
  delay(500);
  lcd.clear(); 
  lcd.print(5);// display number 5
  func_buz();
  delay(500);
  lcd.clear(); 
  lcd.print(6);// display number 6
  func_buz();
  delay(500);
  lcd.clear(); 
  lcd.print(7);// display number 7
  func_buz();
  delay(500);
  lcd.clear(); 
  lcd.print(8);// display number 8
  func_buz();
  delay(500);
  lcd.clear(); 
  lcd.print(9);// display number 9
  tone(buz, 500);
  delay(4000);// 
  noTone(buz);
  lcd.clear();
}
  if (f2==0){
    int k = 0;
    int num_variant = 14;  // номер варіанта
    while (k < (num_variant/2)){   
      digitalWrite(led, 0);
      delay(250);
      digitalWrite(led, 1);
      delay(250);
      digitalWrite(led, 0);
      delay(250);
      digitalWrite(led, 1);
      delay(250);
      k=k+1;
    
    }
  }

  if (t >= 36) {
    m2_servo.write(10);
    Serial.println("Servo 10");
    
  }
  else {
    m2_servo.write(45);
     Serial.println("Servo 45");
   
  }

}
