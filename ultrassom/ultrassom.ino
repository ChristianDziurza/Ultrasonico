const int ledPin1 = 8;
const int ledPin2 = 9;
const int ledPin3 = 10;

const int trigPin = 5;
const int echoPin = 4;

long duracao;
int distancia;
void setup() {
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);

  Serial.begin(9600);
  
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin3,OUTPUT);

}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 

  duracao = pulseIn(echoPin, HIGH);
  distancia = duracao*0.034 /2;

  if(distancia > 10){
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin1,HIGH);
  }else if(distancia < 10 && distancia > 5 ){
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin2,HIGH);
  }else if(distancia <= 5){
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3,HIGH);
  }
  Serial.print(distancia);

  Serial.println(" cm");



}
