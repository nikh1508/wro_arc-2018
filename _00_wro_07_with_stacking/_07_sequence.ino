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
          line_stop_prependicular(angle[index][motion], direction[index][motion]);
        motion++;
        break;
      }
    case (5): {//sideways
        digitalWrite(sqc_pin, LOW);
        reset_feedback();
        sideways(direction[index][motion], steps[index][motion], angle[index][motion]);
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
    //
    case (7): {
        digitalWrite(sqc_pin, LOW);
        reset_feedback();
        dump_error();
        motion++;
        break;
      }
    //
    case (8): {
        digitalWrite(sqc_pin, LOW);
        reset_feedback();
        red__orange_dblue();
        dump_error(800, 800, 270.0, 0);
        motion++;
        break;
      }
    //
    case (9): {
        digitalWrite(sqc_pin, LOW);
        reset_feedback();
        orange_dblue();
        dump_error(800, 1100, 270.0, 0);
        motion++;
        break;
      }
    //
    case (10): {
        digitalWrite(sqc_pin, LOW);
        reset_feedback();
        green__orange_dblue();
        dump_error(800, 1100, 270.0, 0);
        motion++;
        break;
      }
    //
    case (11): {
        digitalWrite(sqc_pin, LOW);
        reset_feedback();
        second_red___orange_dblue();
        dump_error(800, 800, 270.0, 0);
        motion++;
        break;
      }
    //
    case (12): {
        digitalWrite(sqc_pin, LOW);
        reset_feedback();
        second_green__orange_dblue();
        dump_error(800, 1100, 270.0, 0);
        motion++;
        break;
      }
    //
    case (13): {
        digitalWrite(sqc_pin, LOW);
        reset_feedback();
        dblue_orange();
        dump_error(800, 800, 270.0, 0);
        motion++;
        break;
      }
    //
    case (14): {
        digitalWrite(sqc_pin, LOW);
        reset_feedback();
        red__orange_dblue();
        dump_error(800, 800, 270.0, 0);
        motion++;
        break;
      }
    //
    case (15): {
        digitalWrite(sqc_pin, LOW);
        reset_feedback();
        green__orange_dblue();
        dump_error(800, 1100, 270.0, 0);
        motion++;
        break;
      }
    //
    case (16): {
        digitalWrite(sqc_pin, LOW);
        reset_feedback();
        second_red___orange_dblue();
        dump_error(800, 800, 270.0, 0);
        motion++;
        break;
      }
    //
    case (17): {
        digitalWrite(sqc_pin, LOW);
        reset_feedback();
        second_green__orange_dblue();
        dump_error(800, 1100, 270.0, 0);
        motion++;
        break;
      }
    case (100): {
        digitalWrite(sqc_pin, LOW);
        reset_feedback();
        dump_error(800, 800, 0.0, 1);
        motion++;
        break;
      }
    //
    case (0): {
        stop();
        digitalWrite(sqc_pin, HIGH);
        reset_feedback();
        break;
      }
    default: {
        break;
      }
  }
}
