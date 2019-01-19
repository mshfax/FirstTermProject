/*#include<stdio.h>
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
*/
#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<fstream>
#include<iostream>
#include <windows.h>
using namespace std;
void vehiclefunction(int, int);
void vehiclenumber(int number_vehicle) {



	char vehicle_name[15];
	int capacity_temp, speed_temp, price_temp;
	FILE * vehiclesFile = fopen("Vehicles.txt", "r");
	if (vehiclesFile == NULL)
	{
		cout << "The File opening was Unsuccessful!\n";
		return;
	}




	if (number_vehicle == 1)
	{


		fscanf(vehiclesFile, "\n%s\t%d\t%d\t%d", vehicle_name, &capacity_temp, &speed_temp, &price_temp);

		fseek(vehiclesFile, 0, SEEK_SET);
		vehiclefunction(capacity_temp, number_vehicle);


	}

	else if (number_vehicle == 2)

	{
		fscanf(vehiclesFile, "\n\n\n%s\t%d\t%d\t%d", vehicle_name, &capacity_temp, &speed_temp, &price_temp);

		fseek(vehiclesFile, 0, SEEK_SET);
		vehiclefunction(capacity_temp, number_vehicle);
	}

	else if (number_vehicle == 3)
	{

		fscanf(vehiclesFile, "\n\n\n\n\n%s\t%d\t%d\t%d", vehicle_name, &capacity_temp, &speed_temp, &price_temp);

		fseek(vehiclesFile, 0, SEEK_SET);
		vehiclefunction(capacity_temp, number_vehicle);
	}



}











void vehiclefunction(int capa, int number_vehicle)
{


	int n;


	int a, b, num = 1;

	n = capa;
	int *p = new int[n];
	int *q = new int[n];

	for (int i = 0; i<n; i++)
		q[i] = 0;
	while (1)
	{
		printf("\n\n");
		b = 0;
		for (int i = 0; i<n; i++)
		{
			a = i % 3;
			if (q[i])
			{
				b++;
				if (a == 2)
					puts("");
				if (a == 1)
					printf("\t");
			}
			else
			{
				switch (a)
				{
				case 0:
					printf("[%2d]", i + 1);
					break;
				case 1:
					printf("\t[%2d]", i + 1);
					break;
				case 2:
					printf("\t\t[%2d]\n", i + 1);
				}
			}
			if (b == n)
				printf("\n\there is not empty space");
		}
		if (q[num - 1]>1)
		{
			printf("\n\t it is reserved");
			q[num - 1]--;
		}
		printf("\n\nPLEASE ENTER NUMBER : \n");
		scanf("%d", &num);
		FILE * seatFile = fopen("seat.txt", "a");
		if (seatFile == NULL)
		{
			cout << "The File opening was Unsuccessful!\n";
			return;
		}

		if (number_vehicle == 1)
		{


			fprintf(seatFile, "/n%d\t", num);




		}

		else if (number_vehicle == 2)

		{
			fprintf(seatFile, "/n/n/n%d\t", num);


		}

		else if (number_vehicle == 3)
		{

			fprintf(seatFile, "/n/n/n/n/n%d\t", num);


		}



		q[num - 1]++;
		system("cls");
	}
	fclose(seatFile);

}
