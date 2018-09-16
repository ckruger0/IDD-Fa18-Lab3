#include <EEPROM.h>
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int sensorPin = A0;
int sensorValue = 0;
int addr = 0;
byte value;
int summedVal = 0;

long timer = 900000;

int EEPROM_size = 1023;

void setup()
{
  Serial.begin(9600);
  for (int i = 0; i < 1024; i++){
    EEPROM.write(i, 0);}

  lcd.begin(16,2);
  pinMode( sensorPin, INPUT );
  analogReference(DEFAULT);
}

void loop(){
  if(addr < 4){
    // Timer is set to collect every 15 minutes for 4 times. (1 hour per collection cycle)
    // Print confirmation to user that program is still running.. 
    lcd.setCursor(0,0);
    lcd.print("Still collecting"); 

    // Read data in
    int sensor_reading = analogRead(sensorPin);
  
    // Write data to EEPROM
    int val = sensor_reading / 4;
    EEPROM.write(addr, val);
    addr = addr + 1;
    lcd.setCursor(0,1);
    lcd.print(addr); lcd.print("/4"); lcd.print("    -1HR: "); lcd.print(EEPROM.read(EEPROM_size + 1));
    delay(timer);
  }
  else {
    // Read and print
    for(int i = 0; i < 4; i++){
      summedVal = summedVal + (EEPROM.read(i) * 4);
    }
    value = summedVal / 4;

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("AVG 1HR LIGHT:"); 
    lcd.setCursor(0,1);
    lcd.print(value);

    delay(5000);
    // Write 1 hour averages in descending order from end of EEPROM, only if there is space.
    if(EEPROM_size > addr){
      EEPROM.write(EEPROM_size, value);
      EEPROM_size = EEPROM_size - 1;
    }

    // Clear first 4 spots on EEPROM, and all counters for prior hour
    for (int i = 0; i < 4; i++){
      EEPROM.write(i, 0);}
    summedVal = 0;
    addr = 0;
  }
}
