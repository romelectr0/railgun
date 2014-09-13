#include <PCD8544.h>
static PCD8544 lcd;
unsigned char skullh[] = {B00111100,B01100110,B11100111,B11101111,B10111111,B11101111,B11100111,B01100110,B00111100};
unsigned char skulll[] = {0,0,B00000001,0,B00000001,0,B00000001};
unsigned char block[] = {255,255,255,255,255,255};
unsigned char blank[] = {0};
unsigned char lined[] = {B00000100};
unsigned char linec[] = {B00000111};
unsigned char linecc[] = {255};
unsigned char linecd[] = {B11110000};
unsigned char linet[] = {B00010000};
unsigned char rail[] = {B11100111};
unsigned char bullet[] = {B00011000};
unsigned char thorn[] = {B1001000,B0101100,B0011010,B0001001};
unsigned char explode1[] = {B00011000,B00111100,B01111110,B01111110,B00111100,B00011000};
unsigned char explode2[] = {B00011000,B00011000};
unsigned char explode3[] = {B00011000,B00111100,B00111100,B00011000};
unsigned char man[] = {B00010000,B11001011,B00111111,B11001011,B00010000};
unsigned char railgun[] = {B1101111,B1000,B10001,B100001,B1000010};
int choosevalue = 200;
int decalnearblock = 4;
int longblock = 29;
int decalotherblock = 5;
int value;
int purcent = 0;
int decalwrite = 3;
void setup() {
  Serial.begin(9600);
  lcd.begin(84,48);
  lcd.setInverse(false);
}
void animation() {
  for(int h = 0;h<20;h++) {
      lcd.setCursor(decalwrite+h+8,0);
      lcd.drawBitmap(rail,1,1);
    }
    
    delay(500);
    lcd.setCursor(79,0);
    lcd.drawBitmap(man,6,1);
     lcd.setCursor(0,0);
  lcd.drawBitmap(thorn,4,1);
  for(int v = 1;v <76;v++) {
    if (v > 0 && v < 21) {
    lcd.setCursor(v+8,0);
    lcd.drawBitmap(linecc,1,1);
    lcd.setCursor(v+9,0);
    lcd.drawBitmap(linecc,1,1);
    lcd.setCursor(v-1+8,0);
    lcd.drawBitmap(rail,1,1);
  }
  else {
    lcd.setCursor(v+8,0);
    lcd.drawBitmap(bullet,1,1);
    lcd.setCursor(v+9,0);
    lcd.drawBitmap(bullet,1,1);
    lcd.setCursor(v-1+8,0);
    lcd.drawBitmap(blank,1,1);
  }
  delay(40);
  }
  for(int h = 0;h < 2;h++) {
  lcd.setCursor(78,0);
  lcd.drawBitmap(explode1,6,1);
  delay(250);
  for(int e = 0;e <8;e++) {
    lcd.setCursor(78+e,0);
    lcd.drawBitmap(blank,1,1);
  }
  lcd.setCursor(80,0);
  lcd.drawBitmap(thorn,4,1);
  delay(250);
  for(int e = 0;e <8;e++) {
    lcd.setCursor(78+e,0);
    lcd.drawBitmap(blank,1,1);
  }
  }
  lcd.setCursor(0,0);
  lcd.drawBitmap(thorn,4,1);
}
void loop () {
  while(true) {
    animation();
  for(int y = 0;y < longblock;y++) {
    lcd.setCursor(y+decalnearblock,4);
    lcd.drawBitmap(lined,1,1);
    lcd.setCursor(y+decalnearblock+longblock+decalotherblock,4);
    lcd.drawBitmap(lined,1,1);
  }
  for(int y = 0;y < longblock;y++) {
    lcd.setCursor(y+decalnearblock,2);
    lcd.drawBitmap(linet,1,1);
    lcd.setCursor(y+decalnearblock+longblock+decalotherblock,2);
    lcd.drawBitmap(linet,1,1);
  }
  lcd.setCursor(decalnearblock,2);
  lcd.drawBitmap(linecd,1,1);
  lcd.setCursor(decalnearblock+longblock+decalotherblock,2);
  lcd.drawBitmap(linecd,1,1);
  lcd.setCursor(decalnearblock+longblock,2);
  lcd.drawBitmap(linecd,1,1);
  lcd.setCursor(decalnearblock+2*longblock+decalotherblock,2);
  lcd.drawBitmap(linecd,1,1);
  /*lcd.setCursor(30,3);
  lcd.drawBitmap(skullh,9,1);
  lcd.setCursor(30,4);
  lcd.drawBitmap(skulll,9,1);*/
  lcd.setCursor(decalwrite+decalnearblock+19,3);
  lcd.print("V");
  lcd.setCursor(decalwrite+decalnearblock+longblock+decalotherblock+19,3);
  lcd.print("%");
    lcd.setCursor(decalnearblock,4);
  lcd.drawBitmap(linec,1,1);
  lcd.setCursor(decalnearblock+longblock+decalotherblock,4);
  lcd.drawBitmap(linec,1,1);
  lcd.setCursor(decalnearblock+longblock,4);
  lcd.drawBitmap(linec,1,1);
  lcd.setCursor(decalnearblock+2*longblock+decalotherblock,4);
  lcd.drawBitmap(linec,1,1);
  lcd.setCursor(decalnearblock,3);
  lcd.drawBitmap(linecc,1,1);
  lcd.setCursor(decalnearblock+longblock+decalotherblock,3);
  lcd.drawBitmap(linecc,1,1);
  lcd.setCursor(decalnearblock+longblock,3);
  lcd.drawBitmap(linecc,1,1);
  lcd.setCursor(decalnearblock+2*longblock+decalotherblock,3);
  lcd.drawBitmap(linecc,1,1);
  for(int i = 0;i < 100;i++) {
     for(int y = 0;y < choosevalue/100;y++){
    value = i*(choosevalue/100)+y+1;
    lcd.setCursor(decalwrite+decalnearblock,3);
    lcd.print(value,DEC);
    delay(500);
     }
    lcd.setCursor(decalwrite+decalnearblock+longblock+decalotherblock,3);
    purcent = i+1;
    lcd.print(purcent,DEC);
    if (purcent >= 50) {
      if (i%2 == 0) {
        lcd.setCursor(decalwrite+2*longblock+decalnearblock+decalotherblock,3);
        lcd.drawBitmap(skullh,9,1);
        lcd.setCursor(decalwrite+2*longblock+decalnearblock+decalotherblock,4);
        lcd.drawBitmap(skulll,7,1);
      }
      if (i%2 != 0) {
        for(int m = 0;m <9;m++) {
          lcd.setCursor(decalwrite+2*longblock+decalnearblock+decalotherblock+m,3);
          lcd.drawBitmap(blank,1,1);
          lcd.setCursor(decalwrite+2*longblock+decalnearblock+decalotherblock+m,4);
          lcd.drawBitmap(blank,1,1);
        }
      }
    }
    if (purcent == 100) {
      lcd.setCursor(75,5);
      lcd.drawBitmap(block,6,1);
      lcd.setCursor(decalwrite+2*longblock+decalnearblock+decalotherblock,3);
        lcd.drawBitmap(skullh,9,1);
        lcd.setCursor(decalwrite+2*longblock+decalnearblock+decalotherblock,4);
        lcd.drawBitmap(skulll,7,1);
    }
    lcd.setCursor(((i/10)-1)*8+3,5);
    lcd.drawBitmap(block,6,1);
  }
  delay(10000);
  lcd.clear();
}
}
