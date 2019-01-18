//
// Created by mostafa on 12/25/18.
//

#ifndef PROJECT_GUEST_H
#define PROJECT_GUEST_H

#endif //PROJECT_GUEST_H


#include <stdio.h>
#include <iostream>
using namespace std;
//functions declaration

void Reservation();



void guestMain() {//what guest want to do
	int n;
	while (1)
	{
		cout << "Do you want to buy a ticket?\n\nPress the number of act that you want to do!\n\n";

		cout << "1.YES\n\n";
		cout << "2.NO\n\n\n";

		cin >> n;


		if (n == 1) {

			Reservation();
		}
		else if (n == 2) {

			return;
		}
		else
		{
			cout << "The number you inserted is not correct!\n\n";
			return;
		}

	}
}




void Reservation() {
	int i;
	FILE *reserve = fopen("guest.txt", "a");

	FILE * accountsFile = fopen("accounts.txt", "r");

	if (reserve == NULL) {
		printf("An error occurd during opennig file!\n");

		return;
	}
	if (accountsFile == NULL) {
		printf("An error occurd during opennig file!\n");

		return;
	}
	int account, pass;
	int account_temp, pass_temp, cash;
	char firstName[30];
	char lastName[30];
	char phone[30];
	char reagent[20];
	cout << "Enter your first name please...\n\n";
	scanf("%s", firstName);
	cout << "Enter your last name:\n\n";
	scanf("%s", lastName, "\n");
	cout << "Enter your phone number:\n\n";
	scanf("%s", phone, "\n");
	cout << "Enter your account number:\n\n";
	cin >> account;
	cout << "\n";
	cout << "Enter the password:\n\n";
	cout << "\n";
	cin >> pass;
	cout << "Confirm the password:\n\n";
	cin >> pass_temp;

	if (pass == pass_temp)
	{

		for (i = 0; i < 100000; i++)
		{
			fscanf(accountsFile, "%d\t%d\t%d\n", &account_temp, &pass_temp, &cash);
			if (account_temp == account)
			{
				if (pass_temp == pass)
				{
					fprintf(reserve, "%s\t%s\t%d\t%d\t%d\n", firstName, lastName, account, pass, phone);

					cout << "Hi" << "\t" << firstName << "\n";
					break;
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
	fclose(reserve);

}



