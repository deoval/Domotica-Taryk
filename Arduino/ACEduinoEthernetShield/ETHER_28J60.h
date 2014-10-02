#ifndef ETHER_28J60_h
#define ETHER_28J60_h

#include <inttypes.h>

class ETHER_28J60
{
  public:
    void setup(uint8_t macAddress[], uint8_t ipAddress[], uint16_t port);
	char* serviceRequest();		// returns a char* containing the requestString
								//        or NULL if no request to service
	void print(char* text); 	// append the text to the response
	void print(int value);  	// append the number to the response
	void respond(); 			// write the final response
  private:
	uint16_t _port;

};

#endif
