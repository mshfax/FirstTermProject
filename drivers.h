//
// Created by mostafa on 12/29/18.
//needs to be completed

#ifndef PROJECT_DRIVERS_H
#define PROJECT_DRIVERS_H

#endif //PROJECT_DRIVERS_H

#include <stdio.h>
#include <iostream>
#include <math.h>

//functions declaration
void declareTrip(int);
void seePassengersInfo();
void cancelDelayTrip();
void historyOfTrips(int);

void driversMain(int username)  //function to clear what admin wants to do
{
    int n;
    while(1)
    {
        cout << "Enter the number of task you want to do please...\n";
        cout << "1. declare a trip\n";
        cout << "2. see all passengers Info\n";
        cout << "3. cancel or delay of a trip\n";
        cout << "4. see history of all trips\n";
        cout << "0. Exit\n";
        cin >> n;
        if(n == 1)
        {
            declareTrip(username);
        }
        else if(n == 2)
        {
            seePassengersInfo();
        }
        else if(n == 3)
        {
            cancelDelayTrip();
        }
        else if(n == 4)
        {
            historyOfTrips(username);
        }
        else if(n == 0)
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
    if(citiesFile == NULL || tripsFile == NULL || driversFile == NULL)
    {
        cout << "The File opening was Unsuccessful!\n";
        return;
    }
    //main code here
    int origin, destination, hourStartTrip, minuteStartTrip;
    cout << "Enter origin city\n";
    cin >> origin;
    cout << "Enter destination city\n";
    cin >> destination;
    cout << "Enter start hour of the trip\n";
    cin >> hourStartTrip;
    cout << "Enter start minute of the trip\n";
    cin >> minuteStartTrip;
    //find the cities and save the origin and destination x and y
    //origin
    int originX=0, originY=0, tempOrigin, a=0, b=0;
    fscanf(citiesFile, "%d\t%d\t%d", &tempOrigin, &a, &b);
    int i = getc(citiesFile);
    fseek(citiesFile,-1,SEEK_CUR);
    int j = 1;
    while (i!=EOF)
    {
        if(tempOrigin == origin)
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
    if(j)
    {
        cout << "Sorry the number you have entered is not correct!! Try again\n";
        return;
    }
    fseek(citiesFile, 0, SEEK_SET);
    //destination
    int destinationX=0, destinationY=0, tempDestination;
    fscanf(citiesFile, "%d\t%d\t%d", &tempDestination, &a, &b);
    i = getc(citiesFile);
    fseek(citiesFile,-1,SEEK_CUR);

    j = 1;
    while (i!=EOF)
    {
        if(tempDestination == destination)
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
    if(j)
    {
        cout << "Sorry the number you have entered is not correct!! Try again\n";
        return;
    }
    //computing the distance
    float distance = sqrt( ((originX - destinationX)*(originX - destinationX)) + ((originY - destinationY)*(originY - destinationY)) );
    //complete trip time and get vehicle and the trip of the driver and print in the file
    char vehicle[15];
    int userName_temp, pass_temp ,accountNumber;
    char firstName[30], lastName[30], phone[15], vehicle_temp[15];
    fscanf(driversFile, "\n%d\t%d\t%d\t%s\t%s\t%s\t%s", &userName_temp, &pass_temp, &accountNumber, firstName, lastName, phone, vehicle_temp);
    //i = getc(driversFile);
    //j = 1;
    for ( j = 0 ;j < 10000; j++)
    {
        if(userName_temp == username)
        {
            strcpy(vehicle,vehicle_temp);//got vehicle
            //j=0;
            break;
        }
        else
        {
            fscanf(driversFile, "\n%d\t%d\t%d\t%s\t%s\t%s\t%s", &userName_temp, &pass_temp, &accountNumber, firstName, lastName, phone, vehicle_temp);
            //i = getc(driversFile);
        }
    }
    if(j==100000)
    {
        cout << "Sorry the number you have entered is not correct!! Try again\n";
        return;
    }
    char vehicle_name[15];
    int capacity_temp, speed_temp, price_temp;
    int speed=0, price=0;
    //open vehicles file for speed
    FILE * vehiclesFile = fopen("Vehicles.txt", "r");
    if(vehiclesFile == NULL)
    {
        cout << "The File opening was Unsuccessful!\n";
        return;
    }
    for (int i = 0; i<6; i++)
    {
        fscanf(vehiclesFile, "\n%s\t%d\t%d\t%d\n", vehicle_name, &capacity_temp, &speed_temp, &price_temp);
        if(strcmp(vehicle, vehicle_name)==0)
        {
            speed = speed_temp;
            price = price_temp;
            break;
        }
    }
    /*int hourFinishTrip = hourStartTrip + temptimehour;
    int minuteFinishTrip = minuteStartTrip + temptimeminute;
    //check that minute and hour finish trip be fewer than 60
    if (minuteFinishTrip >= 60)
    {
        hourFinishTrip++;
        minuteFinishTrip-=60;
    }
    if(hourFinishTrip >= 24)
    {
        hourFinishTrip -= 24;
    }*/
    //round distance and compute tripPrice and round it
    float tripPrice = distance * price;
    tripPrice = nearbyint(tripPrice);
    tripPrice /= 1000;
    tripPrice = nearbyint(tripPrice);
    tripPrice *= 1000;
    fprintf(tripsFile, "%d\t%d\t%d\t%d\t%d:%d\t%s\t%d\n", username, origin, destination,(int) distance, hourStartTrip, minuteStartTrip, vehicle, (int)tripPrice);
    cout << "Trip declared successfully.\n";
    //close open files
    fclose(vehiclesFile);
    fclose(citiesFile);
    fclose(tripsFile);
    fclose(driversFile);
}

void seePassengersInfo()
{
    //code
}

void cancelDelayTrip()
{
    //code
}

void historyOfTrips(int username)
{
    //open trips file and print the lines for this drivers username
    FILE * tripsFile = fopen("Trips.txt", "r");
    //check opening file
    if(tripsFile == NULL)
    {
        cout << "The File opening was Unsuccessful!\n";
        return;
    }
    int username_temp, origin, destination, distance, startTripHour, startTripMinute;
    char vehicle[15];
    int price;
    cout << "The trips will be displayed in the format below.(if there was a trip)\n";
    cout << "username\torigin\tdestination\tdistance\tstart Trip time\t vehicle\tprice\n";
    int BreakNumber = 0;
    int c;
    for (int i = 0; i<100000 && c!=EOF; i++)
    {
        fscanf(tripsFile, "%d\t%d\t%d\t%d\t%d:%d\t%s\t%d", &username_temp, &origin, &destination, &distance, &startTripHour, &startTripMinute, vehicle, &price);
        c = getc(tripsFile);
        if(username_temp == username)
        {
            while(username_temp == username && c!=EOF)
            {
                printf("%d\t%d\t%d\t%d\t%d:%d\t%s\t%d\n", username, origin, destination, distance, startTripHour, startTripMinute, vehicle, price);
                fscanf(tripsFile, "%d\t%d\t%d\t%d\t%d:%d\t%s\t%d", &username_temp, &origin, &destination, &distance, &startTripHour, &startTripMinute, vehicle, &price);
                c = getc(tripsFile);
                BreakNumber++;
            }
            break;
        }
    }
    if(BreakNumber == 0)
    {
        cout << "Sorry you have no declared trip!\n";
        return;
    }
    //close open files
    fclose(tripsFile);
}
