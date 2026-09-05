Prácticas-Domótica
Este repositorio reúne guías, prácticas y ejemplos de Domótica e Internet de las Cosas (IoT), documentando la evolución tecnológica del control del hogar y edificaciones inteligentes, desde sus orígenes cableados hasta el ecosistema actual basado en IoT, Wi-Fi y Asistentes de Voz.
1. Evolución de la Domótica: De lo Cableado al IoT Inalámbrico
La domótica comenzó con sistemas cableados y protocolos propietarios de alta fiabilidad, orientados al ámbito profesional y residencial de alta gama. Estándares pioneros como X10 (comunicación a través de la red eléctrica) y KNX / BACnet (mediante bus de datos dedicado) sentaron las bases del control centralizado para iluminación, climatización y persianas.
Con el avance de la tecnología, la masificación del Wi-Fi y la democratización de la electrónica con la filosofía maker, la domótica evolucionó hacia sistemas inalámbricos descentralizados, flexibles y de bajo costo:
Hardware Abierto y Microcontroladores: Uso de placas de desarrollo como ESP32 y Arduino para la creación de sensores, actuadores y nodos de automatización a medida.
Conectividad Wi-Fi y Plataformas Cloud: Gestión, monitoreo y control remoto en tiempo real mediante servicios como Arduino IoT Cloud, Blynk y ESPHome.
Control por Voz e Integración Oficial: Integración directa con Amazon Alexa a través de la Skill oficial de Arduino para la ejecución de comandos de voz, rutinas de automatización y control accesible de la vivienda.
Hubs Centralizados y Sofisticación Local: Integración de protocolos de baja potencia (Zigbee, Z-Wave, Thread y el estándar emergente Matter) en plataformas abiertas como Home Assistant, permitiendo unificar dispositivos comerciales de diversas marcas sin dependencia estricta de internet.
Dispositivos y Marcas Populares en el Mercado
Categoría
Marcas Globales Destacadas
Disponibles / Populares en Ecuador
 Sistemas Profesionales (Bus)
KNX, Lutron, Control4, Loxone
Lutron, Control4, Vimar, Bticino / Legrand
Hogar Comercial (Wi-Fi / Zigbee)
Philips Hue, Sonoff, Shelly, Aqara, SwitchBot
Sonoff, Tuya / Smart Life, Nexxt Solutions, Broadlink
Control por Voz y Hubs
Amazon Alexa (Echo), Google Assistant, Apple HomeKit
Amazon Alexa (Echo Pop/Dot/Show), Google Nest
Componentes DIY / Desarrollo
Espressif (ESP32/ESP8266), Arduino, Raspberry Pi
Espressif (ESP32), Arduino UNO/Nano, Sensores compatibles

2. Estructura del Repositorio
Practicas-Domotica/
├── 01-Introduccion-Protocolos/  # Documentación técnica sobre KNX, X10 y redes inalámbricas
├── 02-Arduino-ESP32/            # Código C++ / Firmware (.ino, .cpp) para placas de desarrollo
├── 03-Plataformas-Cloud/        # Proyectos y tableros en Blynk y Arduino IoT Cloud
├── 04-Integracion-Alexa/        # Configuración de Arduino IoT Cloud con la Skill oficial de Amazon Alexa
├── 05-Home-Assistant/           # Archivos de configuración YAML y automatizaciones locales
└── README.md                    # Descripción e instrucciones del 

3. Requisitos Previos
Software y Entornos de Desarrollo
Arduino IoT Cloud & Arduino Create Agent.
Arduino IDE (versión 2.0 o superior) o PlatformIO en VS Code.
Driver CP210x o CH340 para la detección de la placa ESP32 por USB.
Cuenta activa en Arduino IoT Cloud.
Aplicación móvil Amazon Alexa en smartphone o tablet.
Instalación de Home Assistant (Home Assistant OS en Raspberry Pi o Docker/VM) para las prácticas avanzadas.
Hardware Sugerido
Placa de desarrollo ESP32 DevKit v1 (Wi-Fi + Bluetooth).
Módulo de Relés de 5V (1 a 4 canales) para control de cargas.
Sensores: DHT11 o DHT22 (Temperatura/Humedad), Sensor Ultrasónico HC-SR04, Sensor LDR (Luz).
Actuadores: LEDs, Servomotores SG90, Buzzer activo.
Cableado tipo Dupont (M-M, M-H, H-H) y Protoboard.
Parlante / Hub inteligente Amazon Echo (opcional, también se puede usar la App Alexa).
Dispositivos comerciales Sonoff o Tuya (opcional para flotas de pruebas).

4. Instalación y Configuración del Entorno de Trabajo
Paso 1: Clonar el Repositorio
git clone https://github.com/TuUsuario/Practicas-Domotica.git
cd Practicas-Domotica
Paso 2: Configurar Arduino IDE para ESP32
Abre Arduino IDE.
Ve a Archivo > Preferencias.
En el campo Gestor de URLs Adicionales de Tarjetas, agrega la siguiente URL:
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
Dirígete a Herramientas > Placa > Gestor de Tarjetas..., busca esp32 de Espressif Systems e instálalo.
Selecciona tu modelo de placa (ej. ESP32 Dev Module) en Herramientas > Placa.
Paso 3: Instalación de Librerías Requeridas
Desde el Gestor de Librerías de Arduino IDE (Herramientas > Administrar Bibliotecas), instala las siguientes dependencias según la práctica a realizar:
WiFi (incluida en el core de ESP32)
ArduinoIoTCloud & Arduino_ConnectionHandler
Blynk (por Volodymyr Shymanskyy)
DHT sensor library de Adafruit

5. Guía Rápida para la Primera Práctica (ESP32 + Arduino Cloud + Alexa)
Crear la Thing en Arduino IoT Cloud: Ingresa a create.arduino.cc/iot/, crea una nueva "Thing" y asocia tu dispositivo ESP32.
Añadir Variable para Alexa: Crea una variable booleana de tipo Alexa Switch (ej. rele_estado) con permisos de lectura y escritura (Read & Write) al cambiar (On Change).
Carga del firmware: Configura tus credenciales Wi-Fi y Secret Key del dispositivo en el editor de Arduino Cloud o sube el código desde tu equipo.
Vincular con Amazon Alexa:
Abre la aplicación Amazon Alexa en tu dispositivo móvil.
Ve a Más > Skills y juegos.
Busca la Skill oficial Arduino, habilítala e inicia sesión con tu cuenta de Arduino Cloud.
Detecta nuevos dispositivos. Alexa identificará la variable de tu ESP32 como un interruptor o luz de forma automática.
Prueba con el comando: "Alexa, enciende el interruptor" o "Alexa, apaga la luz".

6. Licencia y Contribución
Este proyecto se distribuye bajo la licencia MIT. Las contribuciones, sugerencias, correcciones de errores o aportes de nuevas prácticas son totalmente bienvenidas mediante Pull Requests.


