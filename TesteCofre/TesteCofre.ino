#include <Servo.h>

const int pinServo = 2;
const int pinBotao = 3;
const int pinLED1 = 4;
const int pinLED2 = 5;
const int pinSensor = 6;
const int pinPot = A0;

Servo trava;

void setup ()
{
  Serial.begin(9600);
  Serial.println("Teste Cofre");
  pinMode(pinBotao, INPUT);
  digitalWrite(pinBotao, HIGH);
  pinMode(pinLED1, OUTPUT);
  pinMode(pinLED2, OUTPUT);
  pinMode(pinSensor, INPUT);
  digitalWrite(pinSensor, HIGH);
}

void loop ()
{
  Serial.println("1: Botao");
  Serial.println("2: LED");
  Serial.println("3: Servo");
  Serial.println("4: Sensor");
  Serial.println("5: Potenciometro");
  int opc;
  do
  {
    opc = Serial.read();
  } while (opc == -1);
  switch (opc)
  {
    case '1':
      testeBotao();
      break;
    case '2':
      testeLed();
      break;
    case '3':
      testeServo();
      break;
    case '4':
      testeSensor();
      break;
    case '5':
      testePot();
      break;
  }
}

void testeBotao()
{
  int botaoAnt = digitalRead(pinBotao);
  int botao;
  Serial.println ("Teste Botao");
  while (Serial.available() == 0)
  {
    botao = digitalRead(pinBotao);
    if (botao != botaoAnt)
    {
      if (botao == HIGH)
      {
        Serial.println ("Botao solto");
      }
      else
      {
        Serial.println ("Botao apertado");
      }
      botaoAnt = botao;
      delay(200);
    }
  }
  Serial.read();
  Serial.println ();
}

void testeLed()
{
  Serial.println ("Teste LED");
  while (Serial.available() == 0)
  {
    digitalWrite (pinLED1, HIGH);
    delay (500);
    digitalWrite (pinLED2, HIGH);
    delay (500);
    digitalWrite (pinLED1, LOW);
    delay (500);
    digitalWrite (pinLED2, LOW);
    delay (500);
  }
  Serial.read();
  Serial.println ();
}

void testeServo()
{
  Serial.println ("Teste Servo");
  trava.attach(pinServo);
  while (Serial.available() == 0)
  {
    trava.write(1);
    delay (2000);    
    trava.write(90);
    delay (2000);    
  }
  trava.detach();
  Serial.read();
  Serial.println ();
}

void testeSensor()
{
  int sensorAnt = digitalRead(pinSensor);
  int sensor;
  Serial.println ("Teste sensor");
  while (Serial.available() == 0)
  {
    sensor = digitalRead(pinSensor);
    if (sensor != sensorAnt)
    {
      if (sensor == HIGH)
      {
        Serial.println ("tampa aberta");
      }
      else
      {
        Serial.println ("tampa fechada");
      }
      sensorAnt = sensor;
      delay(200);
    }
  }
  Serial.read();
  Serial.println ();
}

void testePot()
{
  Serial.println ("Teste Potenciometro");
  while (Serial.available() == 0)
  {
    Serial.println(analogRead(pinPot));
    delay(1000);
  }
  Serial.read();
  Serial.println ();
}

