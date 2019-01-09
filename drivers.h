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
void historyOfTrips();

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
            historyOfTrips();
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
void declareTrip(int username)
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
    int distance = sqrt( ((originX - destinationX)*(originX - destinationX)) + ((originY - destinationY)*(originY - destinationY)) );
    //find the vehicle of the driver
    //complete trip time and get vehicle and the trip of the driver and print in the file

    //close open files
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

void historyOfTrips()
{
    //code
}
