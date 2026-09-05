<html lang="es">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Biblioteca Digital Interactiva - Prácticas Domótica</title>
    <style>
        :root {
            --primary-blue: #0056b3;
            --header-bg: #003366;
            --nav-bg: #002244;
            --active-tab: #0066cc;
            --body-bg: #f4f6f9;
            --card-bg: #ffffff;
            --text-color: #333333;
        }

        body {
            font-family: 'Segoe UI', Arial, sans-serif;
            margin: 0;
            padding: 0;
            background-color: var(--body-bg);
            color: var(--text-color);
        }

        /* Encabezado */
        header {
            background-color: var(--header-bg);
            color: white;
            text-align: center;
            padding: 20px 10px;
        }

        header h1 {
            margin: 0;
            font-size: 1.8rem;
        }

        header p {
            margin: 5px 0 0 0;
            font-size: 0.95rem;
            color: #d1e0f0;
        }

        /* Menú Navegación */
        nav {
            background-color: var(--nav-bg);
            display: flex;
            justify-content: center;
            gap: 5px;
            padding: 5px 10px 0 10px;
            flex-wrap: wrap;
        }

        .tab-btn {
            background-color: transparent;
            color: #e0e0e0;
            border: none;
            padding: 12px 20px;
            font-size: 0.95rem;
            font-weight: bold;
            cursor: pointer;
            border-radius: 6px 6px 0 0;
            transition: all 0.2s ease;
        }

        .tab-btn:hover {
            background-color: rgba(255, 255, 255, 0.1);
            color: white;
        }

        .tab-btn.active {
            background-color: var(--active-tab);
            color: white;
        }

        /* Contenedor y Pestañas */
        .container {
            max-width: 1100px;
            margin: 25px auto;
            padding: 0 15px;
        }

        .tab-content {
            display: none;
            background: white;
            padding: 25px;
            border-radius: 8px;
            box-shadow: 0 2px 8px rgba(0,0,0,0.08);
        }

        .tab-content.active {
            display: block;
        }

        h2 {
            color: #111;
            margin-top: 0;
            font-size: 1.5rem;
        }

        .quick-def {
            color: #555;
            font-size: 0.95rem;
            margin-bottom: 25px;
            line-height: 1.5;
        }

        /* Rejilla de Tarjetas */
        .grid-cards {
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(300px, 1fr));
            gap: 20px;
        }

        .card {
            background: var(--card-bg);
            border: 1px solid #e0e0e0;
            border-radius: 6px;
            padding: 18px;
            display: flex;
            flex-direction: column;
            justify-content: space-between;
        }

        .card-badge {
            display: inline-block;
            background-color: #e8f1f8;
            color: var(--primary-blue);
            font-size: 0.75rem;
            font-weight: bold;
            padding: 4px 8px;
            border-radius: 4px;
            margin-bottom: 10px;
            width: fit-content;
        }

        .card h3 {
            margin: 0 0 10px 0;
            font-size: 1.1rem;
            color: #003366;
            border-bottom: 2px solid #0056b3;
            padding-bottom: 5px;
        }

        .card-img {
            width: 100%;
            height: 180px;
            object-fit: contain;
            margin: 10px 0;
            border-radius: 4px;
            background-color: #fafafa;
        }

        .card p {
            font-size: 0.88rem;
            color: #555;
            line-height: 1.4;
            margin: 5px 0;
        }

        .card-spec {
            font-size: 0.82rem;
            color: #333;
            background-color: #f8fafc;
            padding: 8px;
            border-left: 3px solid var(--primary-blue);
            margin-top: 8px;
        }

        .btn-action {
            display: block;
            text-align: center;
            background-color: var(--primary-blue);
            color: white;
            text-decoration: none;
            padding: 8px 12px;
            border-radius: 4px;
            font-size: 0.85rem;
            font-weight: bold;
            margin-top: 15px;
            cursor: pointer;
            border: none;
        }

        .btn-action:hover {
            background-color: #003366;
        }
    </style>
</head>
<body>

    <header>
        <h1>📚 Biblioteca Digital Interactiva</h1>
        <p>Prácticas de Domótica e Internet de las Cosas (IoT) — Instrumentación y Control</p>
    </header>

    <nav>
        <button class="tab-btn active" onclick="openTab(event, 'inicio')">🏠 Inicio</button>
        <button class="tab-btn" onclick="openTab(event, 'cableada')">🔌 Domótica Cableada</button>
        <button class="tab-btn" onclick="openTab(event, 'esp32')">📶 ESP32 & Microcontroladores</button>
        <button class="tab-btn" onclick="openTab(event, 'alexa')">🗣️ Control por Voz (Alexa)</button>
    </nav>

    <div class="container">

        <!-- Pestaña 1: Inicio -->
        <div id="inicio" class="tab-content active">
            <h2>Bienvenido a la Plataforma Didáctica</h2>
            <p class="quick-def">Esta herramienta interactiva permite a estudiantes y docentes consultar de forma visual y rápida las características técnicas, esquemas de funcionamiento y prácticas reales del ecosistema domótico e IoT.</p>
            
            <div class="grid-cards">
                <div class="card">
                    <div>
                        <span class="card-badge">Fundamentos</span>
                        <h3>Domótica Cableada</h3>
                        <img class="card-img" src="https://upload.wikimedia.org/wikipedia/commons/thumb/1/1e/KNX-logo.svg/320px-KNX-logo.svg.png" alt="KNX Cableado">
                        <p>Sistemas profesionales de bus cableado (KNX, X10, BACnet) orientados a edificios inteligentes de alta fiabilidad.</p>
                    </div>
                    <button class="btn-action" onclick="switchTab('cableada')">Explorar Tema →</button>
                </div>

                <div class="card">
                    <div>
                        <span class="card-badge">Hardware Libres</span>
                        <h3>ESP32 & IoT</h3>
                        <img class="card-img" src="https://upload.wikimedia.org/wikipedia/commons/thumb/8/87/ESP-WROOM-32_ESP32_NodeMCU_Wi-Fi_microcontroller_module.jpg/320px-ESP-WROOM-32_ESP32_NodeMCU_Wi-Fi_microcontroller_module.jpg" alt="ESP32 Module">
                        <p>Placas de desarrollo de bajo costo con Wi-Fi/Bluetooth nativos para nodos de sensorización y control.</p>
                    </div>
                    <button class="btn-action" onclick="switchTab('esp32')">Explorar Tema →</button>
                </div>

                <div class="card">
                    <div>
                        <span class="card-badge">Cloud & Voz</span>
                        <h3>Integración Alexa</h3>
                        <img class="card-img" src="https://upload.wikimedia.org/wikipedia/commons/thumb/c/cc/Amazon_Alexa_logo.svg/320px-Amazon_Alexa_logo.svg.png" alt="Amazon Alexa">
                        <p>Vinculación de actuadores físicos mediante Arduino IoT Cloud y la Skill oficial de Amazon Alexa.</p>
                    </div>
                    <button class="btn-action" onclick="switchTab('alexa')">Explorar Tema →</button>
                </div>
            </div>
        </div>

        <!-- Pestaña 2: Domótica Cableada -->
        <div id="cableada" class="tab-content">
            <h2>Domótica Cableada y Sistemas Bus</h2>
            <p class="quick-def"><b>Definición rápida:</b> Protocolos de comunicación industrial y residencial donde los actuadores y sensores están interconectados mediante cables físicos dedicados o la red eléctrica existente.</p>
            
            <div class="grid-cards">
                <div class="card">
                    <div>
                        <span class="card-badge">Estándar Mundial</span>
                        <h3>Sistema Bus KNX</h3>
                        <img class="card-img" src="https://upload.wikimedia.org/wikipedia/commons/thumb/1/1e/KNX-logo.svg/320px-KNX-logo.svg.png" alt="KNX Bus">
                        <p><b>Principio:</b> Medio de comunicación descentralizado sobre cable de par trenzado (TP-1) a 29-30 VDC.</p>
                        <div class="card-spec">
                            <b>Aplicación Típica:</b> Cuadros eléctricos centralizados, control de persianas y climatización HVAC.
                        </div>
                    </div>
                    <a href="https://github.com/crisdibujes/Practicas-Domotica/tree/main/01-Introduccion-Protocolos" target="_blank" class="btn-action">Ver Código / Archivos</a>
                </div>

                <div class="card">
                    <div>
                        <span class="card-badge">Red Eléctrica</span>
                        <h3>Protocolo X10</h3>
                        <img class="card-img" src="https://upload.wikimedia.org/wikipedia/commons/thumb/e/e5/Relay_module_for_Arduino.jpg/320px-Relay_module_for_Arduino.jpg" alt="X10 Modulo">
                        <p><b>Principio:</b> Inyección de ráfagas de alta frecuencia (120 kHz) en el cruce por cero de la red de 110V/220V AC.</p>
                        <div class="card-spec">
                            <b>Aplicación Típica:</b> Automatizaciones residenciales básicas sin requerir cableado estructurado adicional.
                        </div>
                    </div>
                    <a href="https://github.com/crisdibujes/Practicas-Domotica/tree/main/01-Introduccion-Protocolos" target="_blank" class="btn-action">Ver Código / Archivos</a>
                </div>
            </div>
        </div>

        <!-- Pestaña 3: ESP32 -->
        <div id="esp32" class="tab-content">
            <h2>ESP32 & Programación de Nodos IoT</h2>
            <p class="quick-def"><b>Definición rápida:</b> Microcontrolador System-on-Chip de 32 bits diseñado por Espressif con conectividad inalámbrica, pines GPIO, ADC, PWM e I2C integrados.</p>
            
            <div class="grid-cards">
                <div class="card">
                    <div>
                        <span class="card-badge">Microcontrolador</span>
                        <h3>ESP32 DevKit v1</h3>
                        <img class="card-img" src="https://upload.wikimedia.org/wikipedia/commons/thumb/8/87/ESP-WROOM-32_ESP32_NodeMCU_Wi-Fi_microcontroller_module.jpg/320px-ESP-WROOM-32_ESP32_NodeMCU_Wi-Fi_microcontroller_module.jpg" alt="ESP32 Board">
                        <p><b>Principio:</b> Microprocesador Dual-Core Xtensa LX6 con antena Wi-Fi integrada de 2.4 GHz.</p>
                        <div class="card-spec">
                            <b>Voltaje Típico:</b> 3.3V Lógica / 5V Alimentación USB.<br>
                            <b>Función:</b> Procesamiento local y envío de métricas de sensores a la nube.
                        </div>
                    </div>
                    <a href="https://github.com/crisdibujes/Practicas-Domotica/tree/main/02-Arduino-ESP32" target="_blank" class="btn-action">Ver Archivos .INO</a>
                </div>

                <div class="card">
                    <div>
                        <span class="card-badge">Actuador</span>
                        <h3>Módulo de Relé de 5V</h3>
                        <img class="card-img" src="https://upload.wikimedia.org/wikipedia/commons/thumb/e/e5/Relay_module_for_Arduino.jpg/320px-Relay_module_for_Arduino.jpg" alt="Relay Module">
                        <p><b>Principio:</b> Interruptor optoacoplado que conmuta cargas de alta potencia (110V/220V) mediante señales TTL.</p>
                        <div class="card-spec">
                            <b>Función:</b> Encendido y apagado de luces, motores o electrodomésticos desde el GPIO.
                        </div>
                    </div>
                    <a href="https://github.com/crisdibujes/Practicas-Domotica/tree/main/02-Arduino-ESP32" target="_blank" class="btn-action">Ver Archivos .INO</a>
                </div>
            </div>
        </div>

        <!-- Pestaña 4: Alexa -->
        <div id="alexa" class="tab-content">
            <h2>Control por Voz (Amazon Alexa + Cloud)</h2>
            <p class="quick-def"><b>Definición rápida:</b> Integración IoT que vincula variables programadas en la nube de Arduino con los servidores de voz de Amazon para ejecutar comandos hablados en tiempo real.</p>
            
            <div class="grid-cards">
                <div class="card">
                    <div>
                        <span class="card-badge">Asistente Virtual</span>
                        <h3>Amazon Echo / Alexa Skill</h3>
                        <img class="card-img" src="https://upload.wikimedia.org/wikipedia/commons/thumb/c/cc/Amazon_Alexa_logo.svg/320px-Amazon_Alexa_logo.svg.png" alt="Alexa Echo">
                        <p><b>Principio:</b> Procesamiento de lenguaje natural mediante la nube para activar objetos virtuales tipo <i>CloudSwitch</i>.</p>
                        <div class="card-spec">
                            <b>Ejemplo Real:</b> "Alexa, enciende la luz del estudio" manda el evento al servidor IoT y activa el relé del ESP32.
                        </div>
                    </div>
                    <a href="https://github.com/crisdibujes/Practicas-Domotica/tree/main/04-Integracion-Alexa" target="_blank" class="btn-action">Ver Guía de Integración</a>
                </div>
            </div>
        </div>

    </div>

    <script>
        function openTab(evt, tabName) {
            var i, tabcontent, tablinks;
            tabcontent = document.getElementsByClassName("tab-content");
            for (i = 0; i < tabcontent.length; i++) {
                tabcontent[i].classList.remove("active");
            }
            tablinks = document.getElementsByClassName("tab-btn");
            for (i = 0; i < tablinks.length; i++) {
                tablinks[i].classList.remove("active");
            }
            document.getElementById(tabName).classList.add("active");
            if(evt) evt.currentTarget.classList.add("active");
        }

        function switchTab(tabName) {
            var tablinks = document.getElementsByClassName("tab-btn");
            for (var i = 0; i < tablinks.length; i++) {
                tablinks[i].classList.remove("active");
                if (tablinks[i].getAttribute("onclick").includes(tabName)) {
                    tablinks[i].classList.add("active");
                }
            }
            openTab(null, tabName);
            window.scrollTo({top: 0, behavior: 'smooth'});
        }
    </script>

</body>
</html>
