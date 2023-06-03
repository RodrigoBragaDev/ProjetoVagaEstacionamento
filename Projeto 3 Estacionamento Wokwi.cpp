#include <ESP32Servo.h>

int ledVermelho = 26;
int ledVerde = 33;
int botaoVerde = 23;
int botaoVermelho = 19;
int segA = 25;
int segB = 18;
int segC = 15;
int segD = 4;
int segE = 5;
int segF = 21;
int segG = 22;
int segP = 2;
int pinServoEsquerdo = 14;
int pinServoDireito = 27;
int pinTrig = 13;
int pinEcho = 12;
bool statusBtnVerde, statusAntVerde = HIGH;
bool statusBtnVermelho, statusAntVermelho = HIGH;
int cont = 0;


Servo servoDireito;
Servo servoEsquerdo;


void setup() {
  Serial.begin(115200);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(botaoVerde, INPUT_PULLUP);
  pinMode(botaoVermelho, INPUT_PULLUP);
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
  pinMode(segP, OUTPUT);
  servoEsquerdo.attach(pinServoEsquerdo);
  servoDireito.attach(pinServoDireito);
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
  servoDireito.write(0);
  servoEsquerdo.write(0);


  
}

void loop() {
  delay(10); 
  statusBtnVerde = digitalRead(botaoVerde);
  statusBtnVermelho = digitalRead(botaoVermelho);

  if (cont > 0){
    digitalWrite(pinTrig, HIGH);
    delayMicroseconds(10);
    digitalWrite(pinTrig, LOW);
    int duracao = pulseIn(pinEcho, HIGH);
    int distancia = duracao/58;
    if (distancia <= 300){
      digitalWrite(ledVermelho, HIGH);
      digitalWrite(ledVerde, LOW);
    } else {
      digitalWrite(ledVermelho, LOW);
      digitalWrite(ledVerde, HIGH);
    }
  } else {
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledVerde, HIGH);
  }

  if(statusBtnVerde == LOW && statusAntVerde== HIGH){
    if (cont == 9) {
      statusAntVerde = LOW;
    } else {
        cont++;
        statusAntVerde = LOW;
        abrirCancelaDireita();
        Serial.print("Contagem = ");
        Serial.println(cont);
    }
    
  }

  if(statusBtnVerde == HIGH && statusAntVerde== LOW){
    statusAntVerde = HIGH;
  }

  if(statusBtnVermelho == LOW && statusAntVermelho== HIGH){
     if (cont == 0) {
      statusAntVermelho = LOW;
    }else {
        cont--;
        statusAntVermelho = LOW;
        abrirCancelaEsquerda();
        Serial.print("Contagem = ");
        Serial.println(cont);
    }
  }

  if(statusBtnVermelho == HIGH && statusAntVermelho== LOW){
    statusAntVermelho = HIGH;
  }
   if(cont == 0){
    apagar();
    zero();
  }else if(cont == 1){
    apagar();
    one();
  }else if(cont == 2){
    apagar();
    two();
  }else if(cont == 3){
    apagar();
    three();
  }else if(cont == 4){
    apagar();
    four();
  }else if(cont == 5){
    apagar();
    five();
  }else if(cont == 6){
    apagar();
    six();
  }else if(cont == 7){
    apagar();
    seven();
  }else if(cont == 8){
    apagar();
    eight();
  }else if(cont == 9){
    apagar();
    nine();
  }
}


void apagar() {
  digitalWrite(segA, LOW);
  digitalWrite(segB, LOW);
  digitalWrite(segC, LOW);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, LOW);
  digitalWrite(segP, LOW);
}
void zero() {
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  
}

void one() {
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
}

void two() {
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segG, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);

}

void three() {
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segG, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segC, HIGH);
}

void four() {
  digitalWrite(segF, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segG, HIGH);
  digitalWrite(segC, HIGH);
}

void five() {
  digitalWrite(segA, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segC, HIGH);
}

void six() {
  digitalWrite(segA, HIGH);
  digitalWrite(segG, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
}

void seven() {
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
}

void eight() {
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
}

void nine() {
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
}

void abrirCancelaDireita() {
  for(int i = 0; i <= 90; i++) {
    servoDireito.write(i);
    delay(6);
  }
  delay(350);
  for(int i = 90; i >= 0; i--) {
    servoDireito.write(i);
    delay(6);
  }

}

void abrirCancelaEsquerda() {
  for(int i = 0; i <= 90; i++) {
    servoEsquerdo.write(i);
    delay(6);
  }
  delay(350);
  for(int i = 90; i >= 0; i--) {
    servoEsquerdo.write(i);
    delay(6);
    }
}