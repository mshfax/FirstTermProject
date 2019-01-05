// Created by mostafa on 12/23/18.
// The functions for Admin tasks.
//needs to be completed

#ifndef PROJECT_ADMIN_H
#define PROJECT_ADMIN_H

#endif //PROJECT_ADMIN_H

#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

//declaration functions
void allUsers();
void allTransactions();
void allTrips();
void editDrivers();//complete
void editTrips();
void editVehicles();//complete
void signUpANewDriver();//complete
void editDriversInfo();//complete
int editDriversInfoInAllUsersFile(int, int, int, int, char[]);//complete
void price();

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
        cout << "0. Exit.\n\n";
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
            cout << "The number you inserted is not correct! try again.\n";
            return;
        }
    }
}

//definition functions
void allUsers()
{
    //completed
    FILE * allUsersFile = fopen("allUsers.txt","r"); // open allUsers file to see all of them
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
    cout << endl;
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
    //completed
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
        editDriversInfo();
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
    FILE * vehiclesFile = fopen("Vehicles.txt", "r+");
    if(vehiclesFile == NULL)
    {
        cout << "The File opening was Unsuccessful!\n";
        return;
    }
    //ask for the vehicle
    char vehicleName[21];
    cout << "Enter the name of vehicle you want to change. (bus/train/airplane)\n";
    scanf("%s", vehicleName);
    char vehicleName_temp[21];
    int capacity, speed, price;
    for (int i = 0; i<4; i++)
    {
        fscanf(vehiclesFile, "\n%s\t%d\t%d\t%d", vehicleName_temp, &capacity, &speed, &price);
        if(strcmp(vehicleName, vehicleName_temp) == 0)
        {
            cout << "what do you want to edit?\n";
            cout << "1. Capacity\n";
            cout << "2. Speed\n";
            cout << "3. Pricing policy number\n";
            cout << "0. Exit\n";
            int menuNumber;
            cin >> menuNumber;
            int j;
            char temp;      //for declare the end of a  line
            if(menuNumber == 1)
            {
                int NewCapacity;
                cout << "Enter new capacity\n";
                cin >> NewCapacity;
                fseek(vehiclesFile, -1, SEEK_CUR);
                for(j = 0;;j++)
                {
                    fseek(vehiclesFile, -1, SEEK_CUR);
                    fscanf(vehiclesFile,"%c", &temp);
                    if(temp == 10)
                    {
                        break;
                    }
                    else
                    {
                        fseek(vehiclesFile, -1, SEEK_CUR);
                    }
                }
                for(int k = 0; k <= j; k++)
                {
                    fprintf(vehiclesFile, "\b");
                }
                fseek(vehiclesFile, -1, SEEK_CUR);
                while(1)
                {
                    fseek(vehiclesFile, -1, SEEK_CUR);
                    fscanf(vehiclesFile,"%c", &temp);
                    if(temp == 10)
                    {
                        break;
                    }
                    else
                    {
                        fseek(vehiclesFile, -1, SEEK_CUR);
                    }
                }
                int Exit;
                Exit = fprintf(vehiclesFile, "%s\t%d\t%d\t%d\n", vehicleName, NewCapacity, speed, price);
                if(Exit >= 0)
                {
                    cout << "Capacity edited successfully\n";
                    break;
                }
                else
                {
                    cout << "Sorry something went wrong!!!\n";
                    break;
                }
            }
            else if(menuNumber == 2)
            {
                int NewSpeed;
                cout << "Enter new speed\n";
                cin >> NewSpeed;
                fseek(vehiclesFile, -1, SEEK_CUR);
                for(j = 0;;j++)
                {
                    fseek(vehiclesFile, -1, SEEK_CUR);
                    fscanf(vehiclesFile,"%c", &temp);
                    if(temp == 10)
                    {
                        break;
                    }
                    else
                    {
                        fseek(vehiclesFile, -1, SEEK_CUR);
                    }
                }
                for(int k = 0; k <= j; k++)
                {
                    fprintf(vehiclesFile, "\b");
                }
                fseek(vehiclesFile, -1, SEEK_CUR);
                while(1)
                {
                    fseek(vehiclesFile, -1, SEEK_CUR);
                    fscanf(vehiclesFile,"%c", &temp);
                    if(temp == 10)
                    {
                        break;
                    }
                    else
                    {
                        fseek(vehiclesFile, -1, SEEK_CUR);
                    }
                }
                int Exit;
                Exit = fprintf(vehiclesFile, "%s\t%d\t%d\t%d\n", vehicleName, capacity, NewSpeed, price);
                if(Exit >= 0)
                {
                    cout << "Speed edited successfully\n";
                    break;
                }
                else
                {
                    cout << "Sorry something went wrong!!!\n";
                    break;
                }
            }
            else if(menuNumber == 3)
            {
                int NewPrice;
                cout << "Enter new pricing policy number\n";
                cin >> NewPrice;
                fseek(vehiclesFile, -1, SEEK_CUR);
                for(j = 0;;j++)
                {
                    fseek(vehiclesFile, -1, SEEK_CUR);
                    fscanf(vehiclesFile,"%c", &temp);
                    if(temp == 10)
                    {
                        break;
                    }
                    else
                    {
                        fseek(vehiclesFile, -1, SEEK_CUR);
                    }
                }
                for(int k = 0; k <= j; k++)
                {
                    fprintf(vehiclesFile, "\b");
                }
                fseek(vehiclesFile, -1, SEEK_CUR);
                while(1)
                {
                    fseek(vehiclesFile, -1, SEEK_CUR);
                    fscanf(vehiclesFile,"%c", &temp);
                    if(temp == 10)
                    {
                        break;
                    }
                    else
                    {
                        fseek(vehiclesFile, -1, SEEK_CUR);
                    }
                }
                int Exit;
                Exit = fprintf(vehiclesFile, "%s\t%d\t%d\t%d\n", vehicleName, capacity, speed, NewPrice);
                if(Exit >= 0)
                {
                    cout << "Capacity edited successfully\n";
                    break;
                }
                else
                {
                    cout << "Sorry something went wrong!!!\n";
                    break;
                }
            }
            else if(menuNumber == 0)
            {
                break;
            }
            else
            {
                cout << "Sorry the number you entered is not correct! try again please..\n";
                break;
            }
        }
    }
    //close open files
    fclose(vehiclesFile);
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
    cout << "Enter driver's account number: (you can not change it later)\n";
    cin >> account;
    cout << "Enter the password: (you can not change it later)\n";
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



void editDriversInfo()
{
    //getting driver's account info
    int username, password;
    cout << "Enter the username of the driver you want to change his/her Info\n";
    cin >> username;
    cout << "Enter the password of the driver you want to change his/her Info\n";
    cin >> password;
    //open files
    FILE * driversFile = fopen("Drivers.txt", "r+");
    //FILE * allUsersFile = fopen("allUsers.txt", "r+");
    if(driversFile == NULL)
    {
        cout << "The File opening was Unsuccessful!\n";
        return;
    }
    //search and edit info
    int i,menuNumber;
    int username_driversFile_temp, pass_driversFile_temp, accountNumber_driversFile_temp;
    char firstName_driversFile_temp[21], lastName_driversFile_temp[21], phone_driversFile_temp[21], vehicle_driversFile_temp[21];

    fscanf(driversFile, "\n%d\t%d\t%d\t%s\t%s\t%s\t%s", &username_driversFile_temp, &pass_driversFile_temp, &accountNumber_driversFile_temp, firstName_driversFile_temp, lastName_driversFile_temp, phone_driversFile_temp, vehicle_driversFile_temp);

    for (i = 0;i < 99999; i++)
    {
        //scan info from the file
        if (username == username_driversFile_temp)
        {
            if(password == pass_driversFile_temp)
            {
                //found the drivers line
                //recognize want info has to be edit
                cout << "Enter the number of field you want to edit (You can not change account number and password!).\n";
                cout << "1. Username\n";
                cout << "2. First name\n";
                cout << "3. last name\n";
                cout << "4. phone\n";
                cout << "5. vehicle\n";
                cout << "0. Return to menu\n";
                cin >> menuNumber;

                if(menuNumber == 1)
                {
                    int NewUsername;
                    cout << "Enter new username\n";
                    cin >> NewUsername;
                    //erase the line
                    int j;
                    char temp;      //for declare the end of a  line
                    fseek(driversFile, -1, SEEK_CUR);
                    for(j = 0;;j++)
                    {
                        fseek(driversFile, -1, SEEK_CUR);
                        fscanf(driversFile,"%c", &temp);
                        if(temp == 10)
                        {
                            break;
                        }
                        else
                        {
                            fseek(driversFile, -1, SEEK_CUR);
                        }
                    }
                    for(int k = 0; k <= j; k++)
                    {
                        fprintf(driversFile, "\b");
                    }
                    fseek(driversFile, -1, SEEK_CUR);
                    while(1)
                    {
                        fseek(driversFile, -1, SEEK_CUR);
                        fscanf(driversFile,"%c", &temp);
                        if(temp == 10)
                        {
                            break;
                        }
                        else
                        {
                            fseek(driversFile, -1, SEEK_CUR);
                        }
                    }
                    int ExitNumber;
                    char sringForPassToFunction[] = "nothing";
                    ExitNumber = editDriversInfoInAllUsersFile(username, password, menuNumber, NewUsername, sringForPassToFunction);
                    fprintf(driversFile, "%d\t%d\t%d\t%s\t%s\t%s\t%s", NewUsername, pass_driversFile_temp, accountNumber_driversFile_temp, firstName_driversFile_temp, lastName_driversFile_temp, phone_driversFile_temp, vehicle_driversFile_temp);
                    if(ExitNumber >= 0)
                    {
                        cout << "Username edited successfully." << endl;
                    }
                    else
                    {
                        cout << "sorry something went wrong!!\n";
                    }
                }
                else if(menuNumber == 2)
                {
                    char NewFirstName[21];
                    cout << "Enter new firstName\n";
                    scanf("%s", NewFirstName);
                    //erase the line
                    int j;
                    char temp;      //for declare the end of a  line
                    fseek(driversFile, -1, SEEK_CUR);
                    for(j = 0;;j++)
                    {
                        fseek(driversFile, -1, SEEK_CUR);
                        fscanf(driversFile,"%c", &temp);
                        if(temp == 10)
                        {
                            break;
                        }
                        else
                        {
                            fseek(driversFile, -1, SEEK_CUR);
                        }
                    }
                    for(int k = 0; k <= j; k++)
                    {
                        fprintf(driversFile, "\b");
                    }
                    fseek(driversFile, -1, SEEK_CUR);
                    while(1)
                    {
                        fseek(driversFile, -1, SEEK_CUR);
                        fscanf(driversFile,"%c", &temp);
                        if(temp == 10)
                        {
                            break;
                        }
                        else
                        {
                            fseek(driversFile, -1, SEEK_CUR);
                        }
                    }
                    int ExitNumber;
                    ExitNumber = editDriversInfoInAllUsersFile(username, password, menuNumber, 0, NewFirstName);
                    fprintf(driversFile, "%d\t%d\t%d\t%s\t%s\t%s\t%s", username_driversFile_temp, pass_driversFile_temp, accountNumber_driversFile_temp, NewFirstName, lastName_driversFile_temp, phone_driversFile_temp, vehicle_driversFile_temp);
                    if(ExitNumber >= 0)
                    {
                        cout << "First name edited successfully." << endl;
                    }
                    else
                    {
                        cout << "sorry something went wrong!!\n";
                    }
                }
                else if(menuNumber == 3)
                {
                    char NewLastName[21];
                    cout << "Enter new lastName\n";
                    scanf("%s", NewLastName);
                    //erase the line
                    int j;
                    char temp;      //for declare the end of a  line
                    fseek(driversFile, -1, SEEK_CUR);
                    for(j = 0;;j++)
                    {
                        fseek(driversFile, -1, SEEK_CUR);
                        fscanf(driversFile,"%c", &temp);
                        if(temp == 10)
                        {
                            break;
                        }
                        else
                        {
                            fseek(driversFile, -1, SEEK_CUR);
                        }
                    }
                    for(int k = 0; k <= j; k++)
                    {
                        fprintf(driversFile, "\b");
                    }
                    fseek(driversFile, -1, SEEK_CUR);
                    while(1)
                    {
                        fseek(driversFile, -1, SEEK_CUR);
                        fscanf(driversFile,"%c", &temp);
                        if(temp == 10)
                        {
                            break;
                        }
                        else
                        {
                            fseek(driversFile, -1, SEEK_CUR);
                        }
                    }
                    fprintf(driversFile, "%d\t%d\t%d\t%s\t%s\t%s\t%s", username_driversFile_temp, pass_driversFile_temp, accountNumber_driversFile_temp, firstName_driversFile_temp, NewLastName, phone_driversFile_temp, vehicle_driversFile_temp);
                    int ExitNumber;
                    ExitNumber = editDriversInfoInAllUsersFile(username, password, menuNumber, 0, NewLastName);
                    if(ExitNumber >= 0)
                    {
                        cout << "Last name edited successfully." << endl;
                    }
                    else
                    {
                        cout << "sorry something went wrong!!\n";
                    }
                }
                else if(menuNumber == 4)
                {
                    char NewPhone[20];
                    cout << "Enter new phone number\n";
                    scanf("%s", NewPhone);
                    //erase the line
                    int j;
                    char temp;      //for declare the end of a  line
                    fseek(driversFile, -1, SEEK_CUR);
                    for(j = 0;;j++)
                    {
                        fseek(driversFile, -1, SEEK_CUR);
                        fscanf(driversFile,"%c", &temp);
                        if(temp == 10)
                        {
                            break;
                        }
                        else
                        {
                            fseek(driversFile, -1, SEEK_CUR);
                        }
                    }
                    for(int k = 0; k <= j; k++)
                    {
                        fprintf(driversFile, "\b");
                    }
                    fseek(driversFile, -1, SEEK_CUR);
                    while(1)
                    {
                        fseek(driversFile, -1, SEEK_CUR);
                        fscanf(driversFile,"%c", &temp);
                        if(temp == 10)
                        {
                            break;
                        }
                        else
                        {
                            fseek(driversFile, -1, SEEK_CUR);
                        }
                    }
                    fprintf(driversFile, "%d\t%d\t%d\t%s\t%s\t%s\t%s", username_driversFile_temp, pass_driversFile_temp, accountNumber_driversFile_temp, firstName_driversFile_temp, lastName_driversFile_temp, NewPhone, vehicle_driversFile_temp);
                    int ExitNumber;
                    ExitNumber = editDriversInfoInAllUsersFile(username, password, menuNumber, 0, NewPhone);
                    if(ExitNumber >= 0)
                    {
                        cout << "Phone number edited successfully." << endl;
                    }
                    else
                    {
                        cout << "sorry something went wrong!!\n";
                    }
                }
                else if(menuNumber == 5)
                {
                    char NewVehicle[21];
                    cout << "Enter new vehicle\n";
                    scanf("%s", NewVehicle);
                    //erase the line
                    int j;
                    char temp;      //for declare the end of a  line
                    fseek(driversFile, -1, SEEK_CUR);
                    for(j = 0;;j++)
                    {
                        fseek(driversFile, -1, SEEK_CUR);
                        fscanf(driversFile,"%c", &temp);
                        if(temp == 10)
                        {
                            break;
                        }
                        else
                        {
                            fseek(driversFile, -1, SEEK_CUR);
                        }
                    }
                    for(int k = 0; k <= j; k++)
                    {
                        fprintf(driversFile, "\b");
                    }
                    fseek(driversFile, -1, SEEK_CUR);
                    while(1)
                    {
                        fseek(driversFile, -1, SEEK_CUR);
                        fscanf(driversFile,"%c", &temp);
                        if(temp == 10)
                        {
                            break;
                        }
                        else
                        {
                            fseek(driversFile, -1, SEEK_CUR);
                        }
                    }
                    fprintf(driversFile, "%d\t%d\t%d\t%s\t%s\t%s\t%s", username_driversFile_temp, pass_driversFile_temp, accountNumber_driversFile_temp, firstName_driversFile_temp, lastName_driversFile_temp, phone_driversFile_temp, NewVehicle);
                    int ExitNumber;
                    ExitNumber = editDriversInfoInAllUsersFile(username, password, menuNumber, 0, NewVehicle);
                    if(ExitNumber >= 0)
                    {
                        cout << "Vehicle edited successfully." << endl;
                    }
                    else
                    {
                        cout << "sorry something went wrong!!\n";
                    }
                }
                else if(menuNumber == 0)
                {
                    break;
                }
                else
                {
                    cout << "Sorry the number you have entered is not correct! Try again please...\n";
                    break;
                }
            }
            else
            {
                cout << "Sorry the password is incorrect...\n";
                break;
            }
        }
        else
        {
            //read next line
            fscanf(driversFile, "\n%d\t%d\t%d\t%s\t%s\t%s\t%s", &username_driversFile_temp, &pass_driversFile_temp, &accountNumber_driversFile_temp, firstName_driversFile_temp, lastName_driversFile_temp, phone_driversFile_temp, vehicle_driversFile_temp);
        }
    }
    if(i >= 100000)
    {
        cout << "Sorry the username you have entered is not correct!!!\n";
    }
    //close open file
    fclose(driversFile);
}

void price()
{
    //code
}

//define a function for edit drivers info in all users file
int editDriversInfoInAllUsersFile(int username, int password, int menuNumber, int NewIntegers, char NewStrings[21])
{
    //open file
    FILE * allUsersFile = fopen("allUsers.txt", "r+");
    if(allUsersFile == NULL)
    {
        cout << "The File opening was Unsuccessful!\n";
        return -1;

    }
    int username_allUsersFile_temp, pass_allUsersFile_temp, accountNumber_allUsersFile_temp;
    char firstName_allUsersFile_temp[21], lastName_allUsersFile_temp[21], phone_allUsersFile_temp[21], vehicle_allUsersFile_temp[21];
    //read first line
    fscanf(allUsersFile, "%d\t%d\t%d\t%s\t%s\t%s\t%s", &username_allUsersFile_temp, &pass_allUsersFile_temp, &accountNumber_allUsersFile_temp, firstName_allUsersFile_temp, lastName_allUsersFile_temp, phone_allUsersFile_temp, vehicle_allUsersFile_temp);
    //search in the file and edit the info
    int i;
    for (i = 0; i<100000; i++)
    {
        if(username_allUsersFile_temp == username)
        {
            if(password == pass_allUsersFile_temp)
            {
                // the line of the driver found
                //erase the line
                int j;
                char temp;
                fseek(allUsersFile, -1, SEEK_CUR);
                for (j = 0;; j++)
                {
                    fseek(allUsersFile, -1, SEEK_CUR);
                    fscanf(allUsersFile,"%c", &temp);
                    if(temp == 10)
                    {
                        break;
                    }
                    else
                    {
                        fseek(allUsersFile, -1, SEEK_CUR);
                    }
                }
                for(int k = 0; k <= j; k++)
                {
                    fprintf(allUsersFile, "\b");
                }
                fseek(allUsersFile, -1, SEEK_CUR);
                while(1)
                {
                    fseek(allUsersFile, -1, SEEK_CUR);
                    fscanf(allUsersFile,"%c", &temp);
                    if(temp == 10)
                    {
                        break;
                    }
                    else
                    {
                        fseek(allUsersFile, -1, SEEK_CUR);
                    }
                }
                //rewrite the line
                if(menuNumber == 1)//username
                {
                    fprintf(allUsersFile, "%d\t%d\t%d\t%s\t%s\t%s\t%s", NewIntegers, pass_allUsersFile_temp, accountNumber_allUsersFile_temp, firstName_allUsersFile_temp, lastName_allUsersFile_temp, phone_allUsersFile_temp, vehicle_allUsersFile_temp);
                    break;
                }
                else if(menuNumber == 2)//firstName
                {
                    fprintf(allUsersFile, "%d\t%d\t%d\t%s\t%s\t%s\t%s", username_allUsersFile_temp, pass_allUsersFile_temp, accountNumber_allUsersFile_temp, NewStrings, lastName_allUsersFile_temp, phone_allUsersFile_temp, vehicle_allUsersFile_temp);
                    break;
                }
                else if(menuNumber == 3)//lastName
                {
                    fprintf(allUsersFile, "%d\t%d\t%d\t%s\t%s\t%s\t%s", username_allUsersFile_temp, pass_allUsersFile_temp, accountNumber_allUsersFile_temp, firstName_allUsersFile_temp, NewStrings, phone_allUsersFile_temp, vehicle_allUsersFile_temp);
                    break;
                }
                else if(menuNumber == 4)//phone
                {
                    fprintf(allUsersFile, "%d\t%d\t%d\t%s\t%s\t%s\t%s", username_allUsersFile_temp, pass_allUsersFile_temp, accountNumber_allUsersFile_temp, firstName_allUsersFile_temp, lastName_allUsersFile_temp, NewStrings, vehicle_allUsersFile_temp);
                    break;
                }
                else if(menuNumber == 5)//vehicle
                {
                    fprintf(allUsersFile, "%d\t%d\t%d\t%s\t%s\t%s\t%s", username_allUsersFile_temp, pass_allUsersFile_temp, accountNumber_allUsersFile_temp, firstName_allUsersFile_temp, lastName_allUsersFile_temp, phone_allUsersFile_temp, NewStrings);
                    break;
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                cout << "Sorry the password is incorrect...\n";
                return -1;
            }
        }
        else
        {
            //read the next line
            fscanf(allUsersFile, "\n%d\t%d\t%d\t%s\t%s\t%s\t%s", &username_allUsersFile_temp, &pass_allUsersFile_temp, &accountNumber_allUsersFile_temp, firstName_allUsersFile_temp, lastName_allUsersFile_temp, phone_allUsersFile_temp, vehicle_allUsersFile_temp);
        }
    }
    //close open files
    fclose(allUsersFile);
    return 1;
}
