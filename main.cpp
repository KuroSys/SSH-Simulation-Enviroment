#include <iostream>
#include <stdio.h>
#include <chrono>
#include <thread>

using namespace std;


std::string encrypt(std::string msg, std::string key)
{
    // Make sure the key is at least as long as the message
    std::string tmp(key);
    while (key.size() < msg.size())
        key += tmp;

    // encryption part
    for (std::string::size_type i = 0; i < msg.size(); ++i)
        msg[i] ^= key[i];
    return msg;
}

std::string decrypt(std::string msg, std::string key)
{
    return encrypt(msg, key); // lol
}



string password     = "SecurePassword";
string logged_user  = "root";
string hostname     = "mybox";
bool logged_in      = false;

void print_prompt()
{
    cout << logged_user << "@" << hostname << ": ";
}

void helptxt()
{
    cout << "Your task is to get the Admin's server password and login into their user." << endl;
}

void sshlogin()
{
    string sshpass = encrypt("Test", "dsad");
    cout << "password: ";
    cin >> password;
    if(sshpass == "HelloWorld1337"){
        cout << "Success (Challange completed!)" << endl;
        std::this_thread::sleep_for(9999999ms);
    }
    else{
        cout << "Invalid password. Please try again." << endl;
    }
}

void list()
{
    cout << "password.txt" << endl;
    cout << "help.txt" << endl;
}

void passwordtxt()
{
    string passs = encrypt("SGVsbG9Xb3JsZDEzMzc=", "idfkdw");

    cout << "user: root" << endl;
    cout << "ip: 192.168.12.34" << endl;
    cout << decrypt(passs, "idfkdw") << endl;
}

int main()
{
    bool exit = false;

    while(!exit)
    {
        if(!logged_in)
        {
            string enter_name;
            string enter_pw;

            cout << "login: ";
            cin >> enter_name;

            cout << "password: ";
            cin >> enter_pw;

            if(enter_pw.compare(password) == 0 && enter_name.compare(logged_user) == 0)
                logged_in = true;
            else
                cout << "Login failed, try again...\n";
            continue;
        }

        if(logged_in)
        {
            string command;


            if(std::getline(std::cin, command))
            {
                //Do sum
                if(command == "cat password.txt")
                    passwordtxt();
                if(command == "cat help.txt")
                    helptxt();
                if(command == "ls")
                   list();
                if(command == "exit")
                    break;
                if(command == "ssh root@192.168.12.34")
                    sshlogin();

            }
            else//do non
                continue;   //empty duh

            print_prompt();
        }
    }


    return 0;
}