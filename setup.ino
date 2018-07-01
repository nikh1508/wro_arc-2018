void setup(){
    Serial.begin(115200);
    Serial.println("Setting up the bot.");
    Wire.begin();
    for (int i : pins)
        pinMode(i, OUTPUT);
    //  while(!bnoInitialize()){
    //      Serial.println("BNO not connected. Trying to reconnect.");
    //      delay(200);
    //  } 
    Serial.println("Setup Complete.");
}