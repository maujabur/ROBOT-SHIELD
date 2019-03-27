/*
   Definições para uso com Robot Shield v0.3
   2019 Mau Jabur
   MauMaker.com

   CC BY SA NC 4.0
   https://creativecommons.org/licenses/by-nc-sa/4.0/deed.pt_BR
*/

////////////////////////////////////////////////////
// Servos
////////////////////////////////////////////////////
#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

const int SERVO1_PIN = 6;
const int SERVO2_PIN = 7;
const int SERVO3_PIN = 8;
const int SERVO4_PIN = 11;
const int SERVO5_PIN = 12;
const int SERVO6_PIN = 13;


////////////////////////////////////////////////////
// Potenciômetros
////////////////////////////////////////////////////

const int POT1 = A5;
const int POT2 = A4;
const int POT3 = A3;
const int POT4 = A2;
const int POT5 = A1;
const int POT6 = A0;


////////////////////////////////////////////////////
// Botões / Chaves / Sensores
////////////////////////////////////////////////////

const int IN_1 =  4; // entrada 1
const int IN_2 =  5; // entrada 2
// ligar a chave entre o pino amarelo (sinal)
// e o pino preto (GND)
// usamos o PULL UP do arduino

////////////////////////////////////////////////////
// Saídas a transistor:
////////////////////////////////////////////////////

const int OUT1 =  9; // saída 1
const int OUT2 = 10; // saída 2


////////////////////////////////////////////////////
void setup() {

  // Servos
  servo1.attach(SERVO1_PIN);
  servo2.attach(SERVO2_PIN);
  servo3.attach(SERVO3_PIN);
  servo4.attach(SERVO4_PIN);
  servo5.attach(SERVO5_PIN);
  servo6.attach(SERVO6_PIN);

  // Saídas a transistor:
  pinMode(OUT1, OUTPUT);
  pinMode(OUT2, OUTPUT);

  // Botoes
  pinMode(IN_1, INPUT_PULLUP);
  pinMode(IN_2, INPUT_PULLUP);
  // usam o resistor PULLUP interno do arduino

  // para a plotter serial
  Serial.begin(115200);
}

void loop() {
  // codigo exemplo

  // SERVOS E POTENCIOMETROS
  int leitura1 = map (
                   analogRead(POT1), // leitura analogiga
                   0, 1023, // limites da leitura
                   0, 180 // graus no servo
                 );
  servo1.write(leitura1);

  int leitura2 = map (
                   analogRead(POT2), // leitura analogiga
                   0, 1023, // limites da leitura
                   0, 180 // graus no servo
                 );
  servo2.write(leitura2);

  int leitura3 = map (
                   analogRead(POT3), // leitura analogiga
                   0, 1023, // limites da leitura
                   0, 180 // graus no servo
                 );
  servo3.write(leitura3);

  int leitura4 = map (
                   analogRead(POT4), // leitura analogiga
                   0, 1023, // limites da leitura
                   0, 180 // graus no servo
                 );
  servo4.write(leitura4);

  int leitura5 = map (
                   analogRead(POT5), // leitura analogiga
                   0, 1023, // limites da leitura
                   0, 180 // graus no servo
                 );
  servo5.write(leitura5);

  int leitura6 = map (
                   analogRead(POT6), // leitura analogiga
                   0, 1023, // limites da leitura
                   0, 180 // graus no servo
                 );
  servo6.write(leitura6);


  // BOTOES E MOTORES
  // botao 1 e out 1
  if (digitalRead(IN_1) == LOW) {
    digitalWrite(OUT1, HIGH);
  }
  else {
    digitalWrite(OUT1, LOW);
  }

  // botao 2 e out 2
  if (digitalRead(IN_2) == LOW) {
    digitalWrite(OUT2, HIGH);
  }
  else {
    digitalWrite(OUT2, LOW);
  }

  // para a plotter serial
  Serial.print (leitura1);
  Serial.print (",");
  Serial.print (leitura2);
  Serial.print (",");
  Serial.print (leitura3);
  Serial.print (",");
  Serial.print (leitura4);
  Serial.print (",");
  Serial.print (leitura5);
  Serial.print (",");
  Serial.print (leitura6);
  Serial.println ();

  // para o grafico não correr tão rápido
  delay(15);

}
