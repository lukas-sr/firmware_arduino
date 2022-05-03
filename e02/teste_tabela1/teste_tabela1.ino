#define MAX 27

void setup() {
  
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
  DDRD = 0b11111111;
}

void loop() {
  
  int vect[MAX] = {0b00000000, 0b00000001, 0b00000010, 0b00000011, 0b00000100, 0b00000101, 
                   0b00000110, 0b00000111, 0b00001000, 0b00001001, 0b00001010, 0b00001011, 
                   0b00001100, 0b00001101, 0b00001110, 0b00001111, 0b00010000, 0b00100000,
                   0b01000000, 0b10000000, 0b11000000, 0b11100000, 0b11110000, 0b11111000,
                   0b11111100, 0b11111110, 0b11111111};
       
  PORTD = 0b00000000;
  
  delay(1000);

  for (int i = 0; i < 27 ; i++){
      PORTD = vect[i];
      Serial.println(PORTD);
      delay(100);      
    }
}
