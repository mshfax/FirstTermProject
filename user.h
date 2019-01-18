//
// Created by mostafa on 1/18/19.
//

#ifndef PROJECT_USER_H
#define PROJECT_USER_H

#endif //PROJECT_USER_H

#include <iostream>
#include <stdio.h>


using namespace std;

void userMain(int username, int accountNumber)
{
    cout << "Enter the number of task you want to do please\n";
    cout << "1. Buy ticket\n";
    cout << "2. Cancel ticket\n";
    cout << "3. See history of tickets\n";
    cout << "0. Exit\n";
    int menuNumber;
    cin >> menuNumber;
    if(menuNumber == 1)
    {
        //goes to function for buy ticket

    }
    else if(menuNumber == 2)
    {
        //goes to function cancel ticket for user
    }
    else if(menuNumber == 3)
    {
        //goes to finction to see history of tickets
    }
    else if(menuNumber == 0)
    {
        return;
    }
    else
    {
        cout << "Sorry the number you have entered is not correct!! Try again please..\n\n";
        return;
    }

}
