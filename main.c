#include <stdio.h>
#include "Socket.h"
char buffer[4096] = { 0 };
void main()
{
	Socket_Client_Init("54.192.22.61", 80);
	Send("GET /v1/bpi/currentprice.json HTTP/1.1\r\nHost: api.coindesk.com\r\n\r\n");
	Recv(buffer, sizeof(buffer));
	char* keyStart = "\"rate_float\":";
	char* startPos = strstr(buffer, keyStart);
	startPos += strlen(keyStart);
	char bitcoinPrice[32] = { 0 };
	int index = 0;
	while (startPos[index] != '}')
	{
		bitcoinPrice[index] = startPos[index];
		index++;
	}
	printf("bit coin price: %s USD\r\n", bitcoinPrice);
}