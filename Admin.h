// Created by mostafa on 12/23/18.
// The functions for Admin tasks.

#include <stdio.h>
#include <iostream>

#ifndef PROJECT_ADMIN_H
#define PROJECT_ADMIN_H

#endif //PROJECT_ADMIN_H

using namespace std;

//declaration functions
void allUsers();
void allTransactions();
void allTrips();
void editDrivers();
void editTrips();
void editVehicles();

void adminMain() //function to clear what admin wants to do
{
    int n;
    while(1)
    {
        //start function menu
        cout << "Enter the number of task you want to do please...\n";
        cout << "1. See all users info.\n";
        cout << "2. See all transaction.\n";
        cout << "3. See all trips.\n";
        cout << "4. Edit drivers info.\n";
        cout << "5. Edit trips info.\n";
        cout << "6. Edit vehicles info.\n";
        cout << "0. Exit.\n";
        //end function menu
        cin >> n;
        if(n == 1)
        {
            //goes to users function
            allUsers();
        }
        else if(n == 2)
        {
            //goes to transactions function
            allTransactions();
        }
        else if(n == 3)
        {
            //goes to trips function
            allTrips();
        }
        else if(n == 4)
        {
            //goes to function to Edit drivers info
            editDrivers();
        }
        else if(n == 5)
        {
            //goes to function to Edit trips info
            editTrips();
        }
        else if(n == 6)
        {
            //goes to function to Edit vehicles info
            editVehicles();
        }
        else if(n == 0)
        {
            return;
        }
        else
        {
            cout << "The number you inserted is not correct! try again please...\n";
            return;
        }
    }
}

//definition functions
void allUsers()
{
    //needs to be completed
}

void allTransactions()
{
    //needs to be completed

}

void allTrips()
{
    //needs to be completed

}

void editDrivers()
{
    //needs to be completed

}

void editTrips()
{
    //needs to be completed

}

void editVehicles()
{
    //needs to be completed
}