# Comunicación ESP32-Raspberry Pi MQTT con Interfaz Node-RED
Este repositorio contiene un programa que establece una comunicación bidireccional entre un microcontrolador ESP32 y una Raspberry Pi utilizando el protocolo MQTT (Message Queuing Telemetry Transport). Además, incluye una interfaz de usuario construida con Node-RED para interactuar con el sistema.

## Descripción del proyecto
El objetivo de este proyecto es permitir la transferencia de mensajes entre un ESP32 y una Raspberry Pi a través de una red local utilizando MQTT como protocolo de comunicación. El ESP32 actuará como un cliente MQTT que envía datos a la Raspberry Pi, que actúa como el servidor MQTT. Además, se ha creado una interfaz de usuario utilizando Node-RED para visualizar y controlar la comunicación de manera intuitiva.

## Requisitos previos
Antes de ejecutar este programa, asegúrate de tener instalado lo siguiente:

+ Arduino IDE o Plataforma de desarrollo ESP32
+ Biblioteca PubSubClient para Arduino: [PubSubClient](https://github.com/knolleary/pubsubclient)
+ Mosquitto MQTT Broker en la Raspberry Pi: [Mosquitto](https://mosquitto.org/)
+ Node.js y npm en la Raspberry Pi: [Node.js](https://nodejs.org/en)
+ Node-RED en la Raspberry Pi: [Node-RED](https://nodered.org/)

## Configuración
Clona este repositorio en tu máquina local

``` git clone https://github.com/usuario/repo.git```

Abre el archivo mqtt_esp32_raspberry.ino en Arduino IDE.

Configurar los parámetros de conexión a la red Wi-Fi y al servidor MQTT en el archivo mqtt_esp32_raspberry.ino:

```
const char* ssid = "nombre_de_red_wifi";
const char* password = "contraseña_wifi";
const char* mqtt_server = "direccion_ip_raspberry_pi";
```

Subir el programa al ESP32.
Asegurase de que el servidor MQTT (Mosquitto) esté en ejecución en la Raspberry Pi y configurado para aceptar conexiones entrantes en el puerto predeterminado (1883).
Ejecuta Node-RED en la Raspberry Pi:

```node-red-start```

Abrir el editor de Node-RED desde el navegador web mediante la ip de la raspberry.
Despliega el flujo de Node-RED y accede a la interfaz de usuario desde tu navegador.
Observa la salida del programa en la consola del Arduino IDE para verificar la conexión MQTT.
