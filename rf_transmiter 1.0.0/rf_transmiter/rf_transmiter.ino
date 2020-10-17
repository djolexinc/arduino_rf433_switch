#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;

void setup()
{
    Serial.begin(9600);    // Debugging only
    if (!driver.init()) Serial.println("Intialization failed");
    else Serial.println("Intialization completed. Software version 1.0");
    Serial.println("Your command: 1-LED ON, 0-LED OFF");
}

void loop()
{
    int incomingData= Serial.read(); // can be -1 if read error
    switch(incomingData) 
    {
       case '1':
          sendMessage("1");
          Serial.println("");
          break;

       case '0':
          sendMessage("0");
          Serial.println("");
          break;
           
       default:
          break;
    }
}

void sendMessage(char *text)
{
    driver.send((uint8_t *)text, strlen(text));
    driver.waitPacketSent();
    Serial.print("Package sent:  ");
    Serial.println(text);
    delay(5000);
}
