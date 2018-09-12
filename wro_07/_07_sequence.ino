void sequnece() {
  switch (action[index][motion]) {
    case (1): {
        digitalWrite(sqc_pin, LOW);
        reset_feedback();
        move(direction[index][motion], steps[index][motion], angle[index][motion]); //line sensor+encoder
        motion++;
        break;
      }
    case (2): {
        digitalWrite(sqc_pin, LOW);
        reset_feedback();
        move_encoder_only(direction[index][motion], steps[index][motion], angle[index][motion]);
        motion++;
        break;
      }

    case (3): {
        digitalWrite(sqc_pin, LOW);
        reset_feedback();
        
        motion++;
        break;
      }
    case (4): {
        digitalWrite(sqc_pin, LOW);
        reset_feedback();
        if (direction[index][motion] > 0) {//right
          digitalWrite(m[0].a, LOW);
          digitalWrite(m[0].b, HIGH);
          digitalWrite(m[1].a, HIGH);
          digitalWrite(m[1].b, LOW);
          digitalWrite(m[2].a, HIGH);
          digitalWrite(m[2].b, LOW);
          analogWrite(m[0].pwm_pin, 39);
          analogWrite(m[1].pwm_pin, 51);
          analogWrite(m[2].pwm_pin, 38);
        }
        else {//left
          digitalWrite(m[0].a, HIGH);
          digitalWrite(m[0].b, LOW);
          digitalWrite(m[1].a, LOW);
          digitalWrite(m[1].b, HIGH);
          digitalWrite(m[2].a, LOW);
          digitalWrite(m[2].b, HIGH);
          analogWrite(m[0].pwm_pin, 38);
          analogWrite(m[1].pwm_pin, 50);
          analogWrite(m[2].pwm_pin, 38);
        }
        while (ch != 's')
          line_stop_prependicular(direction[index][motion]);
        motion++;
        break;
      }
    case (5): {//sideways
        digitalWrite(sqc_pin, LOW);
        reset_feedback();
        if (direction[index][motion] > 0) {//right
          digitalWrite(m[0].a, LOW);
          digitalWrite(m[0].b, HIGH);
          digitalWrite(m[1].a, HIGH);
          digitalWrite(m[1].b, LOW);
          digitalWrite(m[2].a, HIGH);
          digitalWrite(m[2].b, LOW);
          analogWrite(m[0].pwm_pin, 39);
          analogWrite(m[1].pwm_pin, 51);
          analogWrite(m[2].pwm_pin, 38);
        }
        else {//left
          digitalWrite(m[0].a, HIGH);
          digitalWrite(m[0].b, LOW);
          digitalWrite(m[1].a, LOW);
          digitalWrite(m[1].b, HIGH);
          digitalWrite(m[2].a, LOW);
          digitalWrite(m[2].b, HIGH);
          analogWrite(m[0].pwm_pin, 38);
          analogWrite(m[1].pwm_pin, 50);
          analogWrite(m[2].pwm_pin, 38);
        }
        while (ch != 's')
          sideways(steps[index][motion]);
        motion++;
        break;
      }
    case (6): {///l298n---->>>clamping
        digitalWrite(sqc_pin, LOW);
        reset_feedback();
        clamp(steps[index][motion], angle[index][motion]);
        motion++;
        break;
      }
    case (0): {
        stop();
        digitalWrite(sqc_pin, HIGH);
        break;
      }
    default: {
        break;
      }
  }
}
