
#define dig_control 8
#define output_circuit 9

int comp = 0; // valor lido no comparador
  
void setup() {
  
    DDRD = 0xFF;                      // DDRD setado como modo de saída
    
    pinMode(dig_control, OUTPUT);     // configura o pino digital 8 como saída para controle digital
    pinMode(output_circuit, INPUT);   // configura o pino digital 9 como entrada do output do circuito

    Serial.begin(9600);               // Serial 9600 Baudrate
  
    PORTD = 0x00;                     // PORTD inicialmente zerado
}
  
void loop() {    
    // Entrada do DAC
    unsigned char i;
    PORTD = B10000000;                // 
    
    //Ativa o sample Hold
    digitalWrite(13, HIGH); // ativa o pino digital 13
    delay(0.001);
    
    //Lendo a saida do comparador:
    comp = digitalRead(inpin); // lê o pino de saida do comparador
    Serial.println(comp);
    digitalWrite(13, LOW); // desativa o pino digital 13
    
}
