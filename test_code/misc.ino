void SerialFlush(){
    while(Serial.available())
        char ch = Serial.read();
}

