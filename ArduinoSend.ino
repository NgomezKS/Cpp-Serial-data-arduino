#define Pecho 6
#define Ptrig 7
long duracion, distancia;   
 
void setup() {                
  Serial.begin (1200);       // Baudios 
  pinMode(Pecho, INPUT);     // define el pin 6 como entrada (echo)
  pinMode(Ptrig, OUTPUT);    // define el pin 7 como salida  (triger)
  

  }
  
void loop() {
  
  digitalWrite(Ptrig, LOW);
  delayMicroseconds(2);
  digitalWrite(Ptrig, HIGH);   // genera el pulso de triger por 10ms
  delayMicroseconds(10);
  digitalWrite(Ptrig, LOW);
  
  duracion = pulseIn(Pecho, HIGH);
  distancia = (duracion/2) / 29;            // calcula la distancia en centimetros  
  
  if (distancia >= 50 || distancia <= 0){  // si la distancia es mayor a 500cm o menor a 0cm     
                  
    Serial.println("00");         
    
  }
  else if (distancia < 10) {
    
    Serial.print(distancia);
    Serial.println("-");    
          
  } else {
    
    Serial.println(distancia);
    
  }
     delay(200);                               
}
