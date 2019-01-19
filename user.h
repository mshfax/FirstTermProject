//
// Created by mostafa on 1/18/19.
//

#ifndef PROJECT_USER_H
#define PROJECT_USER_H

#endif //PROJECT_USER_H

#include <iostream>
#include <stdio.h>


using namespace std;

//declation functions
void seeHistoryOfTickets(int ,int, int);

void userMain(int username, int account_Number, int password)
{
	cout << "Enter the number of task you want to do please\n";
	cout << "1. Buy ticket\n";
	cout << "2. Cancel ticket\n";
	cout << "3. See history of tickets\n";
	cout << "0. Exit\n";
	int menuNumber;
	cin >> menuNumber;
	if (menuNumber == 1)
	{
		userTicket(username, account_Number, password);
		return;

	}
	else if (menuNumber == 2)
	{
		//goes to function cancel ticket for user
		seeHistoryOfTickets(username, account_Number, password);
		return;
	}
	else if (menuNumber == 3)
	{
		//goes to finction to see history of tickets
	}
	else if (menuNumber == 0)
	{
		return;
	}
	else
	{
		cout << "Sorry the number you have entered is not correct!! Try again please..\n\n";
		return;
	}

}


//definition functions
void seeHistoryOfTickets(int username, int accountNumber, int password)
{
    FILE * ticketFile = fopen("ticket.txt", "r");
    if(ticketFile == NULL)
	{
		cout << "The File opening was Unsuccessful!\n";
		return;
	}
    char firstName[30], lastName[30];
    int username_temp, driverUsername, origin, destination, startTripHour, startTripMinute, year, month, day;
    char trackingCode[15];
    bool r = false;
	int temp = getc(ticketFile);
	fseek(ticketFile, -1, SEEK_CUR);
    for (int i = 0; i<100000 && temp!=EOF; i++)
	{
    	fscanf(ticketFile, "%s\t%s\t%d\t%d\t%d\t%d\t%d:%d\t%d\t%d\t%d\t%s", firstName, lastName, &username_temp, &driverUsername, &origin, &destination, &startTripHour, &startTripMinute, &year, &month, &day, trackingCode);
		temp = getc(ticketFile);
		fseek(ticketFile, -1, SEEK_CUR);
		fscanf(ticketFile, "\n");
		if(username_temp == username)
		{







			r = true;

		}
	}
	if(r == false)
	{
		cout << "You have no declared trip\n";
		return;
	}
    //close file
    fclose(ticketFile);
}
