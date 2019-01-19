//
// Created by mostafa on 1/18/19.
//

#ifndef PROJECT_USER_H
#define PROJECT_USER_H

#endif //PROJECT_USER_H

#include <iostream>
#include <stdio.h>


using namespace std;

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

	}
	else if (menuNumber == 2)
	{
		//goes to function cancel ticket for user
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



void book(int username, int account_Number, int password)
{
	int i, r;
	FILE * allUsersFile = fopen("allUsers.txt", "r");
	if (allUsersFile == NULL)
	{
		cout << "The File opening was Unsuccessful!\n";
		return;
	}
	int userName_temp, pass_temp, accountNumber;
	char firstName[21], lastName[21], phone[21], reagent[21];
	for (i = 0; i<100000; i++)
	{
		fscanf(allUsersFile, "%d\t%d\t%d\t%s\t%s\t%s\t%s\n", &userName_temp, &pass_temp, &accountNumber, firstName, lastName, phone, reagent);
		if (username == userName_temp)
		{
			if (password == pass_temp)
			{







			}
			else
			{
				cout << "The password is incorrect!\n";
				return;
			}
		}

















	}