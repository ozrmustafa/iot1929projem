#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

const char* ssid = "TurkTelekom_CJZ9Y";
const char* password = "5B72cBeD5A816";

#define BOTtoken "1727865024:AAG1C8LFfI_-nNptL7svUrJcLKrL2hl451Y" 
#define CHAT_ID "841540017"

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

const int gazSensor = A0;
const int uyariLed=D5;

void setup() {
  Serial.begin(9600);
  client.setInsecure(); 
  pinMode(uyariLed,OUTPUT);
  Serial.print("Wifi baglaniyor! ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi baglandi");
  Serial.print("IP adresi: ");
  Serial.println(WiFi.localIP()); 
}

void loop() {
  int gazDeger=analogRead(A0);
  Serial.println(gazDeger);
  if(gazDeger>250){
    digitalWrite(uyariLed,HIGH);
    bot.sendMessage(CHAT_ID, "Duman algilandi", "");
    Serial.println("Duman algilandi");
    delay(1000);
  }
  else
  {
    digitalWrite(uyariLed,LOW);
    }
}
