void setup() {
 timer1_pwm_init();
 
// Serial.begin(9600);
}

void timer1_pwm_init() // Udkommenter de linjer, der ikke skal bruges
{

 TCCR1A = 0; // clear først alle tællerens styrebit
 TCCR1B = 0; // Vælg wave generation mode, WGM1(3 - 0) for timer1
 bitSet(TCCR1B, 4); // Mode 15 = 1111, Fast PWM til OCR1A
 bitSet(TCCR1B, 3); // Mode 14 = 1110, Fast PWM til ICR1
 bitSet(TCCR1A, 1);
 bitSet(TCCR1A, 0);

// Vælg hvad skal ske på pin 9 ved Compare-A match, ( OC1A )
// bitSet(TCCR1A, 7); // set bit COM1A1, COM1A0. Top = OCR1A i mode 15
// bitSet(TCCR1A, 6); // 00 = none, 01 = Toggle, 10=Clear, 11=Set

   bitSet(TCCR1A, 5); // og pin 10, Compare-B match, ( OC1B )
 // bitSet(TCCR1A, 4); // 00 = none, 01 = Toggle, 10=Clear, 11=Set
 // 10=Clear hvis tæller = compareværdi. 11=modsat fase
 
// vælg Prescaler
// bitSet(TCCR1B,2); // 000=stop, 001=/1, 010 =/8, 011=/64,
 bitSet(TCCR1B,1); // 100=/256, 101=/1024, 110 & 111= ext pin
// bitSet(TCCR1B,0);
// vælg Compareværdi for
 OCR1B = 1000;
 OCR1A = 20000; // Top i mode 15
// enable pin som output:
 pinMode (10, OUTPUT); // Compare-B-output
// pinMode (9, OUTPUT); // Compare-A-output
}


void loop() {

 for(int i = 20000; i > 0; i=i-1000){
  OCR1B = i;
  delay(100);
 }
 
/*OCR1B = 1000;
  delay(500);
  OCR1B = 19000;
  delay(500);
*/
}
