#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

void login();
void registration();
void forgot();

// creating MENU for the page
int main()
{

    int choice;
    cout<<"\t\t\t__________________________________________________\n\n\n";
    cout<<"\t\t\t               Welcome to the login Page          \n\n\n";
    cout<<"\t\t\t______________          MENU            ____________\n\n";
    cout<<"                                                          \n\n";
    cout<<"\t | Press 1 to LOGIN                          |"<<endl;
    cout<<"\t | Press 2 to REGISTER                       |"<<endl;    
    cout<<"\t | Forgot Password?? Press 3                 |"<<endl;
    cout<<"\t | Press 4 to EXIT                           |"<<endl;
    cout<<"\n\t\t\t Please enter your choice: ";
    
    cin>>choice;
    cout<<endl;

    switch(choice)
    {
        case 1:
            login();
            break;
        
        case 2:
            registration();
            break;

        case 3:
            forgot();
            break;
        
        case 4:
            cout<<"\t\t\t   Thank You!   \n\n";
            break;
        
        default:
            system("cls"); // clears the screen everytime the program is run
            cout<<"\t\t\t  Please select only the options provided above. \n\n"<<endl;
            main();
    }
}


//create login() function
void login()
{
    int count;
    string userId, password, id, pass;
    system("cls");
    cout<<"\t\t\t Please enter your Username and password : "<<endl;
    cout<<"\t\t\t USERNAME: ";
    cin>>userId;
    cout<<"\t\t\t PASSWORD: ";
    cin>>password;

    //check if the username and password is already in the file
    ifstream input("records.txt"); //checks this file for the id and pass
    // here, 'input' is the object of ifstream class
    while (input>>id>>pass)
    {
        if(id == userId && pass == password)
        {
            count = 1;
            system("cls");
        }
    }
    //close this file 'records.txt'
    input.close();

    if (count == 1)
    {
        cout<<userId<<"\t\t\t\t\t SUCCESSFULL LOGIN! \n";
        main();
    }
    else 
    {
        cout<<"\n Can't find an account with the Credentials you entered.";
        cout<<"Please check your username & password and TRY AGAIN! \n";
        //shifts control back to the 'main' function since it contains the Main MENU
        main();
    }
}


//Registration function
void registration()
{
    string ruserId, rpassword, rid, rpass;
    system("cls");
    cout<<"\t\t\t Enter a username: ";
    cin>>ruserId;
    cout<<"\t\t\t Enter a password: ";
    cin>>rpassword;

    //now we use 'ofstream' class since we will write inside a file
    //ios means 'input output stream', app means append mode: opens file & appends it
    ofstream f1("records.txt", ios::app);
    //now writing to the file
    f1<<ruserId<<" "<<rpassword<<endl;
    system("cls");

    //Display saying registration is successfull
    cout<<"\t\t\t  SUCCESSFULL Registration! \n";
    main();
}


//forgot password function
void forgot()
{
    int option;
    system("cls");
    cout<<"\t\t\t No worries. I gotch you! \n";
    cout<<"Press 1 to search your id by username: "<<endl;
    cout<<"Press 2 to go back to Main MENU."<<endl;
    cout<<"\t\t\t  Enter your choice: ";
    cin>>option;

    switch(option)
    {
        case 1:
        {
            int count = 0;
            string suserId, sId, spass;
            cout<<"\n\t\t\t Enter the username you remember using the last time: ";
            cin>>suserId;

            //check if suserId exists in the records.txt file
            ifstream f2("records.txt"); // f2 is the object of ifstream
            while(f2>>sId>>spass)
            {
                if (sId == suserId)
                {
                    count = 1;
                }
            }
            //close the file
            f2.close();

            if(count == 1)
            {
                cout<<"\n\n Your account is found! \n";
                cout<<"\n\n Your password is : "<<spass;
                main();
            }
            else 
            {
                cout<<"\n\t Sorry! We did not find your account. \n";
                main();
            }
        }

        break;

        case 2:
        {
            main(); //control goes back to the main MENU
        }

        default: 
            cout<<"\t\t\t Wrong choice! Please try again "<<endl;
            forgot();
    }
}