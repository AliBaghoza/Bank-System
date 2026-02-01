#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{

private:

    static  bool _Login()
    {
        bool LoginFaild = false;

        string Username, Password;
        short FaildLoginCount = 3;
        do
        {
           
            if (LoginFaild)
            {
                cout << "\nInvlaid Username/Password!";
                cout << "\nYou have " << (FaildLoginCount - 1) << " Trials to login\n\n";
                FaildLoginCount--;
               
                
            }
            
            if (FaildLoginCount == 0)
            {
                cout << "\nYour are Locked after 3 faild trails ";
                    return false;
            }
            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);

       CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();
        return true;
    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
       return _Login();

    }

};

