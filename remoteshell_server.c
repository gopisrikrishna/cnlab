#include <stdio.h> 
#include <fcntl.h> 
#include <sys/types.h> 
#include<stdlib.h>
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 
main(int argc,char *argv[])
{
 
	int sockfd, new_sockfd, rval, fd; 
	char buff1[400],buff2[400]; 
	struct sockaddr_in server, client; 
	int len;
	sockfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP); 
	if(sockfd==-1)
	{
		perror("\nsock_error\n"); 
		exit(1);
	}
	server.sin_family=AF_INET; 
	server.sin_addr.s_addr=inet_addr(argv[1]);
	server.sin_port=htons(atoi(argv[2])); 
	rval=bind(sockfd,(struct sockaddr*)&server,sizeof(server)); 
	if(rval!=-1)
	{
		listen(sockfd,5); 
		while(1)
		{
			len=sizeof(client);
			new_sockfd=accept(sockfd,(struct sockaddr*)&client,&len); 				if(new_sockfd!=-1)
			{		 
				rval=recv(new_sockfd,buff1,sizeof(buff1),0); 					if(rval==-1)
				{
					perror("\n recev_error\n"); exit(1);
				}
				else
				{
					strcat(buff1,">file.txt"); 
					system(buff1);
					fd=open("file.txt",O_RDONLY,0666); 
					if(fd==-1)
					{
						printf("\n file_error\n"); 
						exit(1);
					}
					read(fd,buff2,sizeof(buff2));
				}
				rval=send(new_sockfd,buff2,sizeof(buff2),0); 
				if(rval!=-1)
				{
					printf("\n message sent successfully!\n");
				} 
				else
				{
					perror("\n send_error\n"); 
					exit(1);
				}
			}
			else
			{
				perror("\n accept_error"); 
				exit(1);
			}
		}
	}
	else
	{
		perror("\n bind_error\n"); 
		close(sockfd);
	}
}

