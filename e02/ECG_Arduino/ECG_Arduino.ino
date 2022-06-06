#include "ECG_Arduino.h"

void setup(){
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  DDRD = B11111111;
  
}

void loop() {

  unsigned int c = Serial.parseInt();
  unsigned int tam = sizeof(v01)/sizeof(unsigned char);

  switch (c){
    case 1:
      print_vect(v01, tam);
      Serial.println("v01");
      break;

    case 2:
      print_vect(v02, tam);
      Serial.println("v02");
      break;
          
    case 3:
      print_vect(v03, tam);
      Serial.println("v03");
      break;
      
    case 4:
      print_vect(v04, tam);
      Serial.println("v04");
      break;
      
    case 5:
      print_vect(v05, tam);
      Serial.println("v05");
      break;
      
    case 6:
      print_vect(v06, tam);
      Serial.println("v06");
      break;
      
    case 7:
      print_vect(v07, tam);
      Serial.println("v07");
      break;
     
    case 8:
      print_vect(v08, tam);
      Serial.println("v08");
      break;
      
    case 9:
      print_vect(v09, tam);
      Serial.println("v09");
      break;
      
    case 10:
      print_vect(v10, tam);
      Serial.println("v10");
      break;
      
    case 11:
      print_vect(v11, tam);
      Serial.println("v11");
      break;
      
    case 12:
      print_vect(v12, tam);
      Serial.println("v12");
      break;
  }
}

void print_vect( unsigned char* v, unsigned char tam){

  //PORTD = B00000000;
  
  Serial.println(tam);

  for ( int i = 0 ; i < tam-1 ; i++){
    PORTD = v[i];
    Serial.println(v[i], HEX);
    delay(16);  
  }

}
