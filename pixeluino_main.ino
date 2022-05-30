
#include <SPI.h>
#include <WiFi101.h>
#include <LedControl.h>

int DIN = 7;
int CS =  6;
int CLK = 5;
LedControl lc=LedControl(DIN,CLK,CS,0);

char ssid[] = "";      // your network name   
char pass[] = "";      // your network password
int keyIndex = 0;                 
int status = WL_IDLE_STATUS;     
WiFiServer server(80);         

WiFiClient client = server.available();

int ledPin = 2;

void setup() {
  lc.shutdown(0,false);      
  lc.setIntensity(0,15);      
  lc.clearDisplay(0);   
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  while (!Serial);

  enable_WiFi();
  connect_WiFi();

  server.begin();
  printWifiStatus();
}

void loop() {
  client = server.available();

  if (client) {
    printWEB();
  }
}

void printWifiStatus() {

  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  Serial.print("Open: http://");
  Serial.println(ip);
}

void enable_WiFi() {

  String fv = WiFi.firmwareVersion();
  if (fv < "1.0.0") {
    Serial.println("Update your firmware.");
  }
}

void connect_WiFi() {
  while (status != WL_CONNECTED) {
    Serial.print("Trying to connect to SSID: ");
    Serial.println(ssid);
    // korstin WPA
    status = WiFi.begin(ssid, pass);
    delay(10000);
  }
}

void printWEB() {

  if (client) {                             
    Serial.println("New client");          
    String currentLine = "";                
    while (client.connected()) {            
      if (client.available()) {             
        char c = client.read();             
        Serial.write(c);                    
        if (c == '\n') {                    


          if (currentLine.length() == 0) {

            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

           client.println("<!DOCTYPE html>");
           client.println("<html lang=\"en\">");
            client.println("<head> <meta charset=\"UTF-8\"> <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\"> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"> <title>Arduino Crtanje2</title></head>");
           client.println("<body>");
            client.println("<style>body{text-align: center;}h2{margin-top: 50px;}.block{display: inline-block; background: #373435; text-align: center; border-radius: 5%; height: 300px; width: 300px; margin-left: auto; margin-right: auto;}.button{background-color: #fff; color: transparent; border-radius: 50%; margin-left: 5px; width: 27px; height: 27px; margin-left: auto; margin-right: auto;}.top{display: inline-block; width: 2em; height: 1.5em; border: 0.5em solid #333; border-radius: 50%;}.kocka{margin-top: 10px; height: 27px; display: flex; bottom: 27px;}.kockavrh{margin-top: 7.5px; height: 27px; display: flex; bottom: 27px;}.kockadno{margin-top: 10px; height: 27px; display: flex; bottom: 27px;}#btnRefresh{background: transparent; border-color: transparent; width: 50px; height: 50px; border-radius: 50%; margin-left: 310px; display: flex; margin-top: -35px;}#img2{width: 30px; height: 30px;}</style>");
           client.println("<h2> Crtaj Ovdje! </h2>");
            client.println("<div class=\"container\">");
            client.println("<div class=\"block\">");
            client.println("<div class=\"kockavrh\"> <div class=\"button\"id=\"button1-0\"></div><div class=\"button\"id=\"button2-0\"></div><div class=\"button\"id=\"button3-0\"></div><div class=\"button\"id=\"button4-0\"></div><div class=\"button\"id=\"button5-0\"></div><div class=\"button\"id=\"button6-0\"></div><div class=\"button\"id=\"button7-0\"></div><div class=\"button\"id=\"button8-0\"></div></div>");
            client.println("<div class=\"kocka\"> <div class=\"button\"id=\"button1-1\"></div><div class=\"button\"id=\"button2-1\"></div><div class=\"button\"id=\"button3-1\"></div><div class=\"button\"id=\"button4-1\"></div><div class=\"button\"id=\"button5-1\"></div><div class=\"button\"id=\"button6-1\"></div><div class=\"button\"id=\"button7-1\"></div><div class=\"button\"id=\"button8-1\"></div></div>");
            client.println("<div class=\"kocka\"> <div class=\"button\"id=\"button1-2\"></div><div class=\"button\"id=\"button2-2\"></div><div class=\"button\"id=\"button3-2\"></div><div class=\"button\"id=\"button4-2\"></div><div class=\"button\"id=\"button5-2\"></div><div class=\"button\"id=\"button6-2\"></div><div class=\"button\"id=\"button7-2\"></div><div class=\"button\"id=\"button8-2\"></div></div>");
            client.println("<div class=\"kocka\"> <div class=\"button\"id=\"button1-3\"></div><div class=\"button\"id=\"button2-3\"></div><div class=\"button\"id=\"button3-3\"></div><div class=\"button\"id=\"button4-3\"></div><div class=\"button\"id=\"button5-3\"></div><div class=\"button\"id=\"button6-3\"></div><div class=\"button\"id=\"button7-3\"></div><div class=\"button\"id=\"button8-3\"></div></div>");
            client.println("<div class=\"kocka\"> <div class=\"button\"id=\"button1-4\"></div><div class=\"button\"id=\"button2-4\"></div><div class=\"button\"id=\"button3-4\"></div><div class=\"button\"id=\"button4-4\"></div><div class=\"button\"id=\"button5-4\"></div><div class=\"button\"id=\"button6-4\"></div><div class=\"button\"id=\"button7-4\"></div><div class=\"button\"id=\"button8-4\"></div></div>");
            client.println("<div class=\"kocka\"> <div class=\"button\"id=\"button1-5\"></div><div class=\"button\"id=\"button2-5\"></div><div class=\"button\"id=\"button3-5\"></div><div class=\"button\"id=\"button4-5\"></div><div class=\"button\"id=\"button5-5\"></div><div class=\"button\"id=\"button6-5\"></div><div class=\"button\"id=\"button7-5\"></div><div class=\"button\"id=\"button8-5\"></div></div>");
            client.println("<div class=\"kocka\"> <div class=\"button\"id=\"button1-6\"></div><div class=\"button\"id=\"button2-6\"></div><div class=\"button\"id=\"button3-6\"></div><div class=\"button\"id=\"button4-6\"></div><div class=\"button\"id=\"button5-6\"></div><div class=\"button\"id=\"button6-6\"></div><div class=\"button\"id=\"button7-6\"></div><div class=\"button\"id=\"button8-6\"></div></div>");
            client.println("<div class=\"kockadno\"> <div class=\"button\"id=\"button1-7\"></div><div class=\"button\"id=\"button2-7\"></div><div class=\"button\"id=\"button3-7\"></div><div class=\"button\"id=\"button4-7\"></div><div class=\"button\"id=\"button5-7\"></div><div class=\"button\"id=\"button6-7\"></div><div class=\"button\"id=\"button7-7\"></div><div class=\"button\"id=\"button8-7\"></div></div>");
            client.println("<script>");  
            client.println("let allButtons=document.querySelectorAll(\"div[id^=button]\"),rbtn=document.getElementById(\"btnRefresh\");const xhr=new XMLHttpRequest;let urlSearch=window.location.href;for(var i=0;i<allButtons.length;i++)allButtons[i].addEventListener(\"click\",function(){console.clear(),console.log(\"Stisnuli ste:\",this.id);let o=this.id;document.getElementById(this.id).style.backgroundColor=\"#FF3622\";let t=window.location.protocol+\"//\"+window.location.host+window.location.pathname+o;window.history.pushState({path:t},\"\",t),xhr.open(\"GET\",t),xhr.send();let n=window.location.origin;window.history.pushState({path:n},\"\",n)});performance.navigation.type==performance.navigation.TYPE_RELOAD?(xhr.open(\"GET\",window.location.protocol+\"//\"+window.location.host+window.location.pathname+\"buttonR\"),xhr.send(),window.history.pushState(void 0,void 0,window.location.origin)):(console.clear(),console.log(\"Testirano na Mozilla Firefox, 100.00 64bit Manjaro Linux\"));");
            client.println("</script>");

            client.println();
            break;
          }
          else {      
            currentLine = "";
          }
        }
        else if (c != '\r') {    
          currentLine += c;      
        }

        
        if (currentLine.endsWith("/buttonR")) { 
          lc.clearDisplay(0);
        }
        if (currentLine.endsWith("/button1-0")) {
          Serial.println(currentLine);
          lc.setLed(0,0,0,true);
        }
        if (currentLine.endsWith("/button2-0")) {
          Serial.println(currentLine);
          lc.setLed(0,0,1,true);
        }
        if (currentLine.endsWith("/button3-0")) {
          lc.setLed(0,0,2,true);
        }
        if (currentLine.endsWith("/button4-0")) {
          lc.setLed(0,0,3,true);
        }
        if (currentLine.endsWith("/button5-0")) {
          lc.setLed(0,0,4,true);
        }
        if (currentLine.endsWith("/button6-0")) {
          lc.setLed(0,0,5,true);
        }
        if (currentLine.endsWith("/button7-0")) {
          lc.setLed(0,0,6,true);
        }
        if (currentLine.endsWith("/button8-0")) {
          lc.setLed(0,0,7,true);
        }
        if (currentLine.endsWith("/button1-1")) {
          lc.setLed(0,1,0,true);
        }
        if (currentLine.endsWith("button2-1")) {
          lc.setLed(0,1,1,true);
        }
        if (currentLine.endsWith("button3-1")) {
          lc.setLed(0,1,2,true);
        }
        if (currentLine.endsWith("button4-1")) {
          lc.setLed(0,1,3,true);
        }
        if (currentLine.endsWith("button5-1")) {
          lc.setLed(0,1,4,true);
        }
        if (currentLine.endsWith("button6-1")) {
          lc.setLed(0,1,5,true);
        }
        if (currentLine.endsWith("button7-1")) {
          lc.setLed(0,1,6,true);
        }
        if (currentLine.endsWith("button8-1")) {
          lc.setLed(0,1,7,true);
        }
        if (currentLine.endsWith("button1-2")) {
          lc.setLed(0,2,0,true);
        }
        if (currentLine.endsWith("button2-2")) {
          lc.setLed(0,2,1,true);
        }
        if (currentLine.endsWith("button3-2")) {
          lc.setLed(0,2,2,true);
        }
        if (currentLine.endsWith("button4-2")) {
          lc.setLed(0,2,3,true);
        }
        if (currentLine.endsWith("button5-2")) {
          lc.setLed(0,2,4,true);
        }
        if (currentLine.endsWith("button6-2")) {
          lc.setLed(0,2,5,true);
        }
        if (currentLine.endsWith("button7-2")) {
          lc.setLed(0,2,6,true);
        }
        if (currentLine.endsWith("button8-2")) {
          lc.setLed(0,2,7,true);
        }
        if (currentLine.endsWith("button1-3")) {
          lc.setLed(0,3,0,true);
        }
        if (currentLine.endsWith("button2-3")) {
          lc.setLed(0,3,1,true);
        }
        if (currentLine.endsWith("button3-3")) {
          lc.setLed(0,3,2,true);
        }
        if (currentLine.endsWith("button4-3")) {
          lc.setLed(0,3,3,true);
        }
        if (currentLine.endsWith("button5-3")) {
          lc.setLed(0,3,4,true);
        }
        if (currentLine.endsWith("button6-3")) {
          lc.setLed(0,3,5,true);
        }
        if (currentLine.endsWith("button7-3")) {
          lc.setLed(0,3,6,true);
        }
        if (currentLine.endsWith("button8-3")) {
          lc.setLed(0,3,7,true);
        }
        if (currentLine.endsWith("button1-4")) {
          lc.setLed(0,4,0,true);
        }
        if (currentLine.endsWith("button2-4")) {
          lc.setLed(0,4,1,true);
        }
        if (currentLine.endsWith("button3-4")) {
          lc.setLed(0,4,2,true);
        }
        if (currentLine.endsWith("button4-4")) {
          lc.setLed(0,4,3,true);
        }
        if (currentLine.endsWith("button5-4")) {
          lc.setLed(0,4,4,true);
        }
        if (currentLine.endsWith("button6-4")) {
          lc.setLed(0,4,5,true);
        }
        if (currentLine.endsWith("button7-4")) {
          lc.setLed(0,4,6,true);
        }
        if (currentLine.endsWith("button8-4")) {
          lc.setLed(0,4,7,true);
        }
        if (currentLine.endsWith("button1-5")) {
          lc.setLed(0,5,0,true);
        }
        if (currentLine.endsWith("button2-5")) {
          lc.setLed(0,5,1,true);
        }
        if (currentLine.endsWith("button3-5")) {
          lc.setLed(0,5,2,true);
        }
        if (currentLine.endsWith("button4-5")) {
          lc.setLed(0,5,3,true);
        }
        if (currentLine.endsWith("button5-5")) {
          lc.setLed(0,5,4,true);
        }
        if (currentLine.endsWith("button6-5")) {
          lc.setLed(0,5,5,true);
        }
        if (currentLine.endsWith("button7-5")) {
          lc.setLed(0,5,6,true);
        }
        if (currentLine.endsWith("button8-5")) {
          lc.setLed(0,5,7,true);
        }
        if (currentLine.endsWith("button1-6")) {
          lc.setLed(0,6,0,true);
        }
        if (currentLine.endsWith("button2-6")) {
          lc.setLed(0,6,1,true);
        }
        if (currentLine.endsWith("button3-6")) {
          lc.setLed(0,6,2,true);
        }
        if (currentLine.endsWith("button4-6")) {
          lc.setLed(0,6,3,true);
        }
        if (currentLine.endsWith("button5-6")) {
          lc.setLed(0,6,4,true);
        }
        if (currentLine.endsWith("button6-6")) {
          lc.setLed(0,6,5,true);
        }
        if (currentLine.endsWith("button7-6")) {
          lc.setLed(0,6,6,true);
        }
        if (currentLine.endsWith("button8-6")) {
          lc.setLed(0,6,7,true);
        }
        if (currentLine.endsWith("button1-7")) {
          lc.setLed(0,7,0,true);
        }
        if (currentLine.endsWith("button2-7")) {
          lc.setLed(0,7,1,true);
        }
        if (currentLine.endsWith("button3-7")) {
          lc.setLed(0,7,2,true);
        }
        if (currentLine.endsWith("button4-7")) {
          lc.setLed(0,7,3,true);
        }
        if (currentLine.endsWith("button5-7")) {
          lc.setLed(0,7,4,true);
        }
        if (currentLine.endsWith("button6-7")) {
          lc.setLed(0,7,5,true);
        }
        if (currentLine.endsWith("button7-7")) {
          lc.setLed(0,7,6,true);
        }
        if (currentLine.endsWith("button8-7")) {
          lc.setLed(0,7,7,true);
        }
        
        

      }
    }
    client.stop();
    Serial.println("Client disconnected");
  }
}
