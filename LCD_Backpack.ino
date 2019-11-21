#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int buttonPin = 3; //arduino pin connected to button
int buttonState = 0;
int counter = 0;
int previousbuttonState = 0;


void setup()
{
	lcd.init();
	lcd.backlight();
	pinMode(buttonPin, INPUT);
	lcd.print("Button Presses:"); //What the lcd displays on the first line
	Serial.begin(9600);


}

void loop()
{
	buttonState = digitalRead(buttonPin); //Reads if button is being pushed
	lcd.setCursor(0, 1); // set the cursor to column 0, line 1
  	//lcd.print(millis() / 1000);   // print the number of seconds since reset:
 
  	if (buttonState == HIGH && previousbuttonState == LOW) //So it knows when to count
  	{
  		counter +=1; //counter goes up by one
  		lcd.print(counter); //lcd displays the counter
  	}
  	previousbuttonState = buttonState;
 
    //else statement not needed
 
  	Serial.print("");
  	Serial.println(counter); //Serial monitor prints the counter
  }
