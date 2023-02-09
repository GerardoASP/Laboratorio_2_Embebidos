byte pul1=2;
byte pul2=3;
byte led1=4;
byte led2=5;
byte led3=6;
byte led4=7;
byte giro_der=8;
byte giro_izq=9;
byte giro_der2=12;
byte giro_izq2=13;
#define trig 10
#define echo 11
float duracion, distancia;

void setup() {
  Serial.begin(9600);
  pinMode(pul1, INPUT);
  pinMode(pul2, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(giro_der, OUTPUT);
  pinMode(giro_izq, OUTPUT);
  pinMode(giro_der2, OUTPUT);
  pinMode(giro_izq2, OUTPUT);

}

void loop() {
    if(digitalRead(pul1)==HIGH)
    {
    digitalWrite(trig, HIGH);
    delayMicroseconds(1);
    digitalWrite(trig,LOW);
    duracion = pulseIn(echo, HIGH);
    distancia = duracion/58.2;
    delay(50);
    Serial.println(distancia);
    }
     if(digitalRead(pul1)==HIGH)
    {
    digitalWrite(giro_der, HIGH);
    digitalWrite(giro_izq, LOW);
    }
    else
    {
      digitalWrite(giro_der, LOW);
    digitalWrite(giro_izq, LOW);
    }
    if(digitalRead(pul2)==HIGH)
    {
    digitalWrite(giro_der2, HIGH);
    digitalWrite(giro_izq2, LOW);
    }
     else
    {
      digitalWrite(giro_der2, LOW);
    digitalWrite(giro_izq2, LOW);
    }
}
