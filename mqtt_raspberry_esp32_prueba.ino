#include <WiFi.h>
#include <Wire.h>
#include <PubSubClient.h>

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg;
char msg[50];
int value = 0;

float temperatura = 0;
float humedad = 0;
const int ledPin1 = 2;
const int ledPin2 = 4;
const int ledPin3 = 13;

//-------------PWM-----------------
const int ledPin4 = 16;
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;

//*******************SSID-Password servidor de internet
const char* ssid = "IZZI-22EA";
const char* password = "3PmpFrGpQCc3";

//******************Direccion del MQTT Broker IP address
const char* mqtt_server = "192.168.0.95";

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(ledPin4, ledChannel);

}

void loop() {
  if (!client.connected()) {
    reconnect();
  }

  client.loop();

  long now = millis();
  if (now - lastMsg > 1000) {
    lastMsg = now;

    //************* Señal 1 que se envia al broker
    temperatura = analogRead(36)*(100.0/4095.0);

    //Convertir el valor en char array
    char tempString[8];
    dtostrf(temperatura, 1, 2, tempString);
    Serial.print("Temperatura: ");
    Serial.println(tempString);
    client.publish("esp32/temperature", tempString); //Topic: "esp32/temperature"

    //**************** Señal que se envia al broker
    humedad = 289.78;

    //Convertir el valor en char array
    char humString[8];
    dtostrf(humedad, 1, 2, humString);
    Serial.print("Temperatura: ");
    Serial.println(tempString);
    client.publish("esp32/humidity", humString); //Topic: "esp32/humidity"

  }
}


void setup_wifi(){
  delay(10);
  Serial.println();
  Serial.print("Conectando a ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Mensaje recibido en topic: ");
  Serial.print(topic);
  Serial.print(", Message: ");
  String messageTemp;
  for(int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

  //********************** Primer output (topic: esp32/output1)
  // Si se recibe mensaje sobre topic 'esp32/output1', verifica si es 'on', off''
  if (String(topic) == "esp32/output1") {
    Serial.print("Cambio de salida: ");
    if(messageTemp == "on") {
      Serial.println("on");
      digitalWrite(ledPin1, HIGH);
    }
    else if(messageTemp == "off") {
      Serial.println("off");
      digitalWrite(ledPin1, LOW);
    }
  }

  //********************** Segundo output (topic: esp32/output2)
  // Si se recibe mensaje sobre topic 'esp32/output2', verifica si es 'on', off''
  if (String(topic) == "esp32/output2") {
    Serial.print("Cambio de salida: ");
    if(messageTemp == "on") {
      Serial.println("on");
      digitalWrite(ledPin2, HIGH);
    }
    else if(messageTemp == "off") {
      Serial.println("off");
      digitalWrite(ledPin2, LOW);
    }
  }

  //********************** Primer output (topic: esp32/output3)
  // Si se recibe mensaje sobre topic 'esp32/output3', verifica si es 'on', off''
  if (String(topic) == "esp32/output3") {
    Serial.print("Cambio de salida: ");
    if(messageTemp == "on") {
      Serial.println("on");
      digitalWrite(ledPin3, HIGH);
    }
    else if(messageTemp == "off") {
      Serial.println("off");
      digitalWrite(ledPin3, LOW);
    }
  }

  //********************** Primer output (topic: esp32/output4)
  // Si se recibe mensaje sobre topic 'esp32/output3', manda al PWM (0-255)
  if (String(topic) == "esp32/output4") {
    Serial.print("Cambio de salida PWM");
    Serial.println("messageTemp");
    ledcWrite(ledChannel, messageTemp.toInt());
  }
}

void reconnect() {
  while(!client.connected()) {
    Serial.print("Intentando conexion MQTT...");
    if (client.connect("ESP32Client")) {
      Serial.println("conectado");
      client.subscribe("esp32/output1");
      client.subscribe("esp32/output2");
      client.subscribe("esp32/output3");
      client.subscribe("esp32/output4");
    }
    else {
      Serial.print("Fallo, rc=");
      Serial.print(client.state());
      Serial.print(" Intentelo de nuevo en 5s");
      delay(5000);
    }
  }
}

































