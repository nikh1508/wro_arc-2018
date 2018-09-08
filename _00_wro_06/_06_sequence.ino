void sequence() {
  switch (sqc) {
    case (1): {
        reset_feedback();
        if (encoder_0 <= 2000) {
          encoder_data();
          ch = 'f';
          lpf(highspeed);
          pid_yaw(360.0);
          move(ch);
        }
        if (encoder_0 > 2000) {
          ch = 'f';
          lpf(lowspeed);
          pid_yaw(360.0);
          move(ch);
          line_stop();
          if (ch == 's') {
            ch = 'r';
            rotate_desired = -270.0;
            move(ch);
            sqc = 2;
          }
        }
        break;
      }
    ////////////////////////////////////////
    case (2): {
        reset_feedback();
        if (encoder_0 <= 8000) {
          encoder_data();
          ch = 'f';
          lpf(highspeed);
          pid_yaw(270.0);
          move(ch);
        }
        if (encoder_0 > 8000) {
          ch = 'f';
          lpf(lowspeed);
          pid_yaw(270.0);
          move(ch);
          line_stop();
          if (ch == 's') {
            digitalWrite(sqc_pin, HIGH);
          }
        }
        break;
      }
    /////////////////////////////////////////////
    //////////////////------------->>>>>>>>>>>>no communication
    /////////////////////////////////////////
    case (3): {
        digitalWrite(sqc_pin, LOW);
        reset_feedback();
        ch = 'r';
        rotate_desired = -270.0;
        move(ch);
        sqc = 0;
        digitalWrite(sqc_pin, HIGH);
        flag_reset = true;
        break;
      }
    ///////////////////////////////////////////
    case (4): {
        digitalWrite(sqc_pin, LOW);
        reset_feedback();
        ch = 'r';
        rotate_desired = -225.0;
        move(ch);
        sqc = 0;
        digitalWrite(sqc_pin, HIGH);
        flag_reset = true;
        break;
      }
    ///////////////////////////////////////////
    case (5): {
        digitalWrite(sqc_pin, LOW);
        reset_feedback();
        ch = 'r';
        rotate_desired = -315.0;
        move(ch);
        sqc = 0;
        digitalWrite(sqc_pin, HIGH);
        flag_reset = true;
        break;
      }
    ///////////////////////////////////////////
    case (6): {
        digitalWrite(sqc_pin, LOW);
        reset_feedback();
        ch = 'r';
        rotate_desired = -360.0;
        move(ch);
        sqc = 0;
        digitalWrite(sqc_pin, HIGH);
        flag_reset = true;
        break;
      }
    case (180): {
        digitalWrite(sqc_pin, LOW);
        reset_feedback();
        ch = 'r';
        rotate_desired = 180.0;
        move(ch);
        sqc = 0;
        digitalWrite(sqc_pin, HIGH);
        flag_reset = true;
        break;
      }
    ///////////////////////////////////////////
    //////////////routines/////////////////
    //////////-------------------------------------------->>>>>short supply 1
    case (7): {
        digitalWrite(sqc_pin, LOW);
        reset_feedback();
        ch = 'r';
        rotate_desired = 180.0;
        move(ch);
        sqc = 8;
        flag_reset = true;
        break;
      }
    /////////////////////////////////
    case (8): {
        reset_feedback();
        if (encoder_0 <= 2000) {
          encoder_data();
          ch = 'f';
          lpf(highspeed);
          pid_yaw(180.0);
          move(ch);
        }
        if (encoder_0 > 1800) {
          encoder_data();//
          ch = 'f';
          lpf(lowspeed);
          pid_yaw(180.0);
          move(ch);
          if (encoder_0 >= 2000) {//
            l298n();
            line_stop_block();
            flag_reset = true;
            gripper_call();
            sqc = 9;
          }
        }
        break;
      }
    /////////////////////////////////
    case (9): {
        reset_feedback();
        if (encoder_0 > -2200) {
          encoder_data();
          ch = 'b';
          lpf(highspeed);
          pid_yaw(180.0);
          move(ch);
        }
        if (encoder_0 <= -2200) {
          ch = 'b';
          lpf(lowspeed);
          pid_yaw(180.0);
          move(ch);
          line_stop();
          if (ch == 's') {
            ch = 'r';
            rotate_desired = 270.0;
            move(ch);
            digitalWrite(sqc_pin, HIGH);//next instruction to reach stacking form
          }
        }
        break;
      }
    /////////////////////////////////
    //////////////////////////////------------------------>>>>>>>>>>>>>short supply-2
    case (10): {
        digitalWrite(sqc_pin, LOW);
        reset_feedback();
        encoder_data();///////////////////////change
        if (encoder_0 < 4000) {
          encoder_data();
          ch = 'f';
          lpf(highspeed);
          pid_yaw(90.0);
          move(ch);
        }
        if (encoder_0 >= 4000) {
          ch = 'f';
          lpf(lowspeed);
          pid_yaw(90.0);
          move(ch);
          line_stop();
          if (ch == 's') {
            ch = 'r';
            rotate_desired = 180.0;
            move(ch);
            sqc = 11;
          }
        }
        break;
      }
    /////////////////////////////////
    case (11): {
        reset_feedback();
        if (encoder_0 <= 1800) {
          encoder_data();
          ch = 'f';
          lpf(highspeed);
          pid_yaw(180.0);
          move(ch);
        }
        if (encoder_0 > 1800) {
          encoder_data();//
          ch = 'f';
          lpf(lowspeed);
          pid_yaw(180.0);
          move(ch);
          if (encoder_0 >= 2000) {//
            l298n();
            line_stop_block();
            flag_reset = true;
            gripper_call();
            sqc = 12;
          }
        }
        break;
      }
    /////////////////////////////////
    case (12): {
        reset_feedback();
        if (encoder_0 > -2000) {
          encoder_data();
          ch = 'b';
          lpf(highspeed);
          pid_yaw(180.0);
          move(ch);
        }
        if (encoder_0 <= -2000) {
          ch = 'b';
          lpf(lowspeed);
          pid_yaw(180.0);
          move(ch);
          line_stop();
          if (ch == 's') {
            ch = 'r';
            rotate_desired = 270.0;
            move(ch);
            sqc = 13;
          }
        }
        break;
      }
    //////////////////////////////////////
    case (13): {
        reset_feedback();
        if (encoder_0 <= 3800) {
          encoder_data();
          ch = 'f';
          lpf(highspeed);
          pid_yaw(270.0);
          move(ch);
        }
        if (encoder_0 > 3800) {
          ch = 'f';
          lpf(lowspeed);
          pid_yaw(270.0);
          move(ch);
          line_stop();
          digitalWrite(sqc_pin, HIGH);//next instruction to reach stacking form
        }
        break;
      }
    ////////////////////////////
    ////////////////////////////////////////////-------------->>>>>>>3rd position
    case (14): {
        digitalWrite(sqc_pin, LOW);//3^rd position
        reset_feedback();
        ch = 'r';
        rotate_desired = -360.0;
        move(ch);
        sqc = 15;
        flag_reset = true;
        break;
      }
    ///////////////////////////////////
    case (15): {
        reset_feedback();
        if (encoder_0 <= 3000) {
          encoder_data();
          ch = 'f';
          lpf(highspeed);
          pid_yaw(360.0);
          move(ch);
        }
        if (encoder_0 > 3000 && encoder_0 < 3200) {
          encoder_data();
          ch = 'f';
          lpf(lowspeed);
          pid_yaw(360.0);
          move(ch);
        }
        if (encoder_0 >= 3200) {
          ch = 's';
          move(ch);
          ch = 'r';
          rotate_desired = 90.0;
          move(ch);
          sqc = 16;
          flag_reset = true;
        }
        break;
      }
    /////////////////////////////////////////////////////
    case (16): {
        reset_feedback();
        if (encoder_0 <= 1800) {
          encoder_data();
          ch = 'f';
          lpf(highspeed);
          pid_yaw(90.0);
          move(ch);
        }
        if (encoder_0 > 1800) {
          encoder_data();//
          ch = 'f';
          lpf(lowspeed);
          pid_yaw(90.0);
          move(ch);
          if (encoder_0 >= 2000) {//
            l298n();
            line_stop_block();
            flag_reset = true;
            gripper_call();
            sqc = 17;
          }
        }
        break;
      }
    //////////////////////////////////////////////////
    case (17): {
        reset_feedback();
        if (encoder_0 > -1500) {
          encoder_data();
          ch = 'b';
          lpf(highspeed);
          pid_yaw(90.0);
          move(ch);
        }
        if (encoder_0 <= -1500) {
          ch = 'b';
          lpf(lowspeed);
          pid_yaw(90.0);
          move(ch);
          line_stop();
          if (ch == 's') {
            ch = 'r';
            rotate_desired = 180.0;
            move(ch);
            sqc = 18;
          }
        }
        break;
      }
    ///////////////////////////////////////////////////
    case (18): {
        reset_feedback();
        if (encoder_0 <= 3200) {
          encoder_data();
          ch = 'f';
          lpf(highspeed);
          pid_yaw(180.0);
          move(ch);
        }
        if (encoder_0 > 3200) {
          ch = 'f';
          lpf(lowspeed);
          pid_yaw(180.0);
          move(ch);
          line_stop();
          if (ch == 's') {
            ch = 'r';
            rotate_desired = 270.0;
            move(ch);
            digitalWrite(sqc_pin, HIGH);//---->>>>further instructions
          }
        }
        break;
      }
    //////////////////////////////////////////////////
    /////////////////////////////////----->>>>>4th position

    case (19): {
        digitalWrite(sqc_pin, LOW);
        reset_feedback();
        ch = 'r';
        rotate_desired = -360.0;
        move(ch);
        sqc = 20;
        flag_reset = true;
        break;
      }
    ///////////////////////////////////
    case (20): {
        reset_feedback();
        if (encoder_0 <= 3000) {
          encoder_data();
          ch = 'f';
          lpf(highspeed);
          pid_yaw(360.0);
          move(ch);
        }
        if (encoder_0 > 3000 && encoder_0 < 3200) {
          encoder_data();
          ch = 'f';
          lpf(lowspeed);
          pid_yaw(360.0);
          move(ch);
        }
        if (encoder_0 >= 3200) {
          ch = 's';
          move(ch);
          ch = 'r';
          rotate_desired = 90.0;
          move(ch);
          sqc = 21;
          flag_reset = true;
        }
        break;
      }
    /////////////////////////////////////////////////////
    case (21): {
        reset_feedback();
        if (encoder_0 <= 1800) {
          encoder_data();
          ch = 'f';
          lpf(highspeed);
          pid_yaw(90.0);
          move(ch);
        }
        if (encoder_0 > 1800) {
          encoder_data();//
          ch = 'f';
          lpf(lowspeed);
          pid_yaw(90.0);
          move(ch);
          if (encoder_0 >= 2000) {//
            l298n();
            line_stop_block();
            flag_reset = true;
            gripper_call();
            sqc = 22;
          }
        }
        break;
      }
    //////////////////////////////////////////////////
    case (22): {
        reset_feedback();
        if (encoder_0 > -1500) {
          encoder_data();
          ch = 'b';
          lpf(highspeed);
          pid_yaw(90.0);
          move(ch);
        }
        if (encoder_0 <= -1500) {
          ch = 'b';
          lpf(lowspeed);
          pid_yaw(90.0);
          move(ch);
          line_stop();
          if (ch == 's') {
            ch = 'r';
            rotate_desired = 180.0;
            move(ch);
            sqc = 23;
          }
        }
        break;
      }
    ///////////////////////////////////////////////////
    case (23): {
        reset_feedback();
        if (encoder_0 <= 3200) {
          encoder_data();
          ch = 'f';
          lpf(highspeed);
          pid_yaw(180.0);
          move(ch);
        }
        if (encoder_0 > 3200) {
          ch = 'f';
          lpf(lowspeed);
          pid_yaw(180.0);
          move(ch);
          line_stop();
          if (ch == 's') {
            ch = 'r';
            rotate_desired = 270.0;
            move(ch);
            digitalWrite(sqc_pin, HIGH);//---->>>>further instructions
          }
        }
        break;
      }
    //////////////////////////////////////////////////
    /////////////////////////////////----->>>>>5th position
    case (24): {
        digitalWrite(sqc_pin, LOW);
        reset_feedback();
        ch = 'r';
        rotate_desired = -360.0;
        move(ch);
        sqc = 25;
        flag_reset = true;
        break;
      }
    ////////////////////////////////////////
    case (25): {
        reset_feedback();
        if (encoder_0 <= 3000) {
          encoder_data();
          ch = 'f';
          lpf(highspeed);
          pid_yaw(360.0);
          move(ch);
        }
        if (encoder_0 > 3000 && encoder_0 < 3200) {
          encoder_data();
          ch = 'f';
          lpf(lowspeed);
          pid_yaw(360.0);
          move(ch);
        }
        if (encoder_0 > 3200) {
          ch = 's';
          move(ch);
          ch = 'r';
          rotate_desired = -270.0;
          move(ch);
          sqc = 26;
          flag_reset = true;
        }
        break;
      }
    ////////////////////////////////////////
    case (26): {
        reset_feedback();
        if (encoder_0 <= 1800) {
          encoder_data();
          ch = 'f';
          lpf(highspeed);
          pid_yaw(270.0);
          move(ch);
        }
        if (encoder_0 > 1800) {
          encoder_data();//
          ch = 'f';
          lpf(lowspeed);
          pid_yaw(270.0);
          move(ch);
          if (encoder_0 >= 2000) {//
            l298n();
            line_stop_block();
            flag_reset = true;
            gripper_call();
            sqc = 27;
          }
        }
        break;
      }
    ///////////////////////////////////
    case (27): {
        reset_feedback();
        if (encoder_0 > -1500) {
          encoder_data();
          ch = 'b';
          lpf(highspeed);
          pid_yaw(270.0);
          move(ch);
        }
        if (encoder_0 <= -1500) {
          ch = 'b';
          lpf(lowspeed);
          pid_yaw(270.0);
          move(ch);
          line_stop();
          if (ch == 's') {
            ch = 'r';
            rotate_desired = -180.0;
            move(ch);
            sqc = 28;
          }
        }
        break;
      }
    //////////////////////////////////////
    case (28): {
        reset_feedback();
        if (encoder_0 <= 3200) {
          encoder_data();
          ch = 'f';
          lpf(highspeed);
          pid_yaw(180.0);
          move(ch);
        }
        if (encoder_0 > 3200) {
          ch = 'f';
          lpf(lowspeed);
          pid_yaw(180.0);
          move(ch);
          line_stop();
          if (ch == 's') {
            ch = 'r';
            rotate_desired = 270.0;
            move(ch);
            digitalWrite(sqc_pin, HIGH);////////////////-------await further instructions
          }
        }
        break;
      }
    /////////////////////////////////////////////////////////////
    /////////////////////////////////////------------->>>>>>>>>>>stacking form 6th position
    case (29): {
        digitalWrite(sqc_pin, LOW);//6^th position
        reset_feedback();
        ch = 'r';
        rotate_desired = -360.0;
        move(ch);
        sqc = 30;
        flag_reset = true;
        break;
      }
    //////////////////////////////////////////////
    case (30): {
        reset_feedback();
        if (encoder_0 <= 3000) {
          encoder_data();
          ch = 'f';
          lpf(highspeed);
          pid_yaw(360.0);
          move(ch);
        }
        if (encoder_0 > 3000) {
          encoder_data();
          ch = 'f';
          lpf(lowspeed);
          pid_yaw(360.0);
          move(ch);
          if (encoder_0 >= 3200) {
            l298n();
            line_stop_block();
            gripper_call();
            sqc = 31;
          }
        }
        break;
      }
    ////////////////////////
    case (31): {
        reset_feedback();
        if (encoder_0 > -2800) {
          encoder_data();
          ch = 'b';
          lpf(highspeed);
          pid_yaw(360.0);
          move(ch);
        }
        if (encoder_0 <= -2800) {
          ch = 'b';
          lpf(lowspeed);
          pid_yaw(360.0);
          move(ch);
          line_stop();
          if (ch == 's') {
            ch = 'r';
            rotate_desired = -270.0;
            move(ch);
            digitalWrite(sqc_pin, HIGH);////////////-------------await further instructions
          }
        }
        break;
      }
    ///////////////////////////////
    default: {
        //        Serial.println("Default Hit sequence");
        break;
      }
  }
}
