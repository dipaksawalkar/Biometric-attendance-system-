#include <Adafruit_Fingerprint.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#if (defined(__AVR__) || defined(ESP8266)) && !defined(__AVR_ATmega2560__)
SoftwareSerial mySerial(6, 7);
#else
#define mySerial Serial  
#endif

int sankalp=0;
int sagar=0;
int shradha=0;
int anuj=0;
int akshay=0;
int snehal=0;
int dipak=0;
int sneha=0;
int chetana=0;

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
void setup()
{
  Serial.begin(9600);
  while (!Serial);  
  delay(100);
  lcd.begin(16,2);
  lcd.println("   Attendance   ");
  lcd.setCursor(0,1);
  lcd.println("     System     ");
  delay(2000);
  finger.begin(57600);
  delay(5);
  if (finger.verifyPassword()) 
  {
    Serial.println("Found sensor!");
  } else 
  {
    Serial.println("no sensor detect :(");
    while (1) { delay(1); }
  }


}

void loop()                   
{
  getFingerprintID();
  delay(50);            
}

uint8_t getFingerprintID() 
{
  uint8_t p = finger.getImage();
  switch (p) 
  {
    case FINGERPRINT_OK:
      lcd.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      lcd.clear();
      lcd.println("Scanning...     ");
      delay(50);
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      lcd.println("Comm. error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      lcd.println("Imaging error");
      return p;
    default:
      lcd.println("Unknown error");
      return p;
  }
  p = finger.image2Tz();
  switch (p) 
  {
    case FINGERPRINT_OK:
      lcd.println("Image converted");
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      lcd.println("Communication error");
      return p;
    default:
      lcd.println("Unknown error");
      return p;
  }
  p = finger.fingerSearch();
  if (p == FINGERPRINT_OK) 
  {
    lcd.println("Matched !");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) 
  {
    lcd.println("Comm. error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) 
  {
    lcd.println("No match");
    return p;
  } else 
  {
    lcd.println("Unknown error");
    return p;
  }
  Serial.print("Found ID #"); Serial.print(finger.fingerID);
  lcd.clear();
  lcd.setCursor(0, 0);
  if((finger.fingerID)==1)
  {
    lcd.println("WELCOME SANKALP ");
    sankalp++;
    delay(3000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Attendence");
    lcd.setCursor(0,1);
    lcd.print("Count: "); lcd.print(sankalp);
    delay(2000);
  }
  else if((finger.fingerID)==2)
  {
    lcd.println("WELCOME SHRADHA ");
    shradha++;
    delay(3000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Attendence");
    lcd.setCursor(0,1);
    lcd.print("Count: "); lcd.print(shradha);
    delay(2000);
  }
  else if((finger.fingerID)==3)
  {
    lcd.println("WELCOME SAGAR   ");
    sagar++;
    delay(3000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Attendence");
    lcd.setCursor(0,1);
    lcd.print("Count: "); lcd.print(sagar);
    delay(2000);
  }
  else if((finger.fingerID)==4)
  {
    lcd.println("WELCOME AKSHAY  ");
    akshay++;
    delay(3000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Attendence");
    lcd.setCursor(0,1);
    lcd.print("Count: "); lcd.print(akshay);
    delay(2000);
  }
  else if((finger.fingerID)==5)
  {
    lcd.println("WELCOME ANUJ    ");
    anuj++;
    delay(3000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Attendence");
    lcd.setCursor(0,1);
    lcd.print("Count: "); lcd.print(anuj);
    delay(2000);
  } 
   else if((finger.fingerID)==6)
  {
    lcd.println("WELCOME SNEHAL  ");
    snehal++;
    delay(3000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Attendence");
    lcd.setCursor(0,1);
    lcd.print("Count: "); lcd.print(snehal);
    delay(2000);
  } 
  else if((finger.fingerID)==7)
  {
    lcd.println("WELCOME DIPAK  ");
    dipak++;
    delay(3000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Attendence");
    lcd.setCursor(0,1);
    lcd.print("Count: "); lcd.print(dipak);
    delay(2000);
  } 
  else if((finger.fingerID)==8)
  {
    lcd.println("WELCOME SNEHA  ");
    sneha++;
    delay(3000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Attendence");
    lcd.setCursor(0,1);
    lcd.print("Count: "); lcd.print(sneha);
    delay(2000);
  } 
   else if((finger.fingerID)==9)
  {
    lcd.println("WELCOME CHETANA  ");
    chetana++;
    delay(3000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Attendence");
    lcd.setCursor(0,1);
    lcd.print("Count: "); lcd.print(chetana);
    delay(2000);
  } 
  lcd.setCursor(0,0);
  lcd.println("   Attendence   ");
  lcd.setCursor(0,1);
  lcd.println("     Marked!     ");
  delay(2000);
  return finger.fingerID;
}
int getFingerprintIDez() 
{
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;


  return finger.fingerID;
}
