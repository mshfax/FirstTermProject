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
void cancelTicket();
void seeHistoryOfTickets(int ,int, int);//complete

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
		cancelTicket();
		return;
	}
	else if (menuNumber == 3)
	{
		//goes to finction to see history of tickets
        seeHistoryOfTickets(username, account_Number, password);
        return;
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
    int username_temp, driverUsername, origin, destination, startTripHour, startTripMinute, year, month, day, cast_temp;
    char trackingCode[15];
    bool r = false;
	int temp = getc(ticketFile);
	fseek(ticketFile, -1, SEEK_CUR);
    cout << "Enter what you desire to do.\n";
    cout << "1. See active tickets\n";
    cout << "2. See all tickets\n";
    int ticketNumber;
    cin >> ticketNumber;
	cout << "The tickets will be displayed in the format below\n";
    cout << "FirstName\tLastName\tusername\tdriverUsername\torigin\tdestination\tstartTripTime\tdate\ttrackingCode\n\n";
    for (int i = 0; i<100000 && temp!=EOF; i++)
	{
    	fscanf(ticketFile, "%s\t%s\t%d\t%d\t%d\t%d\t%d:%d\t%d/%d/%d\t%s\t%d", firstName, lastName, &username_temp, &driverUsername, &origin, &destination, &startTripHour, &startTripMinute, &year, &month, &day, trackingCode, cast_temp);
		temp = getc(ticketFile);
		fseek(ticketFile, -1, SEEK_CUR);
		fscanf(ticketFile, "\n");
		if(username_temp == username)
		{
            // current date/time based on current system
            time_t now = time(0);
            tm *ltm = localtime(&now);
            int yearSys, monthSys, daySys, hourSys, minuteSys;
            yearSys = 1900 + ltm->tm_year;
            monthSys = 1 + ltm->tm_mon;
            daySys = ltm->tm_mday;
            hourSys = ltm->tm_hour;
            minuteSys = ltm->tm_min;
            if(ticketNumber == 1)
            {
                if (monthSys == month)
                {
                    if(daySys == day)
                    {
                        if(hourSys > startTripHour)
                        {

                        }
                        else
                        {
                            printf("%s\t%s\t%d\t%d\t%d\t%d\t%d:%d\t%d/%d/%d\t%s", firstName, lastName, username_temp, driverUsername, origin, destination, startTripHour, startTripMinute, year, month, day, trackingCode);
                        }
                    }
                    else if(daySys > day)
                    {

                    }
                    else if(daySys < day)
                    {
                        printf("%s\t%s\t%d\t%d\t%d\t%d\t%d:%d\t%d/%d/%d\t%s", firstName, lastName, username_temp, driverUsername, origin, destination, startTripHour, startTripMinute, year, month, day, trackingCode);
                    }
                }
                else if(monthSys > month)
                {

                }
                else if(monthSys < month)
                {
                    printf("%s\t%s\t%d\t%d\t%d\t%d\t%d:%d\t%d/%d/%d\t%s", firstName, lastName, username_temp, driverUsername, origin, destination, startTripHour, startTripMinute, year, month, day, trackingCode);
                }

            }
            else if(ticketNumber == 2)
            {
                printf("%s\t%s\t%d\t%d\t%d\t%d\t%d:%d\t%d/%d/%d\t%s", firstName, lastName, username_temp, driverUsername, origin, destination, startTripHour, startTripMinute, year, month, day, trackingCode);
            }
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


void cancelTicket()//completed
{
    char trackingCode[15];
    cout << "Enter trackingCode of ticket you want to cancel\n";
    scanf("%s", trackingCode);
    FILE * ticketFile = fopen("ticket.txt", "r");
    if(ticketFile == NULL)
    {
        cout << "The File opening was Unsuccessful!\n";
        return;
    }
    char firstName[30], lastName[30], trackingCode_temp[10];
    int driversUsername, origin, destination;
    int timemin, timehour, year_ttrip, month_ttrip, day_ttrip, userName, price_temp;
    int c;
    c = getc(ticketFile);
    fseek(ticketFile, -1, SEEK_CUR);
    int lineNumber;
    for (lineNumber = 1;c != EOF; lineNumber++)
    {
        fscanf(ticketFile, "%s\t%s\t%d\t%d\t%d\t%d\t%d:%d\t%d/%d/%d\t%s\t%d\n", firstName, lastName, &userName, &driversUsername, &origin, &destination,&timemin, &timehour, &year_ttrip, &month_ttrip, &day_ttrip, trackingCode_temp, &price_temp);
        c = getc(ticketFile);
        fseek(ticketFile, -1, SEEK_CUR);
        fscanf(ticketFile, "\n");
        if(strcmp(trackingCode, trackingCode_temp) == 0)
        {
            float cast = price_temp;
            float userCash, adminCash, driverCash;
            userCash = cast;
            adminCash = cast * (0.1);
            driverCash = cast * (0.9);
            int user_account = findAccountNumber(userName);
            const int admin_account = 200000;
            const int admin_pass = 1318;
            int driver_account = findAccountNumber(driversUsername);
            int userPass = findPass(user_account);
            int driver_Pass = findPass(driver_account);
            printInAccountFileAndTransactions((int)userCash,(int) adminCash,(int) driverCash, user_account, admin_account, driver_account, userPass, admin_pass, driver_Pass, trackingCode);
            break;
        }
    }
    fclose(ticketFile);
    FILE *fileptr1, *fileptr2;
    char filename[40];
    char ch;
    int delete_line = lineNumber, temp = 1;
    strcpy(filename, "ticket.txt");
    fileptr1 = fopen(filename, "r");
    //rewind
    rewind(fileptr1);
    //open new file in write mode
    fileptr2 = fopen("replica.c", "w");
    ch = 'A';
    while (ch != EOF)
    {
        ch = getc(fileptr1);
        //except the line to be deleted
        if (temp != delete_line)
        {
            //copy all lines in file replica.c
            putc(ch, fileptr2);
        }
        if (ch == '\n')
        {
            temp++;
        }
    }
    fclose(fileptr1);
    fclose(fileptr2);
    remove(filename);
    //rename the file replica.c to original name
    rename("replica.c", filename);
}
