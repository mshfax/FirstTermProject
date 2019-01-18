//
// Created by mostafa on 1/18/19.
//

#ifndef PROJECT_TICKET_H
#define PROJECT_TICKET_H

#endif //PROJECT_TICKET_H


#include <stdio.h>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <string.h>


using namespace std;
//functions declaration
void ticketuser();
void ticketguest();
void ticketMain();
void printInAccountFile(int,int,int,int,int,int,int,int,int);
void ticketuser(int, int, int, char, char, char, char);

void printInAccountFile(int,int,int,int,int,int,int,int,int,char[]);


/*void ticketMain(int number) {//whatdo you want to do
    int n;
    cout << "Enter 0 to go back and 1 to continue\n";
    cin >> n;
    if (n == 1)
    {
        if(number == 1)
        {
            //go to ticketGuest function
            ticketguest();
        }
        else
    }
}*/




void ticketGuest()
{
    int number;
    cout << "Enter 0 to go back and 1 to continue.\n";
    cin >> number;
    if(number == 0)
    {
        return;
    }
    int i;
    FILE * ticketFile = fopen("ticket.txt", "a");
    FILE * tripFile = fopen("Trips.txt", "r");
    FILE * accountsFile = fopen("accounts.txt", "r");
    if(ticketFile == NULL || tripFile == NULL || accountsFile == NULL)
    {
        cout << "The File opening was Unsuccessful!\n";
        return;
    }
    const int accountNumber_admin = 200000;
    const int password_admin = 1318;
    int driver_pass;
    int origin;
    int destination;
    int driver_mony = 0, admin_mony = 0, passenger_mony = 0;
    int taid;
    int Nvehicle;//the vahicle number
    int origin_temp, destination_temp, driverUsername, startTimeHour, startTimeMinute, timeDurationHour, timeDurationMinute, way_temp, cast_temp;
    int account, pass;
    int account_temp, pass_temp, cash;
    char firstName[30], lastName[30];
    char phone[30];
    char vehicle[20], vehicle_temp[20];
    char reagent[20];
    cout << "Enter your first name please...\n\n";
    scanf("%s", firstName);
    cout << "Enter your last name:\n\n";
    scanf("%s", lastName, "\n");
    cout << "enter origin\n";
    cin >> origin;
    cout << "enter destination\n";
    cin >> destination;
    cout << "Select the desired vehicle number...\n";
    cout << "1. bus\n2. train\n3. airplane\n";
    cin >> Nvehicle;
    if (Nvehicle == 1)
    {
        strcpy(vehicle, "bus");
    }
    else if (Nvehicle == 2)
    {
        strcpy(vehicle, "train");
    }
    else if (Nvehicle == 3)
    {
        strcpy(vehicle, "airplane");
    }
    else
    {
        cout << "The number you inserted is not correct!";
    }

    cout << "Enter your phone number:\n\n";
    scanf("%s", phone);
    cout << "Enter your account number:\n\n";
    cin >> account;
    cout << "\n";
    cout << "Enter the password:\n\n";
    cout << "\n";
    cin >> pass;
    cout << "Confirm the password:\n\n";
    cin >> pass_temp;
    cout << "\n\n";
    if (pass == pass_temp)
    {
        for (i = 0; i < 100000; i++)
        {
            fscanf(accountsFile, "%d\t%d\t%d\n", &account_temp, &pass_temp, &cash);
            if (account_temp == account)
            {
                if (pass_temp == pass)
                {
                    for (int i = 0;; i++)
                    {
                        fscanf(tripFile, "%d\t%d\t%d\t%d\t%d:%d\t%d:%d\t%s\t%d\n", &driverUsername, &origin_temp, &destination_temp, &way_temp, &startTimeHour, &startTimeMinute, &timeDurationHour, &timeDurationMinute, vehicle_temp, &cast_temp);
                        if (origin == origin_temp && destination == destination_temp && strcmp(vehicle,vehicle_temp) == 0)
                        {
                            /*if (driverUsername == account_temp)
                            {
                                driver_pass = pass_temp;
                            }*/
                            cout << "Hi" << "\t" << firstName << "\n\n";
                            cout << "Your route:\t" << origin_temp << "_" << destination_temp << "\n\n";
                            cout << "The distance between two cities:  " << way_temp << "\n\n";
                            printf("departure time:\t%d:%d\n", startTimeHour, startTimeMinute);
                            printf("Time of travel:\t%d:%d\n\n", timeDurationHour, timeDurationMinute);
                            cout << "The rate of each seat:\t" << cast_temp << "\n\n";
                            cout << "Passenger name:\t" << firstName << " " << lastName << "\n\n";
                            cout << "Phone:\t" << phone << "\n\n";
                            cout << "Seat number:\t" << "_" << "\n\n\n";
                            cout << "press 1 to reseve\n";
                            cout << "or press 0 to exit\n";
                            cin >> taid;
                            if (taid == 1)
                            {
                                driver_mony = cast_temp*(9 / 10);
                                admin_mony =cast_temp*(1 / 10);
                                passenger_mony = cast_temp;

                                //give a randomNumber
                                srand(time(NULL));
                                char arr[] = "123456789";
                                char trackingCode[10];
                                for(int i = 0; i<9; i++)
                                {
                                    trackingCode[i] = arr[rand()%9];
                                }
                                trackingCode[10] = '\0';
                                printInAccountFile(passenger_mony,admin_mony,driver_mony,account,accountNumber_admin,account,pass,password_admin,driver_pass, trackingCode);

                                fprintf(ticketFile, "%s\t%s\t%d\t%d\t%d\t%d:%d\t%s", firstName, lastName, driverUsername, origin_temp, destination_temp, startTimeHour, startTimeMinute, trackingCode);
                                cout << "mission accomplished\n";
                            }
                            else
                            {
                                break;
                            }
                            break;
                        }
                    }
                }
                else
                {
                    cout << "Sorry the password is incorrect...\n";
                }
            }
        }
        if (i == 100000)
        {
            cout << "The account number you have entered is incorrect! Try again please...\n";
        }
    }
    else
    {
        cout << "two passwords are not the same !!!\n";
        return;
    }


    fclose(ticketFile);
    fclose(tripFile);
    fclose(accountsFile);
}

<<<<<<< HEAD

void ticketuser(int userName_temp, int pass_temp, int accountNumber, char firstName, char lastName, char phone, char reagent) 
{

	for (int i = 0;; i++)
	{


		fscanf(trip, "%d\t%d\t%d\t%d\t%d:%d\t%d:%d\t%s\t%d\n", &account_driver_temp, &origin_temp, &way_temp, &destination_temp, &time_origin_temp, &time_destination_temp, &vehicle_temp, &cast_temp);
		if (origin == origin_temp&&destination == destination_temp)
		{


			if (account_driver_temp == account_temp)
			{
				driver_pass = pass_temp;
			}
			cout << "Hi" << "\t" << firstName << "\n\n";
			cout << "Your route:\t" << origin_temp << "_" << destination_temp << "\n\n";
			cout << "The distance between two cities:  " << way_temp << "\n\n";
			cout << "departure time:\t" << time_origin_temp << "\t" << "time of travel:\t" << time_destination_temp << "\n\n";
			cout << "The rate of each seat:\t" << cast_temp << "\n\n";
			cout << "Passenger name:\t" << firstName << " " << lastName << "\n\n";
			cout << "Phone:\t" << phone << "\n\n";
			cout << "Seat number:\t" << "_" << "\n\n\n";
			cout << "press 1 to reseve\n";
			cout << "or press 0 to exit\n";
			cin >> taid;
			if (taid == 1)
			{
				driver_mony = cast_temp*(9 / 10);
				admin_mony = cast_temp*(1 / 10);
				passenger_mony = cast_temp;

				printInAccountFile(passenger_mony, admin_mony, driver_mony, account, accountNumber_admin, account_driver_temp, pass, password_admin, driver_pass);

				cout << "mission accomplished\n";

			}


			else
			{
				break;
			}
			break;
		}
		else
		{
			cout << "The vehicle you intended for your trip was not found\n";
			break;
		}

	}


}














void printInAccountFile(int userCash, int adminCash, int driverCash, int accountNumber_user, int accountNumber_admin, int accountNumber_driver, int password_user, int password_admin, int password_driver, char trackingCode[10])
{

	FILE*transactionFile = fopen("transaction.txt", a);
	if (transactionFile == NULL)
	{
		cout << "The File opening was Unsuccessful!\n";
		return;
	}

    FILE * accountsFile = fopen("accounts.txt", "r+");
    if(accountsFile == NULL)
    {
        cout << "The File opening was Unsuccessful!\n";
        return;
    }
    int accountNumber_temp, pass_temp, cash;
    fscanf(accountsFile, "%d\t%d\t%d", &accountNumber_temp, &pass_temp, &cash);
    int i;
    for (i = 0; i<100000; i++)
    {
        if(accountNumber_temp == accountNumber_user)
        {
            if(pass_temp == password_user)
            {
                //erase the line
                int j;
                char temp;      //for declare the end of a  line
                fseek(accountsFile, -1, SEEK_CUR);
                for(j = 0;;j++)
                {
                    fseek(accountsFile, -1, SEEK_CUR);
                    fscanf(accountsFile,"%c", &temp);
                    if(temp == 10)
                    {
                        break;
                    }
                    else
                    {
                        fseek(accountsFile, -1, SEEK_CUR);
                    }

                }
                for(int k = 0; k <= j; k++)
                {
                    fprintf(accountsFile, " ");
                }
                fseek(accountsFile, -1, SEEK_CUR);
                while(1)
                {
                    fseek(accountsFile, -1, SEEK_CUR);
                    fscanf(accountsFile,"%c", &temp);
                    if(temp == 10)
                    {
                        break;
                    }
                    else
                    {
                        fseek(accountsFile, -1, SEEK_CUR);
                    }
                }
                cash = cash - userCash;
				fprinf(transactionFile, "%d\t_%d\t", accountNumber_user, userCash);
                fprintf(accountsFile, "%d\t%d\t%d", accountNumber_user, password_user, cash);
                break;
            }
            else
            {
                cout << "Sorry the password you entered is incorrect.\n";
                break;
            }
        }
        else
        {
            fscanf(accountsFile, "\n%d\t%d\t%d", &accountNumber_temp, &pass_temp, &cash);
        }
    }
    if(i >= 100000)
    {
        cout << "Sorry the account number you have entered is not correct!\n";
        return;
    }
	///...
    fseek(accountsFile, 0, SEEK_SET);
    fscanf(accountsFile, "%d\t%d\t%d", &accountNumber_temp, &pass_temp, &cash);
    for (i = 0; i<100000; i++)
    {
        if(accountNumber_temp == accountNumber_admin)
        {
            if(pass_temp == password_admin)
            {
                //erase the line
                int j;
                char temp;      //for declare the end of a  line
                fseek(accountsFile, 0, SEEK_SET);
                /*for(j = 0;;j++)
                {
                    fseek(accountsFile, -1, SEEK_CUR);
                    fscanf(accountsFile,"%c", &temp);
                    if(temp == 10)
                    {
                        break;
                    }
                    else
                    {
                        fseek(accountsFile, -1, SEEK_CUR);
                    }
                }*/
                temp = getc(accountsFile);
                for(int k = 0; temp != 10; k++)
                {
                    fseek(accountsFile, -1, SEEK_CUR);
                    fprintf(accountsFile, " ");
                    temp = getc(accountsFile);
                }
                fseek(accountsFile, -1, SEEK_CUR);
                fseek(accountsFile, 0, SEEK_SET);
                /*while(1)
                {
                    fseek(accountsFile, -1, SEEK_CUR);
                    fscanf(accountsFile,"%c", &temp);
                    if(temp == 10)
                    {
                        break;
                    }
                    else
                    {
                        fseek(accountsFile, -1, SEEK_CUR);
                    }
                }*/
                cash = cash + adminCash;
				fprinf(transactionFile, "%d\t_%d\t", accountNumber_admin, adminCash);
                fprintf(accountsFile, "%d\t%d\t%d", accountNumber_admin, password_admin, cash);
                break;

            }
            else
            {
                cout << "Sorry the password you entered is incorrect.\n";
                break;
            }
        }
        else
        {
            fscanf(accountsFile, "\n%d\t%d\t%d", &accountNumber_temp, &pass_temp, &cash);
        }
    }
    if(i >= 100000)
    {
        cout << "Sorry the account number you have entered is not correct!\n";
        return;
    }
    fseek(accountsFile, 0, SEEK_SET);
    fscanf(accountsFile, "%d\t%d\t%d", &accountNumber_temp, &pass_temp, &cash);
    for (i = 0; i<100000; i++)
    {
        if(accountNumber_temp == accountNumber_driver)
        {
            if(pass_temp == password_driver)
            {
                //erase the line
                int j;
                char temp;      //for declare the end of a  line
                fseek(accountsFile, -1, SEEK_CUR);
                for(j = 0;;j++)
                {
                    fseek(accountsFile, -1, SEEK_CUR);
                    fscanf(accountsFile,"%c", &temp);
                    if(temp == 10)
                    {
                        break;
                    }
                    else
                    {
                        fseek(accountsFile, -1, SEEK_CUR);
                    }
                }
                for(int k = 0; k <= j; k++)
                {
                    fprintf(accountsFile, " ");
                }
                fseek(accountsFile, -1, SEEK_CUR);
                while(1)
                {
                    fseek(accountsFile, -1, SEEK_CUR);
                    fscanf(accountsFile,"%c", &temp);
                    if(temp == 10)
                    {
                        break;
                    }
                    else
                    {
                        fseek(accountsFile, -1, SEEK_CUR);
                    }
                }

             
                fprintf(accountsFile, "%d\t%d\t%d", accountNumber_driver, password_driver, driverCash);

                cash = cash + driverCash;
				fprinf(transactionFile, "%d\t_%d\n", accountNumber_driver, driverCash);
                fprintf(accountsFile, "%d\t%d\t%d", accountNumber_driver, password_driver, cash);

                break;
            }
            else
            {
                cout << "Sorry the password you entered is incorrect.\n";
                break;
            }
        }
        else
        {
            fscanf(accountsFile, "\n%d\t%d\t%d", &accountNumber_temp, &pass_temp, &cash);
        }
    }
    if(i >= 100000)
    {
        cout << "Sorry the account number you have entered is not correct!\n";
        return;
    }
    fclose(accountsFile);
	fclose(transactionFile);
}