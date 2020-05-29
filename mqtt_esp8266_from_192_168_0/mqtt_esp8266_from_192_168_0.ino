/***************************************************
  Adafruit MQTT Library ESP8266 Example

  Must use ESP8266 Arduino from:
    https://github.com/esp8266/Arduino

  Works great with Adafruit's Huzzah ESP board & Feather
  ----> https://www.adafruit.com/product/2471
  ----> https://www.adafruit.com/products/2821

  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Tony DiCola for Adafruit Industries.
  MIT license, all text above must be included in any redistribution
 ****************************************************/
#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

/************************* WiFi Access Point *********************************/

#define WLAN_SSID       "Hi3d3n"
#define WLAN_PASS       "janinaja"

/************************* Adafruit.io Setup *********************************/

#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883                   // use 8883 for SSL
#define AIO_USERNAME    "ddgkcem"
#define AIO_KEY         "bea11afd2b7d41c3a75fb5e632bfb1d9"

/************ Global State (you don't need to change this!) ******************/

// Create an ESP8266 WiFiClient class to connect to the MQTT server.
WiFiClient client;
WiFiServer server(80);
// or... use WiFiFlientSecure for SSL
//WiFiClientSecure client;

// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details.
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

/****************************** Feeds ***************************************/

// Setup a feed called 'photocell' for publishing.
// Notice MQTT paths for AIO follow the form: <username>/feeds/<feedname>
Adafruit_MQTT_Publish photocell = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Solar Power");

// Setup a feed called 'onoff' for subscribing to changes.
Adafruit_MQTT_Subscribe onoffbutton = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/onoff");

/*************************** Sketch Code ************************************/

// Bug workaround for Arduino 1.6.6, it seems to need a function declaration
// for some reason (only affects ESP8266, likely an arduino-builder bug).
void MQTT_connect();
 int result =0;

void setup() {
  pinMode(2, OUTPUT);
  Serial.begin(9600);
  delay(10);

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

  server.begin();
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Setup MQTT subscription for onoff feed.
  mqtt.subscribe(&onoffbutton);
}

uint32_t x;

void loop() {
   MQTT_connect();

  // this is our 'wait for incoming subscription packets' busy subloop
  // try to spend your time here

  Adafruit_MQTT_Subscribe *subscription;
  while ((subscription = mqtt.readSubscription(5000))) {
    if (subscription == &onoffbutton) {
      Serial.print(F("Got: "));
      Serial.println((char *)onoffbutton.lastread);
    }
  }

  // Now we can publish stuff!
   float y;
  y = Serial.parseFloat();
  Serial.print(F("\nSending photocell val "));
  Serial.print(y);
  Serial.print("...");
  
  
  if ( photocell.publish(result)) {
    Serial.println(F("Failed"));
  } else {
    Serial.println(F("OK!"));
  }
  // Check if a client has connected
  WiFiClient client = server.available();
 if (!client) {
    return;
  }
   
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
   
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
  
   
  // Match the request
 char data[1024];
 strcpy(data, request.c_str());
 int len = strlen(data);
 String finalresult;
 for (int i = 5; i <len; i++)
 {
  char chr = data[i];
  if(chr =='_')break;
  finalresult +=(char)chr;
 }
  result = finalresult.toInt();
  Serial.print(request);
 Serial.print(result);
 
  int value = LOW;
  if (request.indexOf("LED=ON")!= -1 ) {
    digitalWrite(0, HIGH);
    digitalWrite(2, HIGH);
    value = HIGH;
  } 
  if (request.indexOf("LED=OFF")!= -1 ){
    digitalWrite(0, LOW);
    digitalWrite(2, LOW);
    value = LOW;
  }
 
  //Set ledPin according to the request
  //digitalWrite(ledPin, value);
   
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
   
  client.print("Led pin is now: ");
   
  if(value == HIGH) {
    client.print("On");  
  } else {
    client.print("Off");
  }
  client.println("<br><br>");
  client.println("Click <a href=\"/LED=ON\">here</a> turn the LED on pin 2 ON<br>");
  client.println("Click <a href=\"/LED=OFF\">here</a> turn the LED on pin 2 OFF<br>");
  client.println("</html>");
 
  delay(100);
  //Serial.print("Read=");
  //Serial.print(client.readStringUntil('\r'));
  Serial.println("Client disconnected");
  Serial.println("");
  // Ensure the connection to the MQTT server is alive (this will make the first
  // connection and automatically reconnect when disconnected).  See the MQTT_connect
  // function definition further below.
 
   ///////////
  //mqtt.disconnect();
    //////////////
  // ping the server to keep the mqtt connection alive
  // NOT required if you are publishing once every KEEPALIVE seconds
  /*
  if(! mqtt.ping()) {
    mqtt.disconnect();
  }
  */
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
