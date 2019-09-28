#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char *argv[])
{
	if(argc!=3)
	{
		printf("Invalid number of arguements.\nEnter source file name and then destination file name\n.");
		exit(1);
	}

	char buff[1024];
	int destfd=open(argv[2],O_CREAT|O_RDWR|O_TRUNC,00600);
	if(destfd<0)
	{
		perror("Open dest");
		exit(1);
	}
	int srcfd=open(argv[1],O_RDONLY);
	if(srcfd<0)
	{
		perror("Open src");
		exit(1);
	}
	int n;
	for(;;)
	{
		n=read(srcfd,buff,1024);
		if(n<=0)
		{
			close(srcfd);
			close(destfd);
			return 0;
		}
		write(destfd,buff,n);
	}
	return 0;
}


