//UDP client program
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include<netinet/in.h>
#include <arpa/inet.h>
main(int argc, char *argv[])
{
	int sockfd, rval;
	char buff1[20],buff2[20];
	struct sockaddr_in server, client;
	int len;
	sockfd=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
	if(sockfd==-1)
	{
		perror("\n SOCK_ERR\n");
		exit(1);
	}
	server.sin_family=AF_INET;
	server.sin_addr.s_addr=inet_addr("192.168.131.131");
	server.sin_port=htons(3221);
	printf("\n enter a message \n");
	scanf("%s", buff1);
	rval=sendto(sockfd, buff1, sizeof(buff1),0,(struct sockaddr*)&server,sizeof(server));
	if(rval!=-1)
	{
		printf("\nmessage sent successfully\n");
	}
	else
	{
		perror("\n SEND_ERR\n");
		exit(1);
	}
	len=sizeof(server);
	rval=recvfrom(sockfd,buff1,sizeof(buff1),0,(struct sockaddr*)&server,&len);
	if(rval==-1)
	{
		perror("\nRECV_ERR\n");
		exit(1);
	}
	else
	{
		printf("\n Received Message is %s\n", buff1);
	}
}
