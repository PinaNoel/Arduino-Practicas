float tempC; // Variable para almacenar el valor obtenido del sensor (0 a 1023)
int pinLM35 = 1; // Variable del pin de entrada del sensor (A0)
 
void setup() {

  Serial.begin(9600);
  pinMode(7 , OUTPUT);
 
}
 
void loop() {
  digitalWrite(7, HIGH);


  tempC = analogRead(pinLM35); 

  //tempC = (5.0 * tempC * 100.0)/1024.0; 
 
  // Envia el dato al puerto serial
  Serial.println(tempC);
  

  digitalWrite(7, LOW);
  delay(1000);
}
