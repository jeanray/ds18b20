#include <OneWire.h> 
#include <DallasTemperature.h>
// Over inkluderes bibliotekene vi trenger for onewire og for temp-sensoren (ds18b20)

int oneWirePin = 4; // Hvilken arduino-pin som enheten(e) er koblet til
// Husk pull-up resistor fra positiv leder (+) over til datalinjen fra sensoren (bruk 4,7k ohm)

OneWire oneWireReferanse(oneWirePin);
DallasTemperature sensorBussObjekt(&oneWireReferanse);

void setup(void)
{
	Serial.begin(115200); // Starter serial med baud rate på 115200

	// Printer initial text som kjøres første gang serial monitoren start
	Serial.println("Program som avleser ds18b20-sensor på en onewire-bus");

	sensorBussObjekt.begin(); 	// Kjører begin på biblioteket

	// "begin" er en del av core arduino bibliotekene

}
void loop(void)
{
	
	sensorBussObjekt.requestTemperatures(); // Vi henter alle temperaturer fra alle ev. sensorer på onewire-bussen 

	Serial.print(sensorBussObjekt.getTempCByIndex(0)); 
	// Printer temperaturen vi hentet fra enhet 0 - ByIndex(0) - enhet 0 er første enheten på bussen om det er flere
	// Alternativt er å adressere onewire-objektet med hele hex-adressen

	Serial.print(";"); // Vi bygger en semikolonbasert fil

	Serial.println(millis() / 100); // Vi viser tiendeler av oppetiden til arduinoen

	delay(100);
}