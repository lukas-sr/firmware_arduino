/*
==============================================================================
CONTADOR DE 8 BITS
Este código faz contagem binária através de 8 saídas digitais do Arduino Uno. 
==============================================================================
Por Lucas Ribeiro de Oliveira.
PED da disciplina EE641 - Lab. de eltrônica básica II
==============================================================================
*/
void setup() {
 // Função para realizar o setup do arduino (roda uma única vez)
 
 DDRD = B11111111; // Condifura todo registrador da porta D como saída. 
 // Equivale a fazer pinMode(porta, OUTPUT) para porta = 1 a 8. 
}

void loop() {
  // Função que roda na forma de loop infinito
  
  PORTD = B00000000; // Seta todo registrador D como saúda (OUTPUT)
  delay(3000);       // Delay inicial de 3s

  // Laço de repetição para fornecer o valor desejado na saída
  for (int i=0; i < 256; i++){
   PORTD = i; // Fornece o valor desejado no registrador PORTD 
   delay(1000); // Delay de 1s
  }
}
