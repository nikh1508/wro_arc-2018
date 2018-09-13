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
        while (ch != 's')
          rotateTo(angle[index][motion], rotate_direction[index][motion]);
        motion++;
        break;
      }
    case (4): {////line_stop_prependicular
        digitalWrite(sqc_pin, LOW);
        reset_feedback();
        if (direction[index][motion] > 0) //right
          right_value();
        else //left
          left_value();
        while (ch != 's')
          line_stop_prependicular();
        motion++;
        break;
      }
    case (5): {//sideways
        digitalWrite(sqc_pin, LOW);
        reset_feedback();
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
