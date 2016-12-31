void setup()
{
  pinMode(9, OUTPUT);   // sets the pin as output
  // analogWrite(9, 255);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
  //pinMode(13, OUTPUT);   
  randomSeed(analogRead(0));
}

void loop() {
  long randNumber;
  int i;
  
  digitalWrite(9,HIGH);
  delay(250);
  //analogWrite(9, 40);   // set the LED on 
  
  while(true)
  {
    // print a random number from 0 to 299
    randNumber = random(50, 60 );  // was 50-60, 10 times
  
    for(int i = 0; i < 5; i++ )
    {
      digitalWrite(9,HIGH);
      delay(random(100, 200 ));
       
      digitalWrite(9,LOW);
      delay(random(200, 250 ));
    }
    
    digitalWrite(9,LOW);
    delay(random(8000, 10 000 ));
    //randNumber = random(2000, 3000 );
    //digitalWrite(9,LOW);
    //delay(randNumber);
  }
  
  
}

//setPwmFrequency(9, 8);

// Set pin 6's PWM frequency to 62500 Hz (62500/1 = 62500)
// Note that the base frequency for pins 5 and 6 is 62500 Hz
//setPwmFrequency(6, 1);

// Set pin 10's PWM frequency to 31 Hz (31250/1024 = 31)
//setPwmFrequency(10, 1024);
//Please keep in mind that changing the PWM frequency changes the Atmega's timers and disrupts the normal operation of many functions that rely on time (delay(), millis(), Servo library).
/**
 * Divides a given PWM pin frequency by a divisor.
 * 
 * The resulting frequency is equal to the base frequency divided by
 * the given divisor:
 *   - Base frequencies:
 *      o The base frequency for pins 3, 9, 10, and 11 is 31250 Hz.
 *      o The base frequency for pins 5 and 6 is 62500 Hz.
 *   - Divisors:
 *      o The divisors available on pins 5, 6, 9 and 10 are: 1, 8, 64,
 *        256, and 1024.
 *      o The divisors available on pins 3 and 11 are: 1, 8, 32, 64,
 *        128, 256, and 1024.
 * 
 * PWM frequencies are tied together in pairs of pins. If one in a
 * pair is changed, the other is also changed to match:
 *   - Pins 5 and 6 are paired.
 *   - Pins 9 and 10 are paired.
 *   - Pins 3 and 11 are paired.
 * 
 * Note that this function will have side effects on anything else
 * that uses timers:
 *   - Changes on pins 3, 5, 6, or 11 may cause the delay() and
 *     millis() functions to stop working. Other timing-related
 *     functions may also be affected.
 *   - Changes on pins 9 or 10 will cause the Servo library to function
 *     incorrectly.
 * 
 * Thanks to macegr of the Arduino forums for his documentation of the
 * PWM frequency divisors. His post can be viewed at:
 *   http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1235060559/0#4
 */
/*void setPwmFrequency(int pin, int divisor) {
  byte mode;
  if(pin == 5 || pin == 6 || pin == 9 || pin == 10) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 64: mode = 0x03; break;
      case 256: mode = 0x04; break;
      case 1024: mode = 0x05; break;
      default: return;
    }
    if(pin == 5 || pin == 6) {
      TCCR0B = TCCR0B & 0b11111000 | mode;
    } else {
      TCCR1B = TCCR1B & 0b11111000 | mode;
    }
  } else if(pin == 3 || pin == 11) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 32: mode = 0x03; break;
      case 64: mode = 0x04; break;
      case 128: mode = 0x05; break;
      case 256: mode = 0x06; break;
      case 1024: mode = 0x7; break;
      default: return;
    }
    TCCR2B = TCCR2B & 0b11111000 | mode;
  }
}*/

