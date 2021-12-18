int redLed = 11; // Led 11
int blueLed = 10; // Led 10
int greenLed = 9; // Led 9
int forcePin = A1; // A1 Analog1 Lectura de Presión
int forceValue=0;     //  Presión

 int fuerzaBrillo=0;     //  Presión

void setup(void) {
   pinMode(forcePin, INPUT);
   pinMode(redLed, OUTPUT);
   pinMode(blueLed, OUTPUT);
   pinMode(greenLed, OUTPUT);
  Serial.begin(9600);   
}
 
void loop(void) {
  forceValue = analogRead(forcePin);
  Serial.println(forceValue);
  
 
  // we'll need to change the range from the analog reading (0-1023) down to the range
  // used by analogWrite (0-255) with map!
  fuerzaBrillo = map(forceValue, 0, 1024, 0, 125);
  // LED gets brighter the harder you press
  if(fuerzaBrillo> 40){
  analogWrite(redLed,250);
    
  analogWrite(blueLed,0);
    
  analogWrite(greenLed,0);
  }else{
   analogWrite(redLed,0);
    
  analogWrite(blueLed,0);
    
  analogWrite(greenLed,0);
  };
   Serial.println(forceValue);
 
  delay(200);
}
