const int Trigger = 7;  
const int Echo = 8;

void setup() {

  Serial.begin(9600);
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);

  digitalWrite(Trigger, LOW);
}



void loop()

{

  long t; 
  long d; 

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10); 
  digitalWrite(Trigger, LOW);

  

  t = pulseIn(Echo, HIGH);

  d = t/59;     //escalamos el tiempo a una distancia en cm

  

  Serial.print("Distancia: ");
  Serial.print(d);
  Serial.print("cm");
  Serial.println();

  delay(1000);

}
