int led = 13; // Definiendo los pines)
int leda = 12;
int ledr = 11;
int trigger = 9;
int echo = 8;
float tiempo_espera,distancia;

void setup() {
Serial.begin(9600);
pinMode(trigger,OUTPUT); // Activa el sensor
pinMode(echo, INPUT); // Echo recibe los datos de la cercania
pinMode(led, OUTPUT);
pinMode(ledr, OUTPUT);
pinMode(leda, OUTPUT);
}

void loop() {
 digitalWrite(trigger, LOW); // Se le envia pulsos al sensor de movimiento para su activación
 delayMicroseconds(2);
 digitalWrite(trigger, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger, LOW);
 
 tiempo_espera = pulseIn(echo, HIGH);

  distancia = (tiempo_espera/2)/29,15; // Se coloca la medida a CM.


 Serial.println(distancia);
 delay(100); // Para evitar recibir datos demasiado rápido

  if (distancia< 60){   // Iluminación de los leds según distancia
    digitalWrite(led, HIGH);
  } else{
    digitalWrite(led, LOW);
  }

  if (distancia< 40){
  digitalWrite(leda, HIGH);
  }
  else{
    digitalWrite(leda, LOW);

  }
  if(distancia< 20){
    digitalWrite(ledr,HIGH);
  }
  else{
    digitalWrite(ledr,LOW);
  }
}
