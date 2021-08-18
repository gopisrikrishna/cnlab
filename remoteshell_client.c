#include <stdio.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <arpa/inet.h> 
#include<netinet/in.h>
main(int argc, char *argv[])
{ 
	int sockfd,rval;
	char buff1[400],buff2[400]; 
	struct sockaddr_in server;
	sockfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP); 
	if(sockfd==-1)
	{
		perror("\nSOCK_ERR\n"); exit(1);
	}
	server.sin_family=AF_INET; 
	server.sin_addr.s_addr=inet_addr(argv[1]);
	server.sin_port=htons(atoi(argv[2])); 
	rval=connect(sockfd,(struct sockaddr*)&server,sizeof(server)); 
	if(rval!=-1)
	{ 
		printf("\n Enter any shell command: \n"); 
		scanf("%s",buff1); 
		rval=send(sockfd,buff1,sizeof(buff1),0); 
		if(rval==-1)
		{
			perror("\nSEND_ERR\n"); 
			exit(1);
		}
		rval=recv(sockfd,buff2,sizeof(buff2),0); 
		if(rval!=-1)
		{
			printf("\n received data is:%s\n", buff2);
		}
		else
		{
			printf("\n RECV_ERR\n");
		}
	}
	else
	{
		perror("\nCONNECT_ERR\n");
	}
}
