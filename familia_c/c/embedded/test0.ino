void setup() {
    DDRD=DDRD|B00000001;//pinMode(0,OUTPUT)
     //DATA DIRECTION REGISTOR port D
     //registrii pe 8 biti
}

void loop() {
  PORTD=PORTD|1;//digitalWrite(0,HIGH)
  delay(1000);
  PORTD=PORTD&11111110;
  delay(1000);
}