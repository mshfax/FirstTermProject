//
// Created by mostafa on 12/29/18.
//needs to be completed


#ifndef PROJECT_DRIVERS_H
#define PROJECT_DRIVERS_H

#endif //PROJECT_DRIVERS_H



#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
//functions declaration
void declareTrip(int);//completed
void seePassengersInfo();
void cancelDelayTrip();
void historyOfTrips(int);//completed

void driversMain(int username)  //function to clear what admin wants to do
{
	int n;
	while (1)
	{
		cout << "Enter the number of task you want to do please...\n";
		cout << "1. declare a trip\n";
		cout << "2. see all passengers Info\n";
		cout << "3. cancel or delay of a trip\n";
		cout << "4. see history of all trips\n";
		cout << "0. Exit\n";
		cin >> n;
		if (n == 1)
		{
			declareTrip(username);
		}
		else if (n == 2)
		{
			seePassengersInfo();
		}
		else if (n == 3)
		{
			cancelDelayTrip();
		}
		else if (n == 4)
		{
			historyOfTrips(username);
		}
		else if (n == 0)
		{
			return;
		}
		else
		{
			cout << "The number you inserted is not correct!\n";
			return;
		}
	}
}

//definition functions
void declareTrip(int username)   //computing the finish hour has some don't know ploblems
{
	//need to be completed
	FILE * citiesFile = fopen("cities.txt", "r");
	FILE * tripsFile = fopen("Trips.txt", "a");
	FILE * driversFile = fopen("Drivers.txt", "r");
	if (citiesFile == NULL || tripsFile == NULL || driversFile == NULL)
	{
		cout << "The File opening was Unsuccessful!\n";
		return;
	}
	//main code here
	int origin, destination, hourStartTrip, minuteStartTrip, year, month, day;
	cout << "Enter origin city\n";
	cin >> origin;
	cout << "Enter destination city\n";
	cin >> destination;
	cout << "Enter start hour of the trip\n";
	cin >> hourStartTrip;
	cout << "Enter start minute of the trip\n";
	cin >> minuteStartTrip;
	cout << "Set the date of the trip   year/month/day\n";
	/*cout << "year:";
	cin >> year;
	cout << "\n";
	cout << "month:";
	cin >> month;
	cout << "\n";
	cout << "day:";
	cin >> day;*/
	scanf("%d/%d/%d", &year, &month, &day);
	//find the cities and save the origin and destination x and y
	//origin
	int originX = 0, originY = 0, tempOrigin, a = 0, b = 0;
	fscanf(citiesFile, "%d\t%d\t%d", &tempOrigin, &a, &b);
	int i = getc(citiesFile);
	fseek(citiesFile, -1, SEEK_CUR);
	int j = 1;
	while (i != EOF)
	{
		if (tempOrigin == origin)
		{
			originX = a;
			originY = b;
			j = 0;
			break;
		}
		else
		{
			fscanf(citiesFile, "%d\t%d\t%d", &tempOrigin, &a, &b);
			i = getc(citiesFile);
		}
	}
	if (j)
	{
		cout << "Sorry the number you have entered is not correct!! Try again\n";
		return;
	}
	fseek(citiesFile, 0, SEEK_SET);
	//destination
	int destinationX = 0, destinationY = 0, tempDestination;
	fscanf(citiesFile, "%d\t%d\t%d", &tempDestination, &a, &b);
	i = getc(citiesFile);
	fseek(citiesFile, -1, SEEK_CUR);

	j = 1;
	while (i != EOF)
	{
		if (tempDestination == destination)
		{
			destinationX = a;
			destinationY = b;
			j = 0;
			break;
		}
		else
		{
			fscanf(citiesFile, "%d\t%d\t%d", &tempDestination, &a, &b);
			i = getc(citiesFile);
		}
	}
	if (j)
	{
		cout << "Sorry the number you have entered is not correct!! Try again\n";
		return;
	}
	//computing the distance
	float distance = sqrt(((originX - destinationX)*(originX - destinationX)) + ((originY - destinationY)*(originY - destinationY)));
	//complete trip time and get vehicle and the trip of the driver and print in the file
	char vehicle[15];
	int userName_temp, pass_temp, accountNumber;
	char firstName[30], lastName[30], phone[15], vehicle_temp[15];
	fscanf(driversFile, "\n%d\t%d\t%d\t%s\t%s\t%s\t%s", &userName_temp, &pass_temp, &accountNumber, firstName, lastName, phone, vehicle_temp);
	//i = getc(driversFile);
	//j = 1;
	for (j = 0; j < 10000; j++)
	{
		if (userName_temp == username)
		{
			strcpy(vehicle, vehicle_temp);//got vehicle
										  //j=0;
			break;
		}
		else
		{
			fscanf(driversFile, "\n%d\t%d\t%d\t%s\t%s\t%s\t%s", &userName_temp, &pass_temp, &accountNumber, firstName, lastName, phone, vehicle_temp);
			//i = getc(driversFile);
		}
	}
	if (j == 100000)
	{
		cout << "Sorry the number you have entered is not correct!! Try again\n";
		return;
	}
	char vehicle_name[15];
	int capacity_temp, speed_temp, price_temp;
	int speed = 0, price = 0;
	//open vehicles file for speed
	FILE * vehiclesFile = fopen("Vehicles.txt", "r");
	if (vehiclesFile == NULL)
	{
		cout << "The File opening was Unsuccessful!\n";
		return;
	}
	for (int i = 0; i<6; i++)
	{
		fscanf(vehiclesFile, "\n%s\t%d\t%d\t%d\n", vehicle_name, &capacity_temp, &speed_temp, &price_temp);
		if (strcmp(vehicle, vehicle_name) == 0)
		{
			speed = speed_temp;
			price = price_temp;
			break;
		}
	}
	int time = (distance / speed) * 60;
	int tempHourTime = time / 60;
	float tempMinuteTime = time % 60;
	tempMinuteTime /= 10;
	tempMinuteTime = nearbyint(tempMinuteTime);
	tempMinuteTime *= 10;
	//check that minute and hour finish trip be fewer than 60
	if (tempMinuteTime >= 60)
	{
		tempHourTime++;
		tempMinuteTime -= 60;
	}
	//round with 30 minute accuracy (Drop accurately 30 minutes)
	if (tempMinuteTime < 10)
	{
		tempMinuteTime = 0;
	}
	else if (tempMinuteTime <= 30)
	{
		tempMinuteTime = 30;
	}
	else if (tempMinuteTime < 40)
	{
		tempMinuteTime = 30;
	}
	else if (tempMinuteTime < 60)
	{
		tempMinuteTime = 0;
		tempHourTime++;
	}
	/*if(hourFinishTrip >= 24)
	{
	hourFinishTrip -= 24;
	}*/
	//round distance and compute tripPrice and round it
	float tripPrice = distance * price;
	tripPrice = nearbyint(tripPrice);
	tripPrice /= 1000;
	tripPrice = nearbyint(tripPrice);
	tripPrice *= 1000;
	fprintf(tripsFile, "%d\t%d\t%d\t%d\t%d:%d\t%d:%d\t%d/%d/%d\t%s\t%d\n", username, origin, destination, (int)distance, hourStartTrip, minuteStartTrip, tempHourTime, (int)tempMinuteTime, year, month, day, vehicle, (int)tripPrice);
	cout << "Trip declared successfully.\n";
	//close open files
	fclose(vehiclesFile);
	fclose(citiesFile);
	fclose(tripsFile);
	fclose(driversFile);
}

void seePassengersInfo()
{

	FILE *ticketFile = fopen("ticket.txt", "r+");
	if (ticketFile == NULL)
	{
		cout << "The File opening was Unsuccessful!\n";
		return;
	}
	char firstName[30], lastName[30], trackingCode[10];
	int driversUsername, origin, destination;
	int timemin, timehour, year_ttrip, month_ttrip, day_ttrip;
	cout << "firstName" << " " << "lastName" << "  " << "origin" << " " << "destination" << "  " << "trakingCode" << "\n";
	int c;
	c = getc(ticketFile);
	fseek(ticketFile, -1, SEEK_CUR);
	for (int i = 0; i<100000 && c != EOF; i++)
	{
		fscanf(ticketFile, "%s\t%s\t%d\t%d\t%d\t%d:%d\t%d/%d/%d\t%s\n", firstName, lastName, &driversUsername, &origin, &destination,&timemin, &timehour, &year_ttrip, &month_ttrip, &day_ttrip, trackingCode);
		c = getc(ticketFile);
		fseek(ticketFile, -1, SEEK_CUR);
		cout << firstName << " " << lastName << "  ";
		cout << origin << " " << destination << "  ";
		printf("%d:%d", timehour, timemin);
		printf("%s\n", trackingCode);
	}
	fclose(ticketFile);
}
//=========================================================================================================
void cancelDelayTrip()
{
	int username1,origin1, destination1;
	int n;
	cout << "press 1 to cancel\n";
	cout << "press 2 to delay\n";
	cin >> n;
	if (n == 1) {
		//open trips file and print the lines for this drivers username
		FILE * tripsFile = fopen("Trips.txt", "r");
		//check opening file
		if (tripsFile == NULL)
		{
			cout << "The File opening was Unsuccessful!\n";
			return;
		}
		int username_temp, origin, destination, distance, startTripHour, startTripMinute, year_trip, month_trip, day_trip;
		char vehicle[15];
		int price;
		cout << "The trips will be displayed in the format below.(if there was a trip)\n";
		cout << "username\torigin\tdestination\tdistance\tstart Trip time\t vehicle\tprice\n";
		cout << "enter your user name\n";
		cin >> username1;
		cout << "origin:\n";
		cin >> origin1;
		cout << "destitation:\n";
		cin >> destination1;
		int BreakNumber = 0;
		int c;
        c = getc(tripsFile);
        fseek(tripsFile, -1, SEEK_CUR);
        for (int i = 0; i < 100000 && c != EOF; i++)
		{
			fscanf(tripsFile, "%d\t%d\t%d\t%d\t%d:%d\t%d/%d/%d\t%s\t%d", &username_temp, &origin, &destination, &distance, &startTripHour, &startTripMinute, &year_trip, &month_trip, &day_trip, vehicle, &price);
			c = getc(tripsFile);
            fseek(tripsFile, -1, SEEK_CUR);
            fscanf(tripsFile, "\n");
            if (username_temp == username1)
			{
				if(origin1==origin)
				{
					if(destination1== destination)
					{
                        /*FILE *fileptr1, *fileptr2;
                        char filename[40];
                        char ch;
                        int delete_line = lineNumber, temp = 1;
                        strcpy(filename, "Trips.txt");
                        fileptr1 = fopen(filename, "r");
                        //rewind
                        rewind(fileptr1);
                        //open new file in write mode
                        fileptr2 = fopen("replica.c", "w");
                        ch = 'A';
                        while (ch != EOF)
                        {
                            ch = getc(fileptr1);
                            //except the line to be deleted
                            if (temp != delete_line)
                            {
                                //copy all lines in file replica.c
                                putc(ch, fileptr2);
                            }
                            if (ch == '\n')
                            {
                                temp++;
                            }
                        }
                        fclose(fileptr1);
                        fclose(fileptr2);
                        remove(filename);
                        //rename the file replica.c to original name
                        rename("replica.c", filename);*/
			        }
		        }
	        }
		}
		if (BreakNumber == 0)
		{
			cout << "Sorry you have no declared trip!\n";
			return;
		}
		//close open files
		fclose(tripsFile);
	}
}

//=========================================================================================================
void historyOfTrips(int username)
{
	//open trips file and print the lines for this drivers username
	FILE * tripsFile = fopen("Trips.txt", "r");
	//check opening file
	if (tripsFile == NULL)
	{
		cout << "The File opening was Unsuccessful!\n";
		return;
	}
	int username_temp, origin, destination, distance, startTripHour, startTripMinute, year_trip, month_trip, day_trip;
	char vehicle[15];
	int price;
	cout << "The trips will be displayed in the format below.(if there was a trip)\n";
	cout << "username\torigin\tdestination\tdistance\tstart Trip time\t vehicle\tprice\n";
	int BreakNumber = 0;
	int c;
	for (int i = 0; i<100000 && c != EOF; i++)
	{
		fscanf(tripsFile, "%d\t%d\t%d\t%d\t%d:%d\t%d/%d/%d\t%s\t%d", &username_temp, &origin, &destination, &distance, &startTripHour, &startTripMinute, &year_trip, &month_trip, &day_trip, vehicle, &price);
		c = getc(tripsFile);
		if (username_temp == username)
		{
			while (username_temp == username && c != EOF)
			{
				printf("%d\t%d\t%d\t%d\t%d:%d\t%s\t%d\n", username, origin, destination, distance, startTripHour, startTripMinute, vehicle, price);
				fscanf(tripsFile, "%d\t%d\t%d\t%d\t%d:%d\t%d/%d/%d\t%s\t%d", &username_temp, &origin, &destination, &distance, &startTripHour, &startTripMinute, &year_trip, &month_trip, &day_trip, vehicle, &price);
				c = getc(tripsFile);
				BreakNumber++;
			}
			break;
		}
	}
	if (BreakNumber == 0)
	{
		cout << "Sorry you have no declared trip!\n";
		return;
	}
	//close open files
	fclose(tripsFile);
}
