// Created by mostafa on 12/23/18.
// The functions for Admin tasks.
//needs to be completed
//sharafi


#ifndef PROJECT_ADMIN_H
#define PROJECT_ADMIN_H

#endif //PROJECT_ADMIN_H

#include <stdio.h>
#include <iostream>

using namespace std;

//declaration functions
void allUsers();
void allTransactions();
void allTrips();
void editDrivers();
void editTrips();
void editVehicles();
void EditCapacityOfAVehicle();
void EditSpeedOfAVehicle();
void price();
void signUpANewDriver();

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
    FILE * allUsersFile = fopen("allUsers.txt","r"); // open allusers file to see all of them
    if(allUsersFile == NULL)
    {
        cout << "The File opening was Unsuccessful!\n";
        return;
    }
    cout << "The users will be displayed in the format below\n";
    cout << "username\tpassword\taccount number\tfirst name\tlast name\tphone\tvehicle(for drivers) or reagent\n";
    int fileCharacters = getc(allUsersFile);
    while (fileCharacters != EOF)
    {
        // display contents of file on screen
        putchar(fileCharacters);
        fileCharacters = getc(allUsersFile);
    }
    //close open file
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
    int a;
    cout << "Enter the number of task you want to do\n";
    cout << "1. sign up a new driver\n";
    cout << "2. Edit drivers Info\n";
    cin >> a;
    if(a == 1)
    {
        signUpANewDriver();
    }
    else if(a == 2)
    {
        //editDriversInfo();
    }
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
    int m;
    cout << "Enter the number of task you want to do please...\n";
    cout << "1. Edit capacity of a vehicle\n";
    cout << "2. Edit the average speed of a vehicle\n";
    cout << "3. Edit price algoritm\n";
    cout << "0. Exit\n";
    cin >> m;
    if(m == 1)
    {
        EditCapacityOfAVehicle();
        return;
    }
    else if(m == 2)
    {
        EditSpeedOfAVehicle();
        return;
    }
    else if(m == 3)
    {
        price();
        return;
    }

    fclose(vehiclesFile);
}

void EditCapacityOfAVehicle()
{
    //code
}

void EditSpeedOfAVehicle()
{
    //code
}

void price()
{
    //code
}

void signUpANewDriver()
{
    const int n = 499999;
    int driversUsername = n;
    int i;
    FILE * accountsFile = fopen("accounts.txt", "r");
    FILE * driversFile = fopen("Drivers.txt", "a");
    FILE * allUsersFile = fopen("allUsers.txt", "a");
    //make sure that files will open
    if(accountsFile == NULL)
    {
        cout << "The File opening was Unsuccessful!\n";
        return;
    }
    if(driversFile == NULL)
    {
        cout << "The File opening was Unsuccessful!\n";
        return;
    }
    if(allUsersFile == NULL)
    {
        cout << "The File opening was Unsuccessful!\n";
        return;
    }
    // start sign up
    int account, pass;
    int account_temp,pass_temp,cash;
    char firstName[30];
    char lastName[30];
    char phone[30];
    char vehicle[15];
    cout << "Enter driver's first name please...\n";
    scanf("%s", firstName);
    cout << "Enter driver's last name:\n";
    scanf("%s", lastName);
    cout << "Enter driver's phone number:\n";
    scanf("%s", phone);
    cout << "Enter driver's account number:\n";
    cin >> account;
    cout << "Enter the password:\n";
    cin >> pass;
    cout << "Confirm the password:\n";
    cin >> pass_temp;
    cout << "Enter driver's vehicle\n";
    scanf("%s", vehicle);
    if(pass == pass_temp)
    {
        for(i = 0;i<100000;i++)
        {
            driversUsername++;
            fscanf(accountsFile,"%d\t%d\t%d\n", &account_temp, &pass_temp, &cash);
            if(account_temp == account)
            {
                if(pass_temp == pass)
                {
                    fprintf(allUsersFile, "%d\t%d\t%d\t%s\t%s\t%s\t%s\n", driversUsername, pass, account, firstName, lastName, phone, vehicle);
                    fprintf(driversFile, "%d\t%d\t%d\t%s\t%s\t%s\t%s\n", driversUsername, pass, account, firstName, lastName, phone, vehicle);
                    cout << "Sign up successfully\n";
                    break;
                }
                else
                {
                    cout << "Sorry the password is incorrect...\n";
                }
            }
        }
        if(i == 100000)
        {
            cout << "The account number you have entered is incorrect! Try again please...\n";
        }
    }
    else
    {
        cout << "two passwords are not the same !!!\n";
        return;
    }
    //finish sign up
    //close open files
    fclose(accountsFile);
    fclose(driversFile);
    fclose(allUsersFile);
}