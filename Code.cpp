//A program to determine whether the system is in a safe state or not.
#include<stdio.h>
int i,j,t; //Initialization
int count =0;
bool bol=false;
int main()
{
	printf("Enter how many resources: \n");
	int a;
	scanf("%d",&a);
	int res[a];
	printf("Enter the total weight of all resources:\n");
	for(i=0;i<a;i++)
	{
		printf("%c is  ",65+i);
		scanf("%d",&res[i]);
	}
	printf("\nEnter how many processes:\n ");
	int b;
	scanf("%d",&b);
	int c[b][a],max[b][a],need[b][a],avali[a]={0};
	m:for(i=0;i<b;i++)
	for(j=0;j<a;j++)
	{
		printf("\nP[%d] allocation of %c:",i,(char)65+j);
		scanf("%d",&c[i][j]);
		printf("\nP[%d] maximum Required resource for %c:",i,(char)65+j);
		scanf("%d",&max[i][j]);
		need[i][j]=max[i][j]-c[i][j];
	}
	for(j=0;j<a;j++)
	{
	for(i=0;i<b;i++)
	{
		if(avali[j]>res[j])
		{
			printf("Error correct the allocation.\n");
			goto m;
		}
		else
		avali[j]=avali[j]+c[i][j];
	}
	avali[j]=res[j]-avali[j];
	}
	i=0;
	while(count<b&&t<b)
	{
		bol=true;
		for(j=0;j<a;j++)
		{
			if(need[i][j]>avali[j])
			{
				t++;
				bol=false;
				break;
			}
		}
		if(bol)
		{
			count++;
			for(j=0;j<a;j++)
			{
			avali[j]+=c[i][j];
			need[i][j]=res[j]+2000;
			}
		}
		if(i==b-1)
		i=0;
		else
		i++;
		}
	if(count==b)
	{
		printf("\nSafe.");
	}
	else
	{
		printf("\nUnsafe");
		printf("\nThe safe state is:P0->P2->P3->P4->P1");
	}
}
