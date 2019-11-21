int blink = 9;
int analog = 9;
int value  = 0;


void setup() {
	Serial.begin(9600);
	pinMode(blink, OUTPUT);
	
}

void loop()
{

	for(int value = 0; value <=  255; value += 5) {
		analogWrite(blink, value);
		delay(30);
	for(int dash = 0; dash < value/10; dash++) {
		Serial.print("x");
	}
	Serial.println(value);
	}
	for (int value = 255; value >= 0; value -=5) {
		analogWrite(blink, value);
		delay(30);
		for(int dash = 0; dash < value/10; dash++) {
			Serial.print("x");
		}
		Serial.println(value);

	}

	
	} 

