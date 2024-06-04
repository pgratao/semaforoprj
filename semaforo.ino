const int pinLed1R = 2;
const int pinLed1Y = 4;
const int pinLed1G = 5;
const int pinLed2R = 18;
const int pinLed2Y = 19;
const int pinLed2G = 21;

bool semaforo1 = true;
bool semaforo2 = false;

const int tempoamarelo = 2000;
const int tempoverde = 5000;

void setup() {
pinMode(pinLed1R, OUTPUT);
pinMode(pinLed1Y, OUTPUT);
pinMode(pinLed1G, OUTPUT);
pinMode(pinLed2R, OUTPUT);
pinMode(pinLed2Y, OUTPUT);
pinMode(pinLed2G, OUTPUT);
}

void loop() {
ligardesligar();
}

void ligardesligar(){
  if (semaforo2){
    diminuiLuz(pinLed2R);
    acendeLuz(pinLed1R);
    acendeLuz(pinLed2G);
    delay(tempoverde);
    diminuiLuz(pinLed2G);
    acendeLuz(pinLed2Y);
    delay(tempoamarelo);
    diminuiLuz(pinLed2Y);
    semaforo1 = true;
    diminuiLuz(pinLed1R); 
    acendeLuz(pinLed2R);
} else {
  acendeLuz(pinLed2R);
}if (semaforo1){
  acendeLuz(pinLed1G);
  delay(tempoverde);
  diminuiLuz(pinLed1G);
  acendeLuz(pinLed1Y);
  delay(tempoamarelo);
  diminuiLuz(pinLed1Y);
  semaforo1 = false;
  semaforo2 = true;
} else {
  acendeLuz(pinLed1G);
}
}
void acendeLuz(int p){
  digitalWrite(p, HIGH);
}

void diminuiLuz(int p){
  digitalWrite(p, LOW);
}
