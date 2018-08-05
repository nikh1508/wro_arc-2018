BLYNK_CONNECTED() {
  Blynk.syncAll();
}

BLYNK_APP_CONNECTED() {
  Blynk.syncAll();
}

//BLYNK_APP_DISCONNECTED() {
//  initialize_default();
//}
BLYNK_WRITE(V0)
{
  gripper_cur = param.asInt();
  Serial.println("Gripper Value :: " + String(gripper_cur));
}

BLYNK_WRITE(V1)
{
  arm_cur = param.asInt();
  Serial.println("Arm Value :: " + String(arm_cur));
}
