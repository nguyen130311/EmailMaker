#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

// Thay đổi một số câu lệnh
// Some changes for the syntaxes
#define _nguyen_ int main()
#define in cin
#define out cout
#define during while
typedef stringstream mkwords;
typedef string mks;

// Tạo biến và mảng phục vụ cho việc tạo email 
// Declare variables and arrays for generating emails
vector<mks> choice = {"@gmail.com", "@outlook.com"};
mks name, Email = "";
int number, choose;
mks Day, Month, Year;

// Khai báo nguyên mẫu hàm
// Function Prototype
void NameStandardize(mks &s);
void InputInfo();
void InfoTransform();
void Email1(mks &Email);
void Email2(mks &Email);
void Email3(mks &Email);
void EmailGenerate();
void EmailExtract();

// Chuẩn hóa tên
// Standardize name
void NameStandardize(mks &s)
{
    int n = s.size() - 1;

    during(s[0] == ' ') 
        s.erase(0, 1);
    during(s[n] == ' ') 
        s.erase(n, 1);
    during(true) {
        int x = s.find("  ");
        if(x > -1) s.erase(x, 1);
        else break;
    }

    for(int i = 0; i < n; i++) 
        if(isupper(s[i])) s[i] += 32;
}

// Mẫu Email 1
// First email choice
void Email1(mks &Email)
{
    Email = "";
    vector<mks> subname(10); int i = 0;
    mkwords ss(name); mks word;
    char F[4];

    during(ss >> word) {
        subname[i] = word;
        F[i] = word[0];
        i++;
    }
    Email += subname[i - 1];
    for(int j = 0; j < i - 1; j++) 
        Email += F[j]; 

    mks day = Day, month = Month, year = Year;

    if(day.size() == 1) 
        Email += '0' + day;
    else 
        Email += day;
    if(month.size() == 1) 
        Email += '0' + month;
    else 
        Email += month;

    mks subyear = year.substr(year.size() / 2, 2);
    Email += subyear + choice[number - 1];
}

// Mẫu Email 2
// Second email choice
void Email2(mks &Email)
{
    Email = "";
    vector<mks> subname(10); int i = 0;
    mkwords ss(name); mks word;
    char F[4];

    during(ss >> word) {
        subname[i] = word;
        F[i] = word[0];
        i++;
    }
    for(int j = 0; j < i; j++)
        Email += F[j]; 
    Email += subname[i - 1];

    mks day = Day, month = Month, year = Year;

    if(day.size() == 1) 
        Email += '0' + day;
    else 
        Email += day;
    if(month.size() == 1) 
        Email += '0' + month;
    else 
        Email += month;
    Email += year + choice[number - 1];
}

// Mẫu Email 3
// Third email choice
void Email3(mks &Email)
{
    Email = "";
    vector<mks> subname(10); int i = 0;
    mkwords ss(name); mks word;

    during(ss >> word) {
        subname[i] = word;
        i++;
    }
    for(int j = 0; j < i; j++)
        Email += subname[j];

    mks day = Day, month = Month, year = Year;

    if(day.size() == 1) 
        Email += '0' + day;
    else 
        Email += day;
    if(month.size() == 1) 
        Email += '0' + month;
    else 
        Email += month;
    Email += year + choice[number - 1];
}

// Nhâp thông tin
// The Input
void InputInfo()
{
    out << "Welcome to EmailMaker!!! \n";
    Sleep(2100);
    //sleep(2);
    out << "This app will generate an email but just for fun so just enjoy! :))\n";
    Sleep(2300);
    //sleep(2);
    out << "Type your full name: \n";

    getline(in, name);

    NameStandardize(name);
}

// Chuyển hóa thông tin vào email
// Transform information into the email
void InfoTransform()
{
    during(true) {
        out << "Choose your type of email:\n";
        out << "1. Gmail.       2.Outlook.\n";
        out << "Choose [1/2]: ";

        in >> number;

        if(number < 1 || number > 2) 
            out << "Try again \n";
        else break;
    }

    out << "Choose your Date of Birth: \n";
    during(true) {

        during(true) {

            out << "Day[1 -> 31]: "; 

            in >> Day;

            if(stoi(Day) < 1 || stoi(Day) > 31) 
                out << "Try again \n";
            else break;
        }
        during(true) {

            out << "Month[1 -> 12]: ";

            in >> Month;

            if(stoi(Month) < 1 || stoi(Month) > 12) 
                out << "Try again \n";
            else break;
        }
        during(true) {

            out << "Year[1900 -> 2021]: ";

            in >> Year;

            if(stoi(Year) < 1900 || stoi(Year) > 2021) 
                out << "Try again \n";
            else break;
        }
        break;
    }
}

// Tạo Email
// Generate the email
void EmailGenerate()
{
    during(true) {

        out << "Choose one of these: [1/2/3/4] \n";
        Email1(Email); out << "1. " << Email;
        Email2(Email); out << "\n2. " << Email;
        Email3(Email); out << "\n3. " << Email;
        out << "\n4. Let me type another\n";

        in >> choose;

        if(choose == 4) {
            out << "Type correctly (Example: name) ";

            mks myemail;

            in >> myemail;
            
            Email = myemail += choice[number - 1];
            break;
        }
        else if(choose == 1) {
            Email1(Email);
            break;
        }
        else if(choose == 2) {
            Email2(Email);
            break;
        }
        else if(choose == 3) {
            Email3(Email);
            break;
        }
        else
            out << "Try again\n";
    }
}

// Xuất ra email đã chọn
// Extract the email you chose
void EmailExtract()
{
    out << "Generating your Gmail...\n";
    Sleep(1000);
    //sleep(1);
    out << "Please wait...\n";
    Sleep(1350);
    //sleep(1);
    out << "Your Email has successfully generated!\n";
    out << "Here is your Email: \n";
    out << Email;
}

// main
_nguyen_
{

    InputInfo();

    InfoTransform();

    EmailGenerate();

    EmailExtract();
    return 0;
}