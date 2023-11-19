#include <ESP8266WiFi.h>
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>
#include <SoftwareSerial.h>

// Substitua pelos detalhes de sua rede WiFi
#define WLAN_SSID       "..SSID DO WIFI.."
#define WLAN_PASS       "..SENHA DO WIFI.."

// Substitua pelos detalhes do seu servidor MQTT no Adafruit.io
#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883
#define AIO_USERNAME  "oscarbmonteiro"
#define AIO_KEY       "..SUA CHAVE DO ADAFUIT.IO.."


WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

// Declaração de feeds MQTT
Adafruit_MQTT_Publish umidade = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/umidade");


float umidadeValor;
//bool desumidificadorValor, umidificadorValor;

void MQTT_connect();

void setup() {
  Serial.begin(9600);
  delay(2000);

  Serial.println(F("Adafruit MQTT demo"));

  // Connect to WiFi access point.
  Serial.println(); Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);

  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.println("WiFi connected");
  Serial.println("IP address: "); Serial.println(WiFi.localIP());

}

void loop() {
  MQTT_connect();
   
  mqtt.processPackets(10000);
  mqtt.ping();
  
  String recebido = "";
  recebido = Serial.readStringUntil(';');
  umidadeValor = recebido.toFloat();
  if (umidadeValor > 0) {
    umidade.publish(umidadeValor);
  }
 
}

// Function to connect and reconnect as necessary to the MQTT server.
// Should be called in the loop function and it will take care if connecting.
void MQTT_connect() {
  int8_t ret;

  // Stop if already connected.
  if (mqtt.connected()) {
    return;
  }

  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
       Serial.println(mqtt.connectErrorString(ret));
       Serial.println("Retrying MQTT connection in 5 seconds...");
       mqtt.disconnect();
       delay(5000);  // wait 5 seconds
       retries--;
       if (retries == 0) {
         // basically die and wait for WDT to reset me
         while (1);
       }
  }
  Serial.println("MQTT Connected!");
}