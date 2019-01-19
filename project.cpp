#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<fstream>
#include<iostream>
#include <windows.h>
int main()
{	
 HANDLE  hConsole;
	int d;
  	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 9);
int n,numb,numa,numt,a,b,num=1;
scanf("%d %d %d",&numb,&numa,&numt);
printf("_bus(1) : \n_airplain(2) : \n_train(3) : \n");
scanf("%d",&n);
SetConsoleTextAttribute(hConsole, 12);
if(n==1)
	n=numb;
if(n==2)
	n=numa;
if(n==3)
	n=numt;
int *p=new int [n];
int *q=new int [n];

for(int i=0;i<n;i++)
	q[i]=0;
while(1)
{
	printf("\n\n");
	b=0;
	for(int i=0;i<n;i++)
	{
		a=i%3;
		if(q[i])
		{
			b++;
			if(a==2)
				puts("");
			if(a==1)
				printf("\t");
		}
		else
		{
			switch(a)
			{
			case 0:
				printf("[%2d]",i+1);
				break;
			case 1:
				printf("\t[%2d]",i+1);
				break;
			case 2:
				printf("\t\t[%2d]\n",i+1);		
			}
		}
		if(b==n)
			printf("\n\there is not empty space");
	}
			if(q[num-1]>1)
		{
			printf("\n\t it is reserved");
			q[num-1]--;
		}
	printf("\n\nPLEASE ENTER NUMBER : \n");
	scanf("%d",&num);
FILE *ptr;
ptr=fopen("ticks.txt","a");
fprintf(ptr,"%d\t",num);
fclose(ptr);
	q[num-1]++;
	system("cls");
}												
return 0;	
}
