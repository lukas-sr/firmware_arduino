/*
==============================================================================
RAMPA DIGITAL DE 8 BITS
Este código faz um sinal de rampa através de 8 saídas digitais do Arduino Uno. 
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
  
  PORTD = B00000000; // Seta todo registrador D como saída (OUTPUT)
  delay(3000);       // Delay inicial de 3s
  
  // Vetor com os valores de saída desejados
  int vetor[] = {0, 1, 3, 7, 15, 31, 63, 127, 255}; 
  int tam = sizeof(vetor) / sizeof(int); // Obtém o tamanho do vetor
  
  PORTD = 0b00000010;
  
  // repetição para percorrer todo vetor
  for (int i=0; i < tam; i++){
    PORTD = vetor[i];  // Fornece o valor desejado no registrador PORTD, ge forma sequencial, a partir do incremente de i
    delay(1000); // Delay de 1s
  }
}
