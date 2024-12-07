#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
#define _nguyen_ int main()
vector<string> choice = {"@gmail.com", "@outlook.com"};
string name, Email = "";
int number, Day, Month, Year, chooseemail;
void NameStandardize(string &s);
void Email1();
void Email2();
void Email3();
void EmailGenerate();
void NameStandardize(string &s)
{
    int n = s.size() - 1;
    while(s[0] == ' ') s.erase(0, 1);
    while(s[n] == ' ') s.erase(n, 1);
    while(true) {
        int x = s.find("  ");
        if(x > -1) s.erase(x, 1);
        else break;
    }
    for(int i = 0; i < s.size(); i++) {
        if(isupper(s[i])) s[i] += 32;
    }
}
void Email1()
{
    Email = "";
    vector<string> subname(4); int i = 0;
    stringstream ss(name); string word;
    char F[4];
    while(ss >> word) {
        subname[i] = word;
        F[i] = word[0];
        i++;
    }
    Email += subname[i - 1];
    for(int j = 0; j < i - 1; j++) {
        Email += F[j]; 
    }
    string day = to_string(Day), month = to_string(Month), year = to_string(Year);
    if(day.size() == 1) {
        Email += '0' + day;
    }
    else {
        Email += day;
    }
    if(month.size() == 1) {
        Email += '0' + month;
    }
    else {
        Email += month;
    }
    string subyear = year.substr(year.size() / 2, 2);
    Email += subyear + choice[number - 1];
}
void Email2()
{
    Email = "";
    vector<string> subname(10); int i = 0;
    stringstream ss(name); string word;
    char F[4];
    while(ss >> word) {
        subname[i] = word;
        F[i] = word[0];
        i++;
    }
    for(int j = 0; j < i; j++)
        Email += F[j]; 
    Email += subname[i - 1];
    string day = to_string(Day), month = to_string(Month), year = to_string(Year);
    if(day.size() == 1) {
        Email += '0' + day;
    }
    else {
        Email += day;
    }
    if(month.size() == 1) {
        Email += '0' + month;
    }
    else {
        Email += month;
    }
    Email += year + choice[number - 1];
}
void Email3()
{
    Email = "";
    vector<string> subname(4); int i = 0;
    stringstream ss(name); string word;
    while(ss >> word) {
        subname[i] = word;
        i++;
    }
    for(int j = 0; j < i; j++)
        Email += subname[j];
    string day = to_string(Day), month = to_string(Month), year = to_string(Year);
    if(day.size() == 1) {
        Email += '0' + day;
    }
    else {
        Email += day;
    }
    if(month.size() == 1) {
        Email += '0' + month;
    }
    else {
        Email += month;
    }
    Email += year + choice[number - 1];
}
void EmailGenerate()
{
    cout << "Welcome to EmailMaker!!! \n";
    Sleep(2100);
    //sleep(2);
    cout << "This app will generate an email but just for fun so just enjoy! :))\n";
    Sleep(2300);
    //sleep(2);
    cout << "Type your full name: \n";
    getline(cin, name);
    NameStandardize(name);
    while(true) {
        cout << "Choose your type of email:\n";
        cout << "1. Gmail.       2.Outlook.\n";
        cout << "Choose [1/2]: ";
        cin >> number;
        if(number < 1 || number > 2) 
            cout << "Try again \n";
        else break;
    }
    cout << "Choose your Date of Birth: \n";
    while(true) {
        while(true) {
            cout << "Day[1 -> 31]: "; 
            cin >> Day;
            if(Day < 1 || Day > 31) {
                cout << "Try again \n";
            }
            else break;
        }
        while(true) {
            cout << "Month[1 -> 12]: ";
            cin >> Month;
            if(Month < 1 || Month > 12) {
                cout << "Try again \n";
            }
            else break;
        }
        while(true) {
            cout << "Year[1900 -> 2021]: ";
            cin >> Year;
            if(Year < 1900 || Year > 2021) {
                cout << "Try again \n";
            }
            else break;
        }
        break;
    }
    while(true) {
        cout << "Choose one of these: [1/2/3/4] \n";
        Email1(); cout << "1. " << Email;
        Email2(); cout << "\n2. " << Email;
        Email3(); cout << "\n3. " << Email;
        cout << "\n4. Let me type another\n";
        cin >> chooseemail;
        if(chooseemail == 4) {
            cout << "Type correctly (Example: name) ";
            string myemail;
            cin >> myemail;
            Email = myemail;
            Email += choice[number - 1];
            break;
        }
        else if(chooseemail == 1) {
            Email1();
            break;
        }
        else if(chooseemail == 2) {
            Email2();
            break;
        }
        else if(chooseemail == 3) {
            Email3();
            break;
        }
        else
            cout << "Try again\n";
    }
    cout << "Generating your Gmail...\n";
    Sleep(1000);
    //sleep(1);
    cout << "Please wait...\n";
    Sleep(1350);
    //sleep(1);
    cout << "Your Email has successfully generated!\n";
    cout << "Here is your Email: \n";
    cout << Email;
}
_nguyen_
{
    EmailGenerate();
    return 0;
}