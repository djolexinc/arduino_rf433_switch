#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile

RH_ASK driver;
const int LEDpin=4;

void setup()
{
    pinMode(LEDpin,OUTPUT);
    Serial.begin(9600);  // Debugging only
    if (!driver.init())
         Serial.println("Initialization failed");
    else Serial.println("Initialization complete, reciver firmware: V1.0.0, Djolex");
}

void loop()
{
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen)) // Non-blocking
    {
      if(buf[0]=='1')
      {
       delay(150);
       Serial.println("On command: key 1");    
       digitalWrite(LEDpin,1);      
      }
      if(buf[0]=='0')
      {
         delay(150);
        Serial.println("On command: key 0");
        digitalWrite(LEDpin,0);
      }      
      }
}
