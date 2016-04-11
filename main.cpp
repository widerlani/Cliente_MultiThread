/* main.cpp - Generated by Visual Multi-Thread Win32 */

#include <stdlib.h>
#include <stdio.h>
#include "AppObjects.h"
#include "my_socket.h"
#define DEFAULT_PORT "5000"

extern DWORD WINAPI thread_Cliente(LPVOID lpParameter);
int main(int argc, char *argv[]);

int main(int argc, char *argv[])
{
	SocketParams params;
	strcpy(params.port, DEFAULT_PORT);
	//strcpy(params.ip, "127.0.0.1");	//localhost //essa porra n�o funciona
	
	if (argc != 2) {
		printf("modo de usar: cliente ip_do_servidor\n");
		exit(1);
		}
	params.ip= argv[1];
	
	params.family = AF_UNSPEC;	    // unspecified so that either an IPv6 or IPv4 address can be returned
	params.socktype = SOCK_STREAM;  // stream socket for the TCP protocol
	params.protocol= IPPROTO_TCP;   // TCP protocol
	
	Cliente = CreateThread(0, 0,(LPTHREAD_START_ROUTINE) thread_Cliente, &params, 0, 0);
	WaitForSingleObject(Cliente, INFINITE);
}
