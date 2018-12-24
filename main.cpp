#include <iostream>
#include <stdio.h>
#include <string>
#include "Admin.h"

using namespace std;

//declaration functions
void signUp(); //function to sign up
void logIn(); //function to log in

int main()
{
    int n;
    while(1)
    {
        cout << "Enter the number of task you want to do\n";
        cout << "1. sign up\n";
        cout << "2. log in\n";
        cout << "0. Exit\n";
        cin >> n;
        if(n == 1)
        {
            //goes to function sign up
            signUp();
        }
        else if(n == 2)
        {
            //goes to function log in
            logIn();
        }
        else if(n == 0)
        {
            return 0;
        }
        else
        {
            cout << "The number you inserted is not correct!\n";
            return -1;
        }
    }
}

void signUp() //function to sign up
{
    const int n=200000;
    const int m=299999;
    int i;
    int username = m;
    int username_temp = n;
    //need to be completed
    FILE * allUsersFile = fopen("allUsers.txt" , "a");
    FILE * usersFile = fopen("users.txt" , "a");
    FILE * accountsFile = fopen("accounts.txt","r");

    //check to show an Error if the files could not OPEN
    if(allUsersFile == NULL)
    {
        cout << "The File opening was Unsuccessful!\n";
        return;
    }
    if(usersFile == NULL)
    {
        cout << "The File opening was Unsuccessful!\n";
        return;
    }
    if(accountsFile == NULL)
    {
        cout << "The File opening was Unsuccessful!\n";
        return;
    }
    // start sign Up
    int account, pass;
    int account_temp,pass_temp,cash;

    char firstName[30];
    char lastName[30];
    char phone[30];
    cout << "Enter your first name please...\n";
    scanf("%s", firstName);
    cout << "Enter your last name please...\n";
    scanf("%s", lastName);
    cout << "Enter your phone number please...\n";
    scanf("%s", phone);
    cout << "Enter your account number please...\n";
    cin >> account;
    cout << "Enter the password please...\n";
    cin >> pass;
    cout << "Confirm the password please...\n";
    cin >> pass_temp;
    if(pass == pass_temp)
    {
        for(i = 0;i<100000;i++)
        {
            username++;
            fscanf(accountsFile,"%d\t%d\t%d\n", &account_temp, &pass_temp, &cash);
            if(account_temp == account)
            {
                if(pass_temp == pass)
                {
                    fprintf(allUsersFile, "%d\t%d\t%d\t%s\t%s\t%s\n", username, pass, account, firstName, lastName, phone);
                    fprintf(usersFile, "%d\t%d\t%d\t%s\t%s\t%s\n", username, pass, account, firstName, lastName, phone);
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

    fclose(allUsersFile);
    fclose(usersFile);
}

void logIn() //function to log in
{
    //needs to be completed

}
