#include<stdio.h>
#include<stdlib.h>

#define max 16

int a[max]={1,5,7,10,12,14,15,18,20,22,25,27,300,64,110,220};

int maximum()
{
	int i;
	int maxs=0;
	for(i=0;i<max;i++)
	{
		if(a[i]>maxs)
			maxs=a[i];
	}
	return maxs;
}
int main()
{
	int maxs=0;
	int i;
	
	printf("Maximum Element is :%d\n",maximum());
	return 0;
}
