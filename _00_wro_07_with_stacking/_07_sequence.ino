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
          line_stop_prependicular(angle[index][motion]);
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
        dump_error();
        motion++;
        break;
      }
    //
    case (8): {
        digitalWrite(sqc_pin, LOW);
        blue_orange();
        changeAngle();
        dump_error(800, 800, 270.0, 0);
        motion++;
        break;
      }
    //
    case (9): {
        digitalWrite(sqc_pin, LOW);
        blue_red();
        changeAngle();
        dump_error(800, 800, 270.0, 0);
        motion++;
        break;
      }
    //
    case (10): {
        digitalWrite(sqc_pin, LOW);
        blue_dblue____yellow_dblue();
        changeAngle();
        dump_error(800, 800, 270.0, 0);
        motion++;
        break;
      }
    //
    case (11): {
        digitalWrite(sqc_pin, LOW);
        yellow_orange();
        changeAngle();
        dump_error(800, 800, 270.0, 0);
        motion++;
        break;
      }
    //
    case (12): {
        digitalWrite(sqc_pin, LOW);
        blue_dblue____yellow_dblue();
        changeAngle();
        dump_error(800, 800, 270.0, 0);
        motion++;
        break;
      }
    //
    case (13): {
        digitalWrite(sqc_pin, LOW);
        orange_red____dblue_red();
        changeAngle();
        dump_error(800, 800, 270.0, 0);
        motion++;
        break;
      }
    //
    case (14): {
        digitalWrite(sqc_pin, LOW);
        green_red____orange_dblue();
        changeAngle();
        dump_error(800, 800, 270.0, 0);
        motion++;
        break;
      }
    //
    case (15): {
        digitalWrite(sqc_pin, LOW);
        orange_green____dblue_green();
        changeAngle();
        dump_error(800, 800, 270.0, 0);
        motion++;
        break;
      }
    //
    case (16): {
        digitalWrite(sqc_pin, LOW);
        red_green____dblue_orange();
        changeAngle();
        dump_error(800, 800, 270.0, 0);
        motion++;
        break;
      }
    //
    case (17): {
        digitalWrite(sqc_pin, LOW);
        orange_red____dblue_red();
        changeAngle();
        dump_error(800, 800, 270.0, 0);
        motion++;
        break;
      }
    //
    case (18): {
        digitalWrite(sqc_pin, LOW);
        orange_green____dblue_green();
        changeAngle();
        dump_error(800, 800, 270.0, 0);
        motion++;
        break;
      }
    //
    case (19): {
        digitalWrite(sqc_pin, LOW);
        green_red____orange_dblue();
        changeAngle();
        dump_error(800, 800, 270.0, 0);
        motion++;
        break;
      }
    //
    case (20): {
        digitalWrite(sqc_pin, LOW);
        green_blue_left();
        changeAngle();
        dump_error(800, 800, 270.0, 0);
        motion++;
        break;
      }
    //
    case (21): {
        digitalWrite(sqc_pin, LOW);
        green_blue_right();
        changeAngle();
        dump_error(800, 800, 270.0, 0);
        motion++;
        break;
      }
    //
    case (22): {
        digitalWrite(sqc_pin, LOW);
        red_green____dblue_orange();
        changeAngle();
        dump_error(800, 800, 270.0, 0);
        motion++;
        break;
      }
    //
    case (23): {
        digitalWrite(sqc_pin, LOW);
        green_blue_left();
        changeAngle();
        dump_error(800, 800, 270.0, 0);
        motion++;
        break;
      }
    //
    case (24): {
        digitalWrite(sqc_pin, LOW);
        green_blue_right();
        changeAngle();
        dump_error(800, 800, 270.0, 0);
        motion++;
        break;
      }
    //
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
