#include <LedControl.h>



#include <Wire.h>
#include <hd44780.h>                       // main hd44780 header
#include <hd44780ioClass/hd44780_I2Cexp.h> // i2c expander i/o class header

hd44780_I2Cexp lcd; // declare lcd object: auto locate & auto config expander chip

int on;


long duration;


int DIN = 10; int CS = 9; int CLK = 8;


byte smile1[8]= {0x3C,0x42,0x95,0xA1,0xA1,0x95,0x42,0x3C};

byte sad1[8]= {0x3C,0x42,0xA5,0x91,0x91,0xA5,0x42,0x3C};

byte heart[8]={0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,};
    byte smile[8]=   {0x04,0x08,0x00,0x00,0x00,0x00,0x00,0x00};
    byte neutral[8]= {0x06,0x08,0x00,0x00,0x00,0x00,0x00,0x00,};
    byte sad[8]=   {0x06,0x09,0x00,0x00,0x00,0x00,0x00,0x00,};
    byte m[8]={0x06,0x09,0x01,0x00,0x00,0x00,0x00,0x00,};
    byte n[8]={0x06,0x09,0x01,0x01,0x00,0x00,0x00,0x00,};
    byte o [8]={0x06,0x09,0x01,0x01,0x02,0x00,0x00,0x00,};
    byte p [8]={0x06,0x09,0x01,0x01,0x02,0x04,0x00,0x00,};
      byte q [8]={0x06,0x09,0x01,0x01,0x02,0x04,0x08,0x00,};
        byte r [8]={0x06,0x09,0x01,0x01,0x02,0x04,0x18,0x00,};
          byte s [8]={0x06,0x09,0x01,0x01,0x02,0x24,0x18,0x00,};
            byte t [8]={0x06,0x09,0x01,0x01,0x42,0x24,0x18,0x00,};
              
byte u [8]={0x06,0x09,0x01,0x81,0x42,0x24,0x18,0x00,};
  byte v [8]={0x06,0x09,0x81,0x81,0x42,0x24,0x18,0x00,};
    byte w  [8]={0x06,0x89,0x81,0x81,0x42,0x24,0x18,0x00,};
      byte x [8]={0x46,0x89,0x81,0x81,0x42,0x24,0x18,0x00,};
        byte y [8]={0x66,0x89,0x81,0x81,0x42,0x24,0x18,0x00,};
        byte z [8]={0x66,0x99,0x81,0x81,0x42,0x24,0x18,0x00,};
     byte aa [8] ={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
       byte bb [8]={0x66,0xFF,0xFF,0xFF,0x7E,0x3C,0x18,0x00,};
    byte cc [8] = {0x0E,0x0A,0x12,0x1E,0x22,0x22,0x42,0xE7,};


LedControl lc=LedControl(DIN,CLK,CS,0);

// LCD geometry
const int LCD_COLS = 16;
const int LCD_ROWS = 2;

int button1Pin=2;
int button2Pin=3;
int button1Value;
int button2Value;
int dt=100;

int a = 60;

void setup()
{

  
int status;


	status = lcd.begin(LCD_COLS, LCD_ROWS);
	if(status) // non zero status means it was unsuccesful
	{
		// hd44780 has a fatalError() routine that blinks an led if possible
		// begin() failed so blink error code using the onboard LED if possible
		hd44780::fatalError(status); // does not return
	}

	// Print a message to the LCD
	


Serial.begin(9600); // Starts the serial communication

lc.shutdown(0,false); //The MAX72XX is in power-saving mode on startup

lc.setIntensity(0,15); // Set the brightness to maximum value

lc.clearDisplay(0); // and clear the display


Serial.println("Enter choice");
on=Serial.read();

pinMode(button1Pin,INPUT);
pinMode(button2Pin,INPUT);
digitalWrite(button1Pin,HIGH);
digitalWrite(button2Pin,HIGH);

}

void loop() {
   lcd.setCursor(0, 0);
 lcd.print("BE MY VALENTINE?");
 lcd.setCursor(0, 1);
 lcd.print("1 = YES / 2 = NO ");

     


  button1Value=digitalRead(button1Pin);
  button2Value=digitalRead(button2Pin);



   if (button2Value==0)
  {
    Serial.print("Your Button 2 is: ");
  Serial.println(button2Value);
    { lcd.clear();
  lcd.setCursor(0, 0);
  	lcd.print("NO WORRIES,I RES");
 lcd.setCursor(0, 1);
 lcd.print("PECT YOUR CHOICE");
  delay(1000);}
  lc.clearDisplay(0); // and clear the display
    int i = 0;
 for(i=0;i<8;i++) { 
    lc.setRow(0,i,smile1[i]);
     }
     delay(800);
  for(i=0;i<8;i++) { 
    lc.setRow(0,i,sad1[i]);
     }  delay(6000);
  }//END OF REJECTION

  if (button1Value==0)
{Serial.print("Your Button 1 is: ");
  Serial.println(button1Value);
 { lcd.clear();
  lcd.setCursor(1, 0);
  	lcd.print(" SEE YOU AT 6 ");
 lcd.setCursor(3, 1);
 lcd.print("   XOXO   ");
  delay(1000);}
     printByte(heart);
    
    delay(a);
      
    printByte(smile);
     
    delay(a);

    printByte(neutral);
    
    delay(a);

    printByte(sad);    

    delay(a);
     printByte (m);
     delay(a);

     printByte(n);
     delay(a);

     printByte (o);
     delay(a);

     printByte(p);
     delay(a);
     
     printByte (q);
     delay(a);

     printByte(r);
     delay(a);
  
     printByte (s);
     delay(a);

     printByte(t);
     delay(a);
     
     printByte (u);
     delay(a);

     printByte(v);
     delay(a);
      printByte(w);
     delay(a);
      printByte(x);
     delay(a);
      printByte(y);
     delay(a);
      printByte(z);
     delay(a);
    
     printByte(aa);
     delay(500);
      printByte(z);
     delay(a);
     delay(500);
     printByte(aa);
     delay(500);
      printByte(z);
     delay(a);
     delay(500);
     printByte(aa);
     delay(500);
      printByte(bb);
      delay(500);
       printByte(aa);
      delay(500);
       printByte(bb);
      
      delay(6000);



  
  }
}

void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}

  

  
 