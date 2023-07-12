#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "guta";
const char* password = "guta1234";
const char* serverUrl = "https://leakage.projects.co.tz/api/send-data";
const int sensorId = 3; // Define the sensor ID here

volatile int flow_frequency; // Measures flow sensor pulses
float vol = 0.0, l_minute;
unsigned char flowsensor = D1;
unsigned char ledPin = D7; // LED pin (D7)
unsigned long currentTime;
unsigned long cloopTime;

void ICACHE_RAM_ATTR flow ()
{
  flow_frequency++;
  digitalWrite(ledPin, HIGH); // Turn on the LED when a pulse is detected
}

void setup()
{
  pinMode(flowsensor, INPUT);
  digitalWrite(flowsensor, HIGH);
  pinMode(ledPin, OUTPUT); // Set the LED pin as output
  digitalWrite(ledPin, LOW); // Initially turn off the LED
  Serial.begin(9600);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  attachInterrupt(digitalPinToInterrupt(flowsensor), flow, RISING);

  currentTime = millis();
  cloopTime = currentTime;
}

void loop ()
{
  currentTime = millis();
  if (currentTime >= (cloopTime + 1000))
  {
    cloopTime = currentTime;
    l_minute = (flow_frequency / 7.5);
    vol = vol + (l_minute / 60);
    flow_frequency = 0;
    Serial.print(l_minute, DEC);
    Serial.println(" L/Sec");
    sendSensorData(sensorId, l_minute); // Pass sensor ID and value to the function
    digitalWrite(ledPin, LOW); // Turn off the LED after sending data
  }
}

void sendSensorData(int sensorId, float sensorValue) {
  delay(1000);
  if (WiFi.status() == WL_CONNECTED) {
    String url = String(serverUrl) + "njknkjnk/" + String(sensorId) + "/" + String(sensorValue, 1);
    //String url =  "https://leakage.projects.co.tz/api/send-data/2/0.1";
    Serial.println(url); // Print the URL

    WiFiClient client;
    HTTPClient http;
    http.begin(client, url);
    int httpResponseCode = http.GET();

    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    }
    else {
      Serial.print("Error sending data. HTTP Response code: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  }
  else {
    Serial.println("WiFi Disconnected. Unable to send data.");
  }
}


