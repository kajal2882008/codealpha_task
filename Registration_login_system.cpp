#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

// Validate username
bool validUsername(string username)
{
    if(username.length() < 3)
        return false;

    for(char c : username)
    {
        if(!isalnum(c) && c != '_')
            return false;
    }
    return true;
}

// Validate password
bool validPassword(string password)
{
    if(password.length() < 8)
        return false;

    bool upper=false, lower=false, digit=false, special=false;

    for(char c : password)
    {
        if(isupper(c))
            upper=true;
        else if(islower(c))
            lower=true;
        else if(isdigit(c))
            digit=true;
        else
            special=true;
    }

    return upper && lower && digit && special;
}

// Register user
void registerUser()
{
    string username,password,user,pass;
    bool found=false;

    cout<<"\n===== User Registration =====\n";

    cout<<"Enter Username: ";
    cin>>username;

    if(!validUsername(username))
    {
        cout<<"Invalid Username!\n";
        return;
    }

    ifstream fin("users.txt");

    while(fin>>user>>pass)
    {
        if(user==username)
        {
            found=true;
            break;
        }
    }

    fin.close();

    if(found)
    {
        cout<<"Username already exists!\n";
        return;
    }

    cout<<"Enter Password: ";
    cin>>password;

    if(!validPassword(password))
    {
        cout<<"Password must contain:\n";
        cout<<"- At least 8 characters\n";
        cout<<"- One uppercase letter\n";
        cout<<"- One lowercase letter\n";
        cout<<"- One digit\n";
        cout<<"- One special character\n";
        return;
    }

    ofstream fout("users.txt",ios::app);
    fout<<username<<" "<<password<<endl;
    fout.close();

    cout<<"Registration Successful!\n";
}

// Login user
void loginUser()
{
    string username,password,user,pass;
    bool success=false;

    cout<<"\n===== User Login =====\n";

    cout<<"Enter Username: ";
    cin>>username;

    cout<<"Enter Password: ";
    cin>>password;

    ifstream fin("users.txt");

    while(fin>>user>>pass)
    {
        if(user==username && pass==password)
        {
            success=true;
            break;
        }
    }

    fin.close();

    if(success)
        cout<<"Login Successful! Welcome "<<username<<"!\n";
    else
        cout<<"Invalid Username or Password!\n";
}

// List all users
void listUsers()
{
    ifstream fin("users.txt");

    string username,password;

    cout<<"\n===== Registered Users =====\n";

    while(fin>>username>>password)
    {
        cout<<username<<endl;
    }

    fin.close();
}

int main()
{
    int choice;

    do
    {
        cout<<"\n============================\n";
        cout<<" Registration & Login System\n";
        cout<<"============================\n";
        cout<<"1. Register\n";
        cout<<"2. Login\n";
        cout<<"3. List Users\n";
        cout<<"4. Exit\n";
        cout<<"Enter Choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                listUsers();
                break;

            case 4:
                cout<<"Thank You!\n";
                break;

            default:
                cout<<"Invalid Choice!\n";
        }

    }while(choice!=4);

    return 0;
}