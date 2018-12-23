#include <iostream>
#include <stdio.h>
#include "Admin.h"

using namespace std;

void signUp() //function to sign up
{
    //need to be completed

}

void logIn() //function to log in
{
    //needs to be completed

}

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