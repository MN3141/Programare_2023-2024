bool state=0;
void setup()
{
  	Serial.begin(9600);
	DDRD=DDRD& ~(1<<PIN7);
  	PORTD=PORTD|1;
}

void loop()
{
  state=PIND&(1<<PIN7);//<=>Serial.println(digitalRead(7))
  //folosim PIND pt citire si PORTB pt scriere
  Serial.println(state);
}