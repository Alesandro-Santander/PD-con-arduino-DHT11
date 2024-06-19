#include "DHT.h"
//libreria DHT.h
#define DHTPIN 2
#define DHTTYPE DHT11
//Definimos el PIN 2 y el tipo de sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}
// El void setup se usa para iniciar variablesla comunicación serial a una velocidad es de 9600 bits por segundo
void loop() {
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
// Se declara las varables flotamtes donde las variables son de temperatura y humedad, tambien vemos el mensaje si el sensor esta mal conectado  
  float adjusted_h = h * 1.2; // Aumentar el valor de humedad en un 20%
  float adjusted_t = t + 5;   // Aumentar la temperatura en 5 grados

  // Enviar la temperatura y la humedad ajustadas a Pure Data
  Serial.print("Temperature ");
  Serial.println(adjusted_t);
  Serial.print("Humidity ");
  Serial.println(adjusted_h);
}