//------------------------------------------------------------------------------
// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID "TMPL8QnOWJDr"
#define BLYNK_DEVICE_NAME "BLUWIFI"
#define BLYNK_AUTH_TOKEN "h7947jS7Cg3hVBBE0V-aYr0P1aMuRiyV"
//------------------------------------------------------------------------------
// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial
//------------------------------------------------
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run
`make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
//------------------------------------------------
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
//------------------------------------------------
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "XXXXXXXXX";
char pass[] = "XXXXXXX";
//------------------------------------------------

BlynkTimer timer;

#define PIN_BUTTON1 26
#define PIN_BUTTON2 25
#define PIN_BUTTON3 33
#define PIN_BUTTON4 32

#define PIN_RELAY1 23
#define PIN_RELAY2 22
#define PIN_RELAY3 21
#define PIN_RELAY4 19

#define wifiLed    2   //D2

int state_relay1 = 1;
int state_relay2 = 1;
int state_relay3 = 1;
int state_relay4 = 1;

int wifiFlag = 0;
char bt_data; // variable for storing bluetooth data 

//Change the virtual pins according the rooms
#define VPIN_BUTTON1    V0
#define VPIN_BUTTON2    V1
#define VPIN_BUTTON3    V2 
#define VPIN_BUTTON4    V3

//--------------------------------------------------------------------------
// This function is called every time the Virtual Pin state change
//i.e when you push switch from Blynk App or Web Dashboard
BLYNK_WRITE(VPIN_BUTTON1) {
  state_relay1 = param.asInt();
  digitalWrite(PIN_RELAY1, state_relay1);
  Serial.println("BLYNK_WRITE: Relay1 State = "+String(state_relay1));
}
//--------------------------------------------------------------------------
BLYNK_WRITE(VPIN_BUTTON2) {
  digitalWrite(PIN_RELAY2, param.asInt());
 // state_relay2 = param.asInt();
 // digitalWrite(PIN_RELAY2, state_relay2);
}
//--------------------------------------------------------------------------
BLYNK_WRITE(VPIN_BUTTON3) {
  digitalWrite(PIN_RELAY3, param.asInt());
//BLYNK_WRITE(VPIN_BUTTON3) {
//  state_relay3 = param.asInt();
//  digitalWrite(PIN_RELAY3, state_relay3);
}
//--------------------------------------------------------------------------
BLYNK_WRITE(VPIN_BUTTON4) {
  digitalWrite(PIN_RELAY4, param.asInt());
//BLYNK_WRITE(VPIN_BUTTON4) {
//  state_relay4 = param.asInt();
 // digitalWrite(PIN_RELAY4, state_relay4);
}
//--------------------------------------------------------------------------

//------------------------------------------------------------------------------
// This function is called every time the device is connected to the Blynk.Cloud
// Request the latest state from the server
BLYNK_CONNECTED() {
  Blynk.syncVirtual(VPIN_BUTTON1);
  Blynk.syncVirtual(VPIN_BUTTON2);
  Blynk.syncVirtual(VPIN_BUTTON3);
  Blynk.syncVirtual(VPIN_BUTTON4);
}
/*MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
 * handle_bt() function
 * handles incomming bluetooth data to control relays
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM*/
void handle_bt(){
  //------------------------------------
  //char command;
  //if(SerialBT.available()){
    bt_data = SerialBT.read();
    Serial.println(bt_data);
     delay(20);
  //}
  //------------------------------------
  
  switch(bt_data)
  {
     //******************************************************************************
     //Turn ON - Relay1
     case 'A': 
      digitalWrite(PIN_RELAY1, HIGH);  
      state_relay1 = 1; 
      Serial.println("handle_bt: Relay1 State = "+String(state_relay1)); 
      Blynk.virtualWrite(VPIN_BUTTON1, state_relay1);
      break;
      
    //Turn OFF - Relay1
    case 'a': 
      digitalWrite(PIN_RELAY1, LOW); 
      state_relay1 = 0; 
      Blynk.virtualWrite(VPIN_BUTTON1, state_relay1);
      break;
    //******************************************************************************
    //Turn ON - Relay2
    case 'B': 
      digitalWrite(PIN_RELAY2, HIGH);  
      state_relay2 = 1; 
      Blynk.virtualWrite(VPIN_BUTTON2, state_relay2);
      break;
      
    //Turn OFF - Relay2
    case 'b': 
      digitalWrite(PIN_RELAY2, LOW); 
      state_relay2 = 0; 
      Blynk.virtualWrite(VPIN_BUTTON2, state_relay2);
      break;
    //******************************************************************************
    //Turn ON - Relay3
    case 'C': 
      digitalWrite(PIN_RELAY3, HIGH);  
      state_relay3 = 1; 
      Blynk.virtualWrite(VPIN_BUTTON3, state_relay3);
      break;
      
    //Turn OFF - Relay3
    case 'c': 
      digitalWrite(PIN_RELAY3, LOW); 
      state_relay3 = 0; 
      Blynk.virtualWrite(VPIN_BUTTON3, state_relay3);
      break;
    //******************************************************************************
    //Turn ON - Relay4
    case 'D': 
      digitalWrite(PIN_RELAY4, HIGH);  
      state_relay4 = 1; 
      Blynk.virtualWrite(VPIN_BUTTON4, state_relay4);
      break;
      
    //Turn OFF - Relay4
    case 'd': 
      digitalWrite(PIN_RELAY4, LOW); 
      state_relay4 = 0; 
      Blynk.virtualWrite(VPIN_BUTTON4, state_relay4);
      break;
   //******************************************************************************
   }
}

//MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM


void checkBlynkStatus() { // called every 3 seconds by SimpleTimer

  bool isconnected = Blynk.connected();
  if (isconnected == false) {
    wifiFlag = 1;
    digitalWrite(wifiLed, LOW); //Turn off WiFi LED
  }
  if (isconnected == true) {
    wifiFlag = 0;
    digitalWrite(wifiLed, HIGH); //Turn on WiFi LED
  }
}




/*MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
 * setup() function
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM*/
void setup()
{
  // Debug console
  Serial.begin(9600);

  //--------------------------------------------------------------------
  btStart();  //Serial.println("Bluetooth On");
  SerialBT.begin("ESP32");
  Serial.println("The device started, now you can pair it with bluetooth!");
  delay(5000);
  //--------------------------------------------------------------------
  //--------------------------------------------------------------------
  pinMode(PIN_BUTTON1, INPUT_PULLUP);
  pinMode(PIN_BUTTON2, INPUT_PULLUP);
  pinMode(PIN_BUTTON3, INPUT_PULLUP);
  pinMode(PIN_BUTTON4, INPUT_PULLUP);  
  //--------------------------------------------------------------------
  pinMode(PIN_RELAY1, OUTPUT);
  pinMode(PIN_RELAY2, OUTPUT);
  pinMode(PIN_RELAY3, OUTPUT);
  pinMode(PIN_RELAY4, OUTPUT);
  //--------------------------------------------------------------------
  pinMode(wifiLed, OUTPUT);
  //--------------------------------------------------------------------
  //During Starting all Relays should TURN OFF
  digitalWrite(PIN_RELAY1, LOW);
  digitalWrite(PIN_RELAY2, LOW);
  digitalWrite(PIN_RELAY3, LOW);
  digitalWrite(PIN_RELAY4, LOW);
  //digitalWrite(PIN_RELAY1, state_relay1);
  //digitalWrite(PIN_RELAY2, state_relay2);
  //digitalWrite(PIN_RELAY3, state_relay3);
  //digitalWrite(PIN_RELAY4, HIGH);
  //digitalWrite(PIN_RELAY4, state_relay4);
  //--------------------------------------------------------------------
  Blynk.begin(auth, ssid, pass);
   timer.setInterval(3000L, checkBlynkStatus); // check if Blynk server is connected every 3 seconds
  Blynk.config(auth);
  delay(2000);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
  //--------------------------------------------------------------------
  //Blynk.virtualWrite(VPIN_BUTTON1, state_relay1);
  //Blynk.virtualWrite(VPIN_BUTTON2, state_relay2);
  //Blynk.virtualWrite(VPIN_BUTTON3, state_relay3);
  //Blynk.virtualWrite(VPIN_BUTTON4, state_relay4);
  }


/*MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
 * loop() function
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM*/
void loop()
{
   if (WiFi.status() != WL_CONNECTED)
  {
   //wifiFlag = 0 ;
   }
  else
  {
    //Serial.println("WiFi Connected");
    Blynk.run();
   }
  timer.run();
  if (wifiFlag == 1){
    }
  else{
    if (SerialBT.available()){
       handle_bt();
    }
  }
  listen_push_buttons();
}

/*MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
 * listen_push_buttons() function
 * checks if a push button is pressed or not, and control the relay according to the
 * button state
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM*/
void listen_push_buttons(){
    //--------------------------------------------------------------------------
    if(digitalRead(PIN_BUTTON1) == LOW){
      delay(200);
      control_relay(1);
      Blynk.virtualWrite(VPIN_BUTTON1, state_relay1); //update button state
    }
    //--------------------------------------------------------------------------
    else if (digitalRead(PIN_BUTTON2) == LOW){
      delay(200);
      control_relay(2);
      Blynk.virtualWrite(VPIN_BUTTON2, state_relay2); //update button state
    }
    //--------------------------------------------------------------------------
    else if (digitalRead(PIN_BUTTON3) == LOW){
      delay(200);
      control_relay(3);
      Blynk.virtualWrite(VPIN_BUTTON3, state_relay3); //update button state
    }
    //--------------------------------------------------------------------------
    else if (digitalRead(PIN_BUTTON4) == LOW){
      delay(200);
      control_relay(4);
      Blynk.virtualWrite(VPIN_BUTTON4, state_relay4); //update button state
    }
    //--------------------------------------------------------------------------
}

//MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM

/*MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
 * control_relay() function
 * turn on or off the relays
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM*/
void control_relay(int relay){
  //------------------------------------------------
  if(relay == 1){
    state_relay1 = !state_relay1;
    digitalWrite(PIN_RELAY1, state_relay1);
    Serial.println("control_relay: Relay1 State = "+String(state_relay1));
    delay(50);
  }
  //------------------------------------------------
  else if(relay == 2){
    state_relay2 = !state_relay2;
    digitalWrite(PIN_RELAY2, state_relay2);
    delay(50);
  }
  //------------------------------------------------
  else if(relay == 3){
    state_relay3 = !state_relay3;
    digitalWrite(PIN_RELAY3, state_relay3);
    delay(50);
  }
  //------------------------------------------------
  else if(relay == 4){
    state_relay4 = !state_relay4;
    digitalWrite(PIN_RELAY4, state_relay4);
    delay(50);
  }
  //------------------------------------------------
}
