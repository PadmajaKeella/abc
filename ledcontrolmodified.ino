/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/

// Load Wi-Fi library
#include <WiFi.h>

// Replace with your network credentials
const char* ssid = "SRKR_IDEALAB";
const char* password = "Tech$9889";

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state
String relay1State = "off";
String relay2State = "off";
String relay3State = "off";
String relay4State = "off";
String relay5State = "off";
String relay6State = "off";
String relay7State = "off";
String relay8State = "off";
// Assign output variables to GPIO pins
const int relay1 = 26;
const int relay2 = 27;
const int relay3 = 19;
const int relay4 = 21;
const int relay5 = 22;
const int relay6 = 23;
const int relay7 = 34;
const int relay8 = 35;
// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

void setup() {
  Serial.begin(115200);
  // Initialize the output variables as outputs
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(relay5, OUTPUT);
  pinMode(relay6, OUTPUT);
  pinMode(relay7, OUTPUT);
  pinMode(relay8, OUTPUT);
  // Set outputs to LOW
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, LOW);
  digitalWrite(relay4, LOW);
  digitalWrite(relay5, LOW);
  digitalWrite(relay6, LOW);
  digitalWrite(relay7, LOW);
  digitalWrite(relay8, LOW);

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected() && currentTime - previousTime <= timeoutTime) {  // loop while the client's connected
      currentTime = millis();
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // turns the GPIOs on and off
            if (header.indexOf("GET /26/on") >= 0) {
              Serial.println("GPIO 26 on");
              relay1State = "on";
              digitalWrite(relay1, HIGH);
            } else if (header.indexOf("GET /26/off") >= 0) {
              Serial.println("GPIO 26 off");
              relay1State = "off";
              digitalWrite(relay1, LOW);
            } else if (header.indexOf("GET /27/on") >= 0) {
              Serial.println("GPIO 27 on");
              relay2State = "on";
              digitalWrite(relay2, HIGH);
            } else if (header.indexOf("GET /27/off") >= 0) {
              Serial.println("GPIO 27 off");
              relay2State = "off";
              digitalWrite(relay2, LOW);
            } else if (header.indexOf("GET /19/on") >= 0) {
              Serial.println("GPIO 19 on");
              relay3State = "on";
              digitalWrite(relay3, HIGH);
            } else if (header.indexOf("GET /19/off") >= 0) {
              Serial.println("GPIO 19 off");
              relay3State = "off";
              digitalWrite(relay3, LOW);
            } else if (header.indexOf("GET /21/on") >= 0) {
              Serial.println("GPIO 21 on");
              relay4State = "on";
              digitalWrite(relay4, HIGH);
            } else if (header.indexOf("GET /21/off") >= 0) {
              Serial.println("GPIO 21 off");
              relay4State = "off";
              digitalWrite(relay4, LOW);
            } else if (header.indexOf("GET /22/on") >= 0) {
              Serial.println("GPIO 22 on");
              relay5State = "on";
              digitalWrite(relay5, HIGH);
            } else if (header.indexOf("GET /22/off") >= 0) {
              Serial.println("GPIO 22 off");
              relay5State = "off";
              digitalWrite(relay5, LOW);
            } else if (header.indexOf("GET /23/on") >= 0) {
              Serial.println("GPIO 23 on");
              relay6State = "on";
              digitalWrite(relay6, HIGH);
            } else if (header.indexOf("GET /23/off") >= 0) {
              Serial.println("GPIO 23 off");
              relay6State = "off";
              digitalWrite(relay6, LOW);
            } else if (header.indexOf("GET /34/on") >= 0) {
              Serial.println("GPIO 34 on");
              relay7State = "on";
              digitalWrite(relay7, HIGH);
            } else if (header.indexOf("GET /34/off") >= 0) {
              Serial.println("GPIO 34 off");
              relay7State = "off";
              digitalWrite(relay7, LOW);
            } else if (header.indexOf("GET /35/on") >= 0) {
              Serial.println("GPIO 35 on");
              relay8State = "on";
              digitalWrite(relay8, HIGH);
            } else if (header.indexOf("GET /35/off") >= 0) {
              Serial.println("GPIO 35 off");
              relay8State = "off";
              digitalWrite(relay8, LOW);
            }
            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family:arial; display: inline-block; margin: 0px auto; text-align: center;background-color:#F9B7FF}");
            client.println(".button { background-color:#66FF00 ; border:2px; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color:#FF0000 ;}</style></head>");
            
            // Web Page Heading
            client.println("<body><h1 style=background-color:#7F38EC;color:white;font-family:algerian;padding:20px 150px>HOME CONTROL DEVICES</h1>");
            client.println("<body><h2 style=background-color:#FFFF00;color:black;font-family:algerian;padding:20px 120px>THE DEVICES ARE:</h2>");
            // Display current state, and ON/OFF buttons for GPIO 26  
            client.println("<p>FAN " + relay1State + "</p>");
            // If the output26State is off, it displays the ON button       
            if (relay1State=="off") {
              client.println("<p><a href=\"/26/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/26/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 
               
            // Display current state, and ON/OFF buttons for GPIO 27  
            client.println("<p>AC " + relay2State + "</p>");
            // If the output27State is off, it displays the ON button       
            if (relay2State=="off") {
              client.println("<p><a href=\"/27/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/27/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            client.println("<p>COOLER " + relay3State + "</p>");
            // If the output26State is off, it displays the ON button       
            if (relay3State=="off") {
              client.println("<p><a href=\"/19/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/19/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 
               
            // Display current state, and ON/OFF buttons for GPIO 27  
            client.println("<p>LIGHT " + relay4State + "</p>");
            // If the output27State is off, it displays the ON button       
            if (relay4State=="off") {
              client.println("<p><a href=\"/21/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/21/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
             client.println("<p>WASHING MACHINE " + relay5State + "</p>");
            // If the output26State is off, it displays the ON button       
            if (relay5State=="off") {
              client.println("<p><a href=\"/22/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/22/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 
               
            // Display current state, and ON/OFF buttons for GPIO 27  
            client.println("<p>FRIDGE " + relay6State + "</p>");
            // If the output27State is off, it displays the ON button       
            if (relay6State=="off") {
              client.println("<p><a href=\"/23/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/23/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            client.println("<p>TELEVISION " + relay7State + "</p>");
            // If the output26State is off, it displays the ON button       
            if (relay7State=="off") {
              client.println("<p><a href=\"/34/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/34/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 
               
            // Display current state, and ON/OFF buttons for GPIO 27  
            client.println("<p>INVERTOR " + relay8State + "</p>");
            // If the output27State is off, it displays the ON button       
            if (relay8State=="off") {
              client.println("<p><a href=\"/35/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/35/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            client.println("</body></html>");
            
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
