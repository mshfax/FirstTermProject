//guest needs to complete
//khare

#include <iostream>
#include <stdio.h>
#include <string>
#include "Admin.h"
#include "guest.h"
#include "drivers.h"

using namespace std;

//declaration functions
void signUp(); //function to sign up
void logIn(); //function to log in

int main()
{
    int n;
    while(1)
    {
        cout << "Enter the number of task you want to do please...\n";
        cout << "1. sign up\n";
        cout << "2. log in\n";
        cout << "3. log in as guest\n";
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
            break;
        }
        else if(n == 3)
        {
            //goes to function guest
			guestMain(1);
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

//definition functions
void signUp() //function to sign up
{
    const int m=299999;
    int i;
    int username = m;
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
    char reagent[20];
    cout << "Enter your first name please...\n";
    scanf("%s", firstName);
    cout << "Enter your last name:\n";
    scanf("%s", lastName);
    cout << "Enter your phone number:\n";
    scanf("%s", phone);
    cout << "Enter your account number:\n";
    cin >> account;
    cout << "Enter the password:\n";
    cin >> pass;
    cout << "Confirm the password:\n";
    cin >> pass_temp;
    cout << "Enter your reagent (if you have no reagent enter noReagent)\n";
    scanf("%s", reagent);
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
                    fprintf(allUsersFile, "%d\t%d\t%d\t%s\t%s\t%s\t%s\n", username, pass, account, firstName, lastName, phone, reagent);
                    fprintf(usersFile, "%d\t%d\t%d\t%s\t%s\t%s\t%s\n", username, pass, account, firstName, lastName, phone, reagent);
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
    //closing open files
    fclose(allUsersFile);
    fclose(usersFile);
}

void logIn() //function to log in
{
    //needs to be completed
    int i,r;
    int username,password,tempUserName;
    cout << "Enter your username please...\n";
    cin >> username;
    cout << "Enter your password:\n";
    cin >> password;
    FILE * allUsersFile = fopen("allUsers.txt","r");
    if(allUsersFile == NULL)
    {
        cout << "The File opening was Unsuccessful!\n";
        return;
    }
    int userName_temp, pass_temp, accountNumber;
    char firstName[21],lastName[21],phone[21],reagent[21];
    for(i = 0;i<100000;i++)
    {
        r = fscanf(allUsersFile,"%d\t%d\t%d\t%s\t%s\t%s\t%s\n", &userName_temp, &pass_temp, &accountNumber, firstName,lastName, phone, reagent);
        if(r != EOF)
        {
            if(username == userName_temp)
            {
                if(password == pass_temp)
                {
                    tempUserName = username / 100000;
                    if(tempUserName == 1)
                    {
                        //goes to admin function
                        cout << "Hi " << firstName << endl;
                        adminMain();
                        return;
                    }
                    else if(tempUserName == 3)
                    {
                        // goes to user function
                        cout << "Hi " << firstName << endl;

                        break;
                    }
                    else if(tempUserName == 5)
                    {
                        //goes to driver function
                        cout << "Hi " << firstName << endl;
                        driversMain(username);
                        break;
                    }
                }
                else
                {
                    cout << "The password is incorrect!\n";
                    return;
                }
            }
        }
    }
    if(i >= 100000)
    {
        cout << "The username is incorrect!\n";
    }

    fclose(allUsersFile);
}
