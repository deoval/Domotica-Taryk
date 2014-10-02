// The Unnamed Circuit
// 
// Made by James Weslley

#include "etherShield.h"
#include "ETHER_28J60.h"

int cooler = 5; //cooler aciona no pino 5 
int led1 = 6; //led1 aciona no pino 6 
int led2 = 7; //led2 aciona no pino 7 


static uint8_t mac[6] = {0xAA, 0xBB, 0xCC, 0xDD, 0xBB, 0xAA};   // mac ex. modificar para adequado
                                                          
static uint8_t ip[4] = {192, 168, 0, 15};                       //ip ex. Modificar para adequado
static uint16_t port = 80;                                      // Porta 80 - padrão para http

ETHER_28J60 e;

void setup()
{
    e.setup(mac, ip, port);
   
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
  	pinMode(cooler, OUTPUT);
   
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  	digitalWrite(cooler, LOW);

 
}

void loop()
{
  char* params;
  if (params = e.serviceRequest())
  {
    // em cmd, o primeiro número representa o item da maquete (led1(1), led2(2), cooler(3)); o segundo, on(1) e off(0)
    if (strcmp(params, "?cmd=11") == 0) // Led1(1) on(1)
    {
          digitalWrite(led1, HIGH);
    }
    if (strcmp(params, "?cmd=10") == 0) // led1(1) off(0) 
    {
          digitalWrite(led1, LOW);
         
    }
    if (strcmp(params, "?cmd=21") == 0) // led2(2) on(1)
    {
          digitalWrite(led2, HIGH);
    }
    if (strcmp(params, "?cmd=20") == 0) // led2(2) off(0)
    {
          digitalWrite(led2, LOW);
         
    }
        if (strcmp(params, "?cmd=31") == 0) // cooler(3) on(1)
    {
          digitalWrite(cooler, HIGH);
    }
    if (strcmp(params, "?cmd=30") == 0) // cooler(3) off(0)
    {
          digitalWrite(cooler, LOW);
         
    }
   
    e.respond();
  }
}
