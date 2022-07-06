#define dig_control 8
#define output_circuit 9

void setup(){
     // Função para realizar o setup do arduino (roda uma única vez)
     pinMode(dig_control, OUTPUT);
     pinMode(output_circuit, INPUT);
     
     DDRD = 0xFF; // Condifura todo registrador da porta D como saída. 
     // Equivale a fazer pinMode(porta, OUTPUT) para porta = 1 a 8. 
     
     Serial.begin(9600);
     
     PORTD = 0x00; // Seta todo registrador D como saúda (OUTPUT)    
}

void loop() {
  // Função que roda na forma de loop infinito
  unsigned int iteracao = 1;
  int comparador;
  
  PORTD = B10000000;              // decimal 128, 2.5V  
  
  digitalWrite(dig_control, HIGH);
  delayMicroseconds(30);
  digitalWrite(dig_control, LOW);

  comparador = digitalRead(output_circuit);

  for( int it = 7 ; it >= 0 ; it-- ){ 
    
    PORTD = PORTD + 128/iteracao; 
    delayMicroseconds(40);
    comparador = digitalRead(output_circuit);
    
    iteracao *= 2;

    if (comparador == LOW){
      PORTD = PORTD - (128/iteracao);
    }

  }
}
