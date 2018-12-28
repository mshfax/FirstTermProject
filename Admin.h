// Created by mostafa on 12/23/18.
// The functions for Admin tasks.
//needs to be completed

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
    int username_temp,pass_temp,account_temp,m;
    char firstName[20],lastName[20],phone[15];
    FILE * allUsersFile = fopen("allUsers.txt","r"); // open allusers file to see all of them
    if(allUsersFile == NULL)
    {
        cout << "The File opening was Unsuccessful!\n";
        return;
    }
    cout << "The users will be displayed in the format below\n";
    cout << "username\tpassword\taccount number\tfirst name\tlast name\tphone\n";
    for(int i = 0;i < 100000; i++)
    {
        //this for must scan the info from allusers file and cout it
        fscanf(allUsersFile, "%d\t%d\t%d\t%s\t%s\t%s\n", &username_temp, &pass_temp, &account_temp, firstName, lastName, phone);
        cout << username_temp << "\t";
        cout << pass_temp << "\t";
        cout << account_temp << "\t";
        cout << firstName << "\t";
        cout << lastName << "\t";
        cout << phone << "\n";
        m = fgetc(allUsersFile);
        if(m == EOF)
        {
            cout << "These are all users.\n";
            break;
        }
    }
    fclose(allUsersFile);
}

void allTransactions()
{
    //needs to be completed
    FILE * allTransactionsFile = fopen("Transactions.txt", "r");
    if(allTransactionsFile == NULL)
    {
        cout << "The File opening was Unsuccessful!\n";
        return;
    }
    //main code here
    fclose(allTransactionsFile);
}

void allTrips()
{
    //needs to be completed
    FILE * allTripsFile = fopen("Trips.txt", "r");
    if(allTripsFile == NULL)
    {
        cout << "The File opening was Unsuccessful!\n";
        return;
    }
    //main code here
    fclose(allTripsFile);
}

void editDrivers()
{
    //needs to be completed
    FILE * driversFile = fopen("Drivers.txt", "a");
    if (driversFile == NULL)
    {
        cout << "The File opening was Unsuccessful!\n";
        return;
    }
    //main code here
    fclose(driversFile);
}

void editTrips()
{
    //needs to be completed
    FILE * tripsFile = fopen("Trips.txt", "a");
    if(tripsFile == NULL)
    {
        cout << "The File opening was Unsuccessful!\n";
        return;
    }
    //main code here
    fclose(tripsFile);
}

void editVehicles()
{
    //needs to be completed
    FILE * vehiclesFile = fopen("Vehicles.txt", "a");
    if(vehiclesFile == NULL)
    {
        cout << "The File opening was Unsuccessful!\n";
        return;
    }
    //main code here
    fclose(vehiclesFile);
}