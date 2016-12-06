#include <TimerOne.h>

#define clock  0
#define data   1
#define latch  2
#define butt   7

#define index  B00110000
#define middle B00001100

volatile unsigned char stream[10];
volatile unsigned char counter = 0;
volatile unsigned char controller = 0;

volatile unsigned char notProgrammed = 1;

unsigned char frame[10];
unsigned char program[10];

byte left = 0;            //Mouse buttons
byte lastLeft = 0;
byte right = 0;
byte lastRight = 0;

signed char xPos = 0;
signed char yPos = 0;

#define xDiv  8
#define yDiv  16

void setup(void) {

  DDRB |= (1 << clock);      //Clock  
  DDRB &= ~(1 << data);     //Data 
  DDRB |= (1 << latch);      //Latch 

  DDRF = 0;    //Program

  Timer1.initialize(040000);
  Timer1.attachInterrupt(getData); // blinkLED to run every 0.15 seconds
  Serial.begin(9600);
  
}

void loop(void) {

  if ((PINF & (1 << butt)) == 0) {
    
    while ((PINF & (1 << butt)) == 0) {
      delay(1); 
    } 
    
    switch(notProgrammed) {
    
      case 1:
        programGlove();
      break;
      case 0:
        Serial.println("MOUSE DISABLED");
        notProgrammed = 10;
      break;
      case 10:
        Serial.println("MOUSE ENABLED");
        notProgrammed = 0;
      break;      

    }    
  }
  
  noInterrupts();
  for (int x = 1 ; x < 6 ; x++) {
    frame[x] = stream[x];  
  }
  interrupts();

  lastLeft = left;
  lastRight = right;

  if (frame[5] & index) {
    left = 1;  
  }
  else {
    left = 0;  
  }
  if (frame[5] & middle) {
    right = 1;  
  }
  else {
    right = 0;  
  }

  if (frame[1] < 128) {
    xPos =  frame[1] / xDiv;          //Positive movement RIGHT 0-127 
  }
  else {
    xPos = (frame[1] - 255) / xDiv;     //Negative movement LEFT 255-128   
  }
  
  if (frame[2] > 127) {
    yPos =  (255 - frame[2]) / yDiv;    //Negative movement DOWN 255-127 
  }
  else {
    yPos = (frame[2] / yDiv) * -1;     //Negative movement 255-128   
  }   

  if (notProgrammed == 0) {
    
    if (lastLeft != left or lastRight != right) {  
      Mouse.set_buttons(left, 0, right);        
    }

    Mouse.move(xPos, yPos);    
    Serial.print(xPos);
    Serial.print("\t");   
    Serial.println(yPos);
  
  }

  delay(10);                  //Put in a little lag

}

void tester() {

  for (int x = 1 ; x < 5 ; x++) {
    Serial.print(frame[x]);
    Serial.print("\t");  
  }
  
  Serial.println(frame[5], BIN);

  Serial.println("");
  delay(100);  
  
}


void getData(void) {

  PORTB |= (1 << latch);
  delayMicroseconds(4);  
  PORTB &= ~(1 << latch);    

  stream[0] = 0;

  for (int x = 0 ; x < 8 ; x++) {

    stream[0] <<= 1;

    if (PINB & (1 << data)) {
      stream[0] |= 1;
    }
    
    PORTB &= ~(1 << clock);        //Pulse the clock
    delayMicroseconds(2);    
    PORTB |= (1 << clock);

    delayMicroseconds(15);

  }

  if (notProgrammed) {    
    return;      
  }
  
  counter += 1;
  
  if (counter == 17) {

    counter = 14;

    delayMicroseconds(90);
  
    for (int b = 1 ; b < 10 ; b++) {
 
      PORTB |= (1 << latch);
      delayMicroseconds(4);  
      PORTB &= ~(1 << latch); 
    
      stream[b] = 0;
    
      for (int x = 0 ; x < 8 ; x++) {
    
        stream[b] <<= 1;
    
        if (PINB & (1 << data)) {
          stream[b] |= 1;
        }
        
        PORTB &= ~(1 << clock);        //Pulse the clock
        delayMicroseconds(2);    
        PORTB |= (1 << clock);
    
        delayMicroseconds(8);
    
      }   
   
      delayMicroseconds(80);
      
    }
    
  } 
 
}

void programGlove() {

  program[0] = B00000110;
  program[1] = B11000001;  
  program[2] = B00001000;
  program[3] = B00000000;
  program[4] = B00000010;  
  program[5] = B11111111;
  program[6] = B00000001;  
  
  Serial.println("PROGRAMMING..."); 

  noInterrupts();  
  
  PORTB |= (1 << latch);            //Set latch HIGH for a while...

  delayMicroseconds(1800);          //...Tells it Program Mode
  
  for (int b = 0 ; b < 7 ; b++) {   //Send 6 bytes (we think)

    for (int x = 0 ; x < 8 ; x++) {  //Send 8 bits

      if (program[b] & B10000000) {    //Set the bit
        PORTB |= (1 << latch);  
      }
      else {
        PORTB &= ~(1 << latch);        
      }

      PORTB &= ~(1 << clock);        //Pulse the clock
      delayMicroseconds(2);    
      PORTB |= (1 << clock);
  
      delayMicroseconds(10); 
      
      program[b] <<= 1;              //Shift to next bit
      
    }
    
    delayMicroseconds(730);

  }
    
  PORTB &= ~(1 << latch);

  notProgrammed = 0;
  
  interrupts();
    
}

