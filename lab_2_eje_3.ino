byte pul1=2;
byte pul2=3;
byte pul3=A0;
byte pul4=A1;
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
boolean giro1=false;
boolean giro2=false;
float duracion, distancia;

void setup() {
  Serial.begin(9600);
  pinMode(pul1, INPUT);
  pinMode(pul2, INPUT);
  pinMode(pul3, INPUT);
  pinMode(pul4, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(giro_der, OUTPUT);
  pinMode(giro_izq, OUTPUT);
  pinMode(giro_der2, OUTPUT);
  pinMode(giro_izq2, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
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
      if(giro1)
      {
    digitalWrite(giro_der, HIGH);
    digitalWrite(giro_izq, LOW);
      }
      else
      {
        digitalWrite(giro_der, LOW);
    digitalWrite(giro_izq, HIGH);
      }
    }
    else
    {
      digitalWrite(giro_der, LOW);
    digitalWrite(giro_izq, LOW);
    }
    if(digitalRead(pul2)==HIGH)
    {
      if(giro2)
      {
    digitalWrite(giro_der2, HIGH);
    digitalWrite(giro_izq2, LOW);
      }
      else
      {
        digitalWrite(giro_der2, LOW);
    digitalWrite(giro_izq2, HIGH);
      }
    }
     else
    {
      digitalWrite(giro_der2, LOW);
    digitalWrite(giro_izq2, LOW);
    }
    if(digitalRead(pul3)!=LOW)
    {
      
      if(giro1)
        giro1=false;
      else
        giro1=true;
      delayMicroseconds(50);
    }
    if(digitalRead(pul4)!=LOW)
    {
      if(giro2)
        giro2 = false;
      else
        giro2 = true;
      delayMicroseconds(50);
    }

    if(!giro1)
    {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
    }
    else
    {
      digitalWrite(led2, HIGH);
      digitalWrite(led1, LOW);
    }
    if(!giro2)
    {
      digitalWrite(led3, HIGH);
      digitalWrite(led4, LOW);
    }
    else
    {
      digitalWrite(led4, HIGH);
      digitalWrite(led3, LOW);
    }
    
    
}
