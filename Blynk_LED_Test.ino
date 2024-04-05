/* This sketch uses and ESP8266 with an LED attanced to D7 (GPIO13) and Blynk
It may be used as an IoT test for your device.
*/

#define BLYNK_TEMPLATE_ID "TMPL2vMaE48jE"
#define BLYNK_TEMPLATE_NAME "TestESP8266"
#define BLYNK_AUTH_TOKEN "xBvJOhgIu2EvmPz6KEPml9T4Jv1Lsz6o"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "mechlab";
char pass[] = "etufh89959";

void setup(){
  Serial.begin(115200);
  pinMode(13, OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

BLYNK_WRITE(V0){
  int i=param.asInt();
  if (i==255){
    Serial.println("On");
    digitalWrite(13, HIGH);
  }
  else{
    digitalWrite(13, LOW);
    Serial.println("Off");
  }
}

void loop(){
  Blynk.run();
}
