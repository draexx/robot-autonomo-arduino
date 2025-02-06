int MA1 = 13; //motor 1 adelante
int MA2 = 12; //motor 1 atras
int MA3 = 8; //motor 2 adelante
int MA4 = 7; //motor 2 atras
int ENA = 11; //motor 1 velocidad
int ENB = 6; //motor 2 velocidad
int triggerPin = 10; // Trigger del sensor ultrasonico
int echoPin = 9; // Echo del sensor ultrasonico
float tiempo; // tiempo que tarda en llegar el eco
float distancia; // distancia en cm
int VELOCIDAD_FULL = 255; // velocidad maxima
int valor = 0; // valor random
void setup() {
    // put your setup code here, to run once:
    randomSeed(analogRead(A0)); // semilla para el random
    Serial.begin(9600); // iniciar comunicacion serial
    pinMode(MA1, OUTPUT); //configura pin de salida
    pinMode(MA2, OUTPUT); //configura pin de salida
    pinMode(MA3, OUTPUT); //configura pin de salida
    pinMode(MA4, OUTPUT); //configura pin de salida
    pinMode(ENA, OUTPUT); //configura pin de salida
    pinMode(ENB, OUTPUT); //configura pin de salida
    pinMode(triggerPin, OUTPUT); //configura pin de salida
    pinMode(echoPin, INPUT); //configura pin de entrada
    Serial.println("Inicia Robot detector de Obstaculo"); //nombre
    Serial.println("Pedro Carranza Calderon"); //nombre
}
void adelante(){
    Serial.println("Adelante");//mensaje
    //motor 1 adelante
    digitalWrite(MA1, HIGH); //encender motor
    digitalWrite(MA2, LOW); //apagar motor
    analogWrite(ENA, VELOCIDAD_FULL); //velocidad
    //motor 2 adelante
    digitalWrite(MA3, HIGH); //encender motor
    digitalWrite(MA4, LOW); //apagar motor
    analogWrite(ENB, VELOCIDAD_FULL); //velocidad
}
void reposo(){
    Serial.println("Reposo");//mensaje
    //motor 1 reposo
    digitalWrite(MA1, LOW); //apagar motor
    digitalWrite(MA2, LOW); //apagar motor
    analogWrite(ENA, 0); //velocidad
    //motor 2 reposo
    digitalWrite(MA3, LOW); //apagar motor
    digitalWrite(MA4, LOW); //apagar motor
    analogWrite(ENB, 0); //velocidad
}
void atras(){
    Serial.println("Atras");//mensaje
    //motor 1 atras
    digitalWrite(MA1, LOW); //apagar motor
    digitalWrite(MA2, HIGH); //encender motor
    analogWrite(ENA, VELOCIDAD_FULL); //velocidad
    //motor 2 atras
    digitalWrite(MA3, LOW); //apagar motor
    digitalWrite(MA4, HIGH); //encender motor
    analogWrite(ENB, VELOCIDAD_FULL); //velocidad
}
void izquierda(){
    Serial.println("Izquierda"); //mensaje
    //motor 1 atras
    digitalWrite(MA1, LOW); //apagar motor
    digitalWrite(MA2, HIGH); //encender motor
    analogWrite(ENA, VELOCIDAD_FULL); //velocidad
    //motor 2 atras
    digitalWrite(MA3, HIGH); //encender motor
    digitalWrite(MA4, LOW); //apagar motor
    analogWrite(ENB, VELOCIDAD_FULL); //velocidad
}
void derecha(){
    Serial.println("Derecha"); //mensaje
    //motor 1 atras
    digitalWrite(MA1, HIGH); //encender motor
    digitalWrite(MA2, LOW); //apagar motor
    analogWrite(ENA, VELOCIDAD_FULL); //velocidad
    //motor 2 atras
    digitalWrite(MA3, LOW); //apagar motor
    digitalWrite(MA4, HIGH); //encender motor
    analogWrite(ENB, VELOCIDAD_FULL); //velocidad
}
void loop() {
  // put your main code here, to run repeatedly:
    digitalWrite(triggerPin, LOW); //envia pulso
    delayMicroseconds(2); //espera
    digitalWrite(triggerPin, HIGH); //envia pulso
    delayMicroseconds(10); //espera
    tiempo = pulseIn(echoPin,HIGH); //tiempo que tarda en llegar el eco
     //distancia en cm
    distancia = tiempo / 58.2;
    Serial.print("\t"); //tabulador
    Serial.println(distancia); //distancia

    adelante();//moverse
    delay(500);//espera

    if (distancia<50){ //si la distancia es menor a 50
    reposo(); //reposo
    delay(500); //espera
    valor = random(1,4); //valor random
    switch(valor){ //switch
        case 1: //caso 1
            atras(); //moverse
            delay(500); //espera
            break; //salir
        case 2:
            derecha();
            delay(500);
            break;
        case 3:
            izquierda();
            delay(500);
            break;
    }
    delay(500);//espera
    }
}