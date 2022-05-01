#include <DHT.h>
#include <ESP8266.h>


#define DHTPIN 2
#define DHTTYPE DHT22

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(A0, INPUT);
  pinMode(2, INPUT);
  dht.begin();

  Serial.println("Connecting...");
  Serial.println(said);
  WiFi.begin(said, password);

  
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  
  
  Serial.println("");
  Serial.println("WiFi Connected");
  Serial.print(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
  WiFiClient client = server.available();
  if(client)
  {
    return;
  }
  //Wait until the client gets data
  Serial.print("new Client");
  
  while(client.available())
  {
    delay(1000);
  }

  
  client.println("HTTP/1.1");
  client.println("Content-Type: text/html");
  
  
  float output= analogRead(sensor_pin);
  float h=dht.readHumidity();
  float t= dht.readTemperature();

  Serial.println(h);
  Serial.println(t);

   if(h<70.0 && t<36)
   {
    client.println("<h1>Monitoring Of Pesticide</h1><h3>TEMP:"String(t)+"'C</h3> <h4>moisture:"+"AIR Quality"+AQI+"ppm</h4>");
    
   }
   else
   {
    client.println("<h1>Monitoring Of Pesticide</h1><h3>TEMP:"String(t)+"'C</h3> <h4>moisture:"+"AIR Quality"+AQI+"ppm</h4>")
   }
  
   
   client.println("<\html>");
   Serial.println("Client Disconnected");
}
