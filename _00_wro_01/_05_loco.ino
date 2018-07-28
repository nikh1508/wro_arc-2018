void forward(int a, int b) {
  //0
  PORTB |= _BV(PB2);//high
  PORTL &= ~_BV(PL0);//low
  //1
  PORTA |= _BV(PA0);//high
  PORTA |= _BV(PA2);//high
  //2
  PORTG |= _BV(PG0);//high
  PORTL &= ~_BV(PL2);//low
  //
  analogWrite(2, a);
  analogWrite(4, b);
}
///
void backward(int a, int b) {
  //0
  PORTL |= _BV(PL0);//high
  PORTB &= ~_BV(PB2);//low
  //1
  PORTA |= _BV(PA0);//high
  PORTA |= _BV(PA2);//high
  //2
  PORTL |= _BV(PL2);//high
  PORTG &= ~_BV(PG0);//low
  //
  analogWrite(2, a);
  analogWrite(4, b);
}
////
void left(int x, int y, int z) {
  //0
  PORTB |= _BV(PB2);//high
  PORTL &= ~_BV(PL0);//low
  //1
  PORTA |= _BV(PA0);//high
  PORTA &= ~_BV(PA2);//low
  //2
  PORTL |= _BV(PL2);//high
  PORTG &= ~_BV(PG0);//low
  //
  analogWrite(2, x);
  analogWrite(4, y);
  analogWrite(3, z);
}
void right(int x, int y, int z) {
  //0
  PORTL |= _BV(PL0);//high
  PORTB &= ~_BV(PB2);//low
  //1
  PORTA |= _BV(PA2);//high
  PORTA &= ~_BV(PA0);//low
  //2
  PORTL |= _BV(PL2);//high
  PORTG &= ~_BV(PG0);//low
  //
  analogWrite(2, x);
  analogWrite(4, y);
  analogWrite(3, z);
}
void stop() {
  //0
  PORTB |= _BV(PB2);//high
  PORTL |= _BV(PL0);//high
  //1
  PORTA |= _BV(PA0);//high
  PORTA |= _BV(PA2);//high
  //2
  PORTG |= _BV(PG0);//high
  PORTL |= _BV(PL2);//high
  //
  analogWrite(2, 0);
  analogWrite(3, 0);
  analogWrite(4, 0);
}
//
void ccw() {
  if (yaw > (-90.0)) {
    //0
    PORTB |= _BV(PB2);//high
    PORTL &= ~_BV(PL0);//low
    //1
    PORTA |= _BV(PA2);//high
    PORTA &= ~_BV(PA0);//low
    //2
    //2
    PORTL |= _BV(PL2);//high
    PORTG &= ~_BV(PG0);//low
    //
    analogWrite(2, 200);
    analogWrite(3, 200);
    analogWrite(4, 200);
  }
  if (yaw <= -90.0) {
    ch = 's';
  }
}
//
void cw() {
  if (yaw < 90.0) {
    //0
    PORTL |= _BV(PL0);//high
    PORTB &= ~_BV(PB2);//low
    //1
    PORTA |= _BV(PA0);//high
    PORTA &= ~_BV(PA2);//low
    //2
    //2
    PORTG |= _BV(PG0);//high
    PORTL &= ~_BV(PL2);//low
    //
    analogWrite(2, 200);
    analogWrite(3, 200);
    analogWrite(4, 200);
  }
  if (yaw >= 90.0) {
    ch = 's';
  }
}
////////////////////////////////
////////////////////////////////
void move(char c) {
  switch (c) {
    case ('f'): {
        forward(pwm0, pwm2);
        break;
      }
    case ('b'): {
        backward(pwm0, pwm2);
        break;
      }
    case ('l'): {
        left(pwm0, pwm2, pwm1);
        break;
      }
    case ('r'): {
        right(pwm0, pwm2, pwm1);
        break;
      }
    case ('s'): {
        stop();
        break;
      }
    case ('q'): {
        ccw();
        break;
      }
    case ('e'): {
        cw();
        break;
      }
  }
}

