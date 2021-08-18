#include<stdio.h>
#include<string.h>
#include<sys/select.h>
int main(int argc,char *argv[])
{
	int fd=0,ret,sret;
	char buf[11];
	fd_set readfds;
	struct timeval timeout;
	while(1)
	{
		FD_ZERO(&readfds);
		FD_SET(fd,&readfds);
		timeout.tv_sec=5;
		timeout.tv_usec=0;
		sret=select(8,&readfds,NULL,NULL,&timeout);
		if(sret==0)
		{
			printf("\nsret=%d\n",sret);
			printf("Time Out\n");			
		}
		else
		{
			printf("\nsret=%d\n",sret);
			memset((void *) buf,0,11);
			ret=read(fd,(void *) buf,10);
			printf("ret=%d\n",ret);
			if(ret!=-1)
			{
				printf("buf=%s\n",buf);
			}
		}
	}
	return 0;
}

