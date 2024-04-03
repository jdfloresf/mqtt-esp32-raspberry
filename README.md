# Comunicación ESP32-Raspberry Pi MQTT
Este repositorio contiene un programa que establece una comunicación bidireccional entre un microcontrolador ESP32 y una Raspberry Pi utilizando el protocolo MQTT (Message Queuing Telemetry Transport).

## Descripción del proyecto
El objetivo de este proyecto es permitir la transferencia de mensajes entre un ESP32 y una Raspberry Pi a través de una red local utilizando MQTT como protocolo de comunicación. El ESP32 actuará como un cliente MQTT que envía datos a la Raspberry Pi, que actúa como el servidor MQTT.

## Requisitos previos
Antes de ejecutar este programa, asegúrate de tener instalado lo siguiente:

Arduino IDE o Plataforma de desarrollo ESP32
Biblioteca PubSubClient para Arduino: PubSubClient
Mosquitto MQTT Broker en la Raspberry Pi: Mosquitto
Configuración
Clona este repositorio en tu máquina local:



``` git clone https://github.com/usuario/repo.git```

Abre el archivo mqtt_esp32_raspberry.ino en Arduino IDE.

Asegúrate de configurar los parámetros de conexión a la red Wi-Fi y al servidor MQTT en el archivo mqtt_esp32_raspberry.ino:

```
const char* ssid = "nombre_de_red_wifi";
const char* password = "contraseña_wifi";
const char* mqtt_server = "direccion_ip_raspberry_pi";
```

Sube el programa al ESP32.

Asegúrate de que el servidor MQTT (Mosquitto) esté en ejecución en la Raspberry Pi y configurado para aceptar conexiones entrantes en el puerto predeterminado (1883).

Observa la salida del programa en la consola del Arduino IDE para verificar la conexión MQTT.
