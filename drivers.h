//
// Created by mostafa on 12/29/18.
//needs to be completed

#ifndef PROJECT_DRIVERS_H
#define PROJECT_DRIVERS_H

#endif //PROJECT_DRIVERS_H

#include <stdio.h>
#include <iostream>

//functions declaration
void declareTrip();
void seePassengersInfo();
void cancelDelayTrip();
void historyOfTrips();

void driversMain()  //function to clear what admin wants to do
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
            declareTrip();
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
void declareTrip()
{
    //code
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
