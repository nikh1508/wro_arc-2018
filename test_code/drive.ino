enum motors{back, left, right, all};

void stopMotor(int motor, bool hardBrake = false){
    switch(motor){
        case back:
            digitalWrite(ft_d1, hardBrake);
            digitalWrite(ft_d2, hardBrake);
            break;
        case left:
            digitalWrite(lt_d1, hardBrake);
            digitalWrite(lt_d2, hardBrake);
            break;
        case right:
            digitalWrite(rt_d1, hardBrake);
            digitalWrite(rt_d2, hardBrake);
        case all:
            digitalWrite(ft_d1, hardBrake);
            digitalWrite(ft_d2, hardBrake);
            digitalWrite(lt_d1, hardBrake);
            digitalWrite(lt_d2, hardBrake);
            digitalWrite(rt_d1, hardBrake);
            digitalWrite(rt_d2, hardBrake);
    }   
}

int current_pwm[3] = {0};
void writeMotor(int motor, int pwm){
    switch(motor){
        case back:
            digitalWrite(ft_d1, pwm > 0);
            digitalWrite(ft_d2, pwm < 0);
            analogWrite(ft_pwm, abs(pwm));
            current_pwm[0] = pwm;
            break;
        case left:
            digitalWrite(lt_d1, pwm > 0);
            digitalWrite(lt_d2, pwm < 0);
            analogWrite(lt_pwm, abs(pwm));
            current_pwm[1] = pwm;

            break;
        case right:
            digitalWrite(rt_d1, pwm > 0);
            digitalWrite(rt_d2, pwm < 0);
            analogWrite(rt_pwm, abs(pwm));
            current_pwm[2] = pwm;
            break;
    }
    if(motor_debug){
                Serial.print("FT_PWM : : ");
                Serial.print(current_pwm[0]);
                Serial.print("\tLT_PWM : : ");
                Serial.print(current_pwm[1]);
                Serial.print("\tRT_PWM : : ");
                Serial.print(current_pwm[2]);
            }
}
