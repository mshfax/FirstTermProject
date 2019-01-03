// Created by mostafa on 12/23/18.
// The functions for Admin tasks.
//needs to be completed

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
void signUpANewDriver();
void editDriversInfo();
void EditCapacityOfAVehicle();
void EditSpeedOfAVehicle();
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
    cout << "3. Edit pricing policy\n";
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
    //int username_allUsersFile_temp, pass_allUsersFile_temp, accountNumber_allUsersFile_temp;
    //char firstName_allUsersFile_temp[21], lastName_allUsersFile_temp[21], phone_allUsersFile_temp[21], vehicle_allUsersFile_temp[21];

    fscanf(driversFile, "\n%d\t%d\t%d\t%s\t%s\t%s\t%s", &username_driversFile_temp, &pass_driversFile_temp, &accountNumber_driversFile_temp, firstName_driversFile_temp, lastName_driversFile_temp, phone_driversFile_temp, vehicle_driversFile_temp);
    //fscanf(allUsersFile, "%d\t%d\t%d\t%s\t%s\t%s\t%s", &username_allUsersFile_temp, &pass_allUsersFile_temp, &accountNumber_allUsersFile_temp, firstName_allUsersFile_temp, lastName_allUsersFile_temp, phone_allUsersFile_temp, vehicle_allUsersFile_temp);

    for (i = 0;i < 99999; i++)
    {
        //scan info from the file
        if (username == username_driversFile_temp)
        {
            if(password == pass_driversFile_temp)
            {
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
                    fprintf(driversFile, "%d\t%d\t%d\t%s\t%s\t%s\t%s", NewUsername, pass_driversFile_temp, accountNumber_driversFile_temp, firstName_driversFile_temp, lastName_driversFile_temp, phone_driversFile_temp, vehicle_driversFile_temp);
                    //fprintf(allUsersFile, "\r%d\t%d\t%d\t%s\t%s\t%s\t%s", NewUsername, pass_allUsersFile_temp, accountNumber_allUsersFile_temp, firstName_allUsersFile_temp, lastName_allUsersFile_temp, phone_allUsersFile_temp, vehicle_allUsersFile_temp);
                    cout << "Username edited successfully." << endl;
                }
                else if(menuNumber == 2)
                {
                    char NewFirstName[21];
                    cout << "Enter new firstName\n";
                    scanf("%s", NewFirstName);
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
                    fprintf(driversFile, "%d\t%d\t%d\t%s\t%s\t%s\t%s", username_driversFile_temp, pass_driversFile_temp, accountNumber_driversFile_temp, NewFirstName, lastName_driversFile_temp, phone_driversFile_temp, vehicle_driversFile_temp);
                    //fprintf(allUsersFile, "\r%d\t%d\t%d\t%s\t%s\t%s\t%s", username_allUsersFile_temp, pass_allUsersFile_temp, accountNumber_allUsersFile_temp, NewFirstName, lastName_allUsersFile_temp, phone_allUsersFile_temp, vehicle_allUsersFile_temp);
                    cout << "First name edited successfully." << endl;
                }
                else if(menuNumber == 3)
                {
                    char NewLastName[21];
                    cout << "Enter new lastName\n";
                    scanf("%s", NewLastName);
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
                    //fprintf(allUsersFile, "\r%d\t%d\t%d\t%s\t%s\t%s\t%s", username_allUsersFile_temp, pass_allUsersFile_temp, accountNumber_allUsersFile_temp, firstName_allUsersFile_temp, NewLastName, phone_allUsersFile_temp, vehicle_allUsersFile_temp);
                    cout << "Last name edited successfully." << endl;
                }
                else if(menuNumber == 4)
                {
                    char NewPhone[20];
                    cout << "Enter new phone number\n";
                    scanf("%s", NewPhone);
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
                    //fprintf(allUsersFile, "\r%d\t%d\t%d\t%s\t%s\t%s\t%s", username_allUsersFile_temp, pass_allUsersFile_temp, accountNumber_allUsersFile_temp, firstName_allUsersFile_temp, lastName_allUsersFile_temp, NewPhone, vehicle_allUsersFile_temp);
                    cout << "Phone number edited successfully." << endl;
                }
                else if(menuNumber == 5)
                {
                    char NewVehicle[21];
                    cout << "Enter new vehicle\n";
                    scanf("%s", NewVehicle);
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
                    //fprintf(allUsersFile, "\r%d\t%d\t%d\t%s\t%s\t%s\t%s", username_allUsersFile_temp, pass_allUsersFile_temp, accountNumber_allUsersFile_temp, firstName_allUsersFile_temp, lastName_allUsersFile_temp, phone_allUsersFile_temp, NewVehicle);
                    cout << "Vehicle edited successfully." << endl;
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
        fscanf(driversFile, "\n%d\t%d\t%d\t%s\t%s\t%s\t%s", &username_driversFile_temp, &pass_driversFile_temp, &accountNumber_driversFile_temp, firstName_driversFile_temp, lastName_driversFile_temp, phone_driversFile_temp, vehicle_driversFile_temp);
        //fscanf(allUsersFile, "\n%d\t%d\t%d\t%s\t%s\t%s\t%s", &username_allUsersFile_temp, &pass_allUsersFile_temp, &accountNumber_allUsersFile_temp, firstName_allUsersFile_temp, lastName_allUsersFile_temp, phone_allUsersFile_temp, vehicle_allUsersFile_temp);
    }
    if(i >= 100000)
    {
        cout << "Sorry the username you have entered is not correct!!!\n";
    }
    //close open file
    fclose(driversFile);
    //fclose(allUsersFile);
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
