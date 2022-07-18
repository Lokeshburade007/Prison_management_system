//Prison management system

#include <iostream>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <fstream>
#include <ctime>
using namespace std;

class date   //friend function
{
    public:
    friend void Date(date l){   //Defination Of Friend Function
    string a;
    time_t T = time(NULL);
    struct tm tm = *localtime(&T);
    cout << "\n\n\n";
    cout << "\t\t\t\t\t   Today's Date:\n";
    cout << "\t\t\t\t\t   Date: " << tm.tm_mday << "/" 
    << tm.tm_mon + 1 << "/" << tm.tm_year + 1900 << "\n";
    cout << "\t\t\t\t\t   Enter Any Value to Begin....\n";
    cout << "\t\t\t\t\t    ";
     cin>>a;
    }
};


class ttime
{
    public:
    void Time() //Defination of Function Overriding
{
    time_t curr_time;
    curr_time = time(NULL);

    tm *tm_local = localtime(&curr_time);
    cout << "Time : " << tm_local->tm_hour << ":" << tm_local->tm_min << ":" << tm_local->tm_sec << endl;
}

};


class Prison  //Main Class
{
private:
    // Detaiils of Prisoner
    string First_Name[20] = {" ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "};
    string Second_Name[20];
    string Gender[20];
    int CellNo[20] = {1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010, 1011, 1012, 1013, 1014, 1015, 1016, 1017, 1018, 1019, 1020};
    int Age[20];
    double Height[20];
    string Eyecolor[20];
    string Crime[20];
    int Punishmentmonths[20];
    int o = 0;


public:
    void SetData();      // Set data of the prisoners
    void Details();      // Getting details of the prisoners
    void Prisonermenu();   //  Menu function
    void Attendance();   // Storing attendace of the prisoners
    void Release();      // Release the prisoners
    // Declaration of Function Overriding 
    void Time();
    void SearchPrison(); // Search Prison
    void Exit();         // Exit function
    Prison(){  //Constructor
        Time();
    }
    ~Prison(){    //Destructor 
        system("CLS");
        cout<<"\n\n\n\n\n\t\t\t\t\t\t\t** Thank You **\n\n\n\n\n";
    }
};

void Prison ::SetData()
{
    system("cls");
    Time();
    int a, s;
    cout << "\t\t\t\t    -----------------------------------------------------\n";
    cout << "\t\t\t\t    |                                                   |\n";
    cout << "\t\t\t\t    |         Enter basic information of prisoner       |\n";
    cout << "\t\t\t\t    |                                                   |\n";
    cout << "\t\t\t\t    -----------------------------------------------------\n";
    cout << "\n\n";
    cout << "\t\t\t\t\t";
    cout << "Enter first name : ";
    cin >> First_Name[o];
    cout << "\t\t\t\t\t";
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "Enter second name : ";
    cin >> Second_Name[o];
    cout << "\t\t\t\t\t";
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "Enter gender : ";
    cin >> Gender[o];
    cout << "\t\t\t\t\t";
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "Enter age : ";
    try{                       //exception handling
        cin >> Age[o];
    }
    catch(...){
        cout<<"Enter an integer for age"<<endl;
    }
    cout << "\t\t\t\t\t";
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "Enter height : ";
    try{                       //exception handling
        cin >> Height[o];
    }
    catch(...){
        cout<<"Enter a number for height"<<endl;
    }
    cout << "\t\t\t\t\t";
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "Enter eyecolor : ";
    cin >> Eyecolor[o];
    cout << "\t\t\t\t\t";
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "Enter crime : ";
    cin >> Crime[o];
    cout << "\t\t\t\t\t";
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "Enter punishment span in months : ";
    cin >> Punishmentmonths[o];
    cout << "\t\t\t\t\t";
    cout << "\n\n\n";
    cout << "\t\t\t\t\t";
    cout << "Your Cell No is " << CellNo[o];
    cout << "\n\t\t\t\t\t";
    cout << "\n";
    cout << "\t\t\t\t\t";
    o = o + 1;
    cout << "Press 1 to return : ";
    scanf("%d", &s);
    if (s == 1)
    {
        Prison ::Prisonermenu();
    }
}

void Prison ::Details()
{
    system("cls");
    Time();
    int t;
    cout << "\t\t\t\t    -----------------------------------------------------\n";
    cout << "\t\t\t\t    |                                                   |\n";
    cout << "\t\t\t\t    |                Prisoner list                      |\n";
    cout << "\t\t\t\t    |                                                   |\n";
    cout << "\t\t\t\t    -----------------------------------------------------\n";
    int s, c = 0, p = 0;

    cout << "\n\t\t\t\t\t";

    cout << "\n===========================================================================================================\n";
    cout << "SR.\tNAME\t\t\tCell Block\tAge\tGender\tHeight\tEye Colour\tCrime\tPunishment\n";
    cout << "===========================================================================================================\n";

    for (int x = 0; x <= 19; x++)
    {
        if (First_Name[x] != " ")
        {
            p++;
            cout << p << "\t" << First_Name[x] << "" << Second_Name[x] << "\t\t" << CellNo[x] << "\t\t" << Age[x] << "\t" << Gender[x] << "\t" << Height[x] << "\t" << Eyecolor[x] << "\t\t" << Crime[x] << "\t\t" << Punishmentmonths[x] << endl;
            cout << "\n"
                 << endl;
            c++;
        }
    }
    if (c == 0)
    {
        cout << "\n\t\t\t\t\t";
        cout << "No prisoner Present";
        cout << "\n";
        cout << "\t\t\t\t\t";
    }
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "Press 1 to return : ";
    scanf("%d", &s);
    if (s == 1)
    {
        Prison::Prisonermenu();
    }
}

template<class T>  // template 
T OneDayPassed(T a){
    a--;
    return a;
}

template<class C>
C CellIndex(C b){
    b=b-1001;
    return b;
}

void Prison ::Attendance()
{
    int s, l, c = 0;
    char ch;
    do
    {
        system("cls");
        Time();
        system("cls");
        int t;
        cout << "\t\t\t\t    -----------------------------------------------------\n";
        cout << "\t\t\t\t    |                                                   |\n";
        cout << "\t\t\t\t    |           Prisoner attendance maintainer          |\n";
        cout << "\t\t\t\t    |                                                   |\n";
        cout << "\t\t\t\t    -----------------------------------------------------\n";
        cout << "\n\t\t\t\t\t";
        cout << "\n===========================================================================================================\n";
        cout << "NAME\t\t\tCell Block\tAge\tGender\tHeight\tEye Colour\tCrime\tPunishment\n";
        cout << "===========================================================================================================\n";
        for (int x = 0; x <= 19; x++)
        {
            if (First_Name[x] != " ")
            {
                cout << First_Name[x] << "" << Second_Name[x] << "\t\t" << CellNo[x] << "\t\t" << Age[x] << "\t" << Gender[x] << "\t" << Height[x] << "\t" << Eyecolor[x] << "\t\t" << Crime[x] << "\t\t" << Punishmentmonths[x] << endl;
                cout << "\n"
                     << endl;
                c++;
            }
        }
        if (c != 0)
        {
            cout << "\n\t\t\t\t\t";
            cout << "Enter the cell  block of the prisoner :";
            scanf("%d", &l);
            l = CellIndex<int>(l);   //template call
            cout << "\n\t\t\t\t\t";
            cout << "Name : ";
            cout << First_Name[l] << " " << Second_Name[l];

            Punishmentmonths[l]=OneDayPassed<int>(Punishmentmonths[l]);  //template call

            cout << "\n\t\t\t\t\t";
            cout << "Punishment for :" << Punishmentmonths[l] << " months";
            if (Punishmentmonths[l] <= 0)
            {
                cout << "\n\t\t\t\t\t";
                cout << "Prisoner is ready for release";
            }
            cout << "\n\n";
            cout << "\n\t\t\t\t\t";
            cout << "Press y to choose another prisoner and press n to exit :";
            cin >> ch;
        }
        else
        {
            int a;
            cout << "\t\t\t\t\t";
            cout << "\n";
            cout << "\t\t\t\t\t";
            cout << "\t\t\t\t                                                    \n";
            cout << "\t\t\t\t    ------------------------------------------------\n";
            cout << "\t\t\t\t    |             No prisoners present             |\n";
            cout << "\t\t\t\t    ------------------------------------------------\n";
        }

    } while (ch == 'y');
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "Press 1 to return : ";
    scanf("%d", &s);
    if (s == 1)
    {
        Prison::Prisonermenu();
    }
}

void Prison ::Release()
{
    int s, l, c = 0, r;
    char ch;
    do
    {
        system("cls");
        Time();
        int t;
        cout << "\t\t\t\t    -----------------------------------------------------\n";
        cout << "\t\t\t\t    |                                                   |\n";
        cout << "\t\t\t\t    |                Release prisoner                   |\n";
        cout << "\t\t\t\t    |                                                   |\n";
        cout << "\t\t\t\t    -----------------------------------------------------\n";

        cout << "\n\t\t\t\t\t";
        cout << "\n===========================================================================================================\n";
        cout << "NAME\t\t\tCell Block\tAge\tGender\tHeight\tEye Colour\tCrime\tPunishment\n";
        cout << "===========================================================================================================\n";

        for (int x = 0; x <= 19; x++)
        {
            if (First_Name[x] != " ")
            {
                cout << First_Name[x] << "" << Second_Name[x] << "\t\t" << CellNo[x] << "\t\t" << Age[x] << "\t" << Gender[x] << "\t" << Height[x] << "\t" << Eyecolor[x] << "\t\t" << Crime[x] << "\t\t" << Punishmentmonths[x] << endl;
                cout << "\n"
                     << endl;
                c++;
            }
        }
        if (c != 0)
        {
            cout << "\n\t\t\t\t\t";
            cout << "Enter the cell block of the prisoner :";
            try{
                scanf("%d", &l);            //exception handling
            }
            catch(...){
                cout<<"Enter integer"<<endl;
            }
            l = l - 1001;
            cout << "\n\t\t\t\t\t";
            cout << "Name : ";
            cout << First_Name[l] << " " << Second_Name[l];
            cout << "\n\t\t\t\t\t";
            if (Punishmentmonths[l] <= 0)
            {
                cout << "\n\t\t\t\t\t";
                cout << "Prisoner is ready for release";
                cout << "\n\t\t\t\t\t";
                cout << "Press 1 to release the prisoner :";
                cin >> r;
                if (r == 1)
                {
                    First_Name[l] = " ";
                    Second_Name[l] = " ";
                    Gender[l] = " ";
                    Age[l] = 0;
                    Height[l] = 0;
                    Eyecolor[l] = " ";
                    Punishmentmonths[l] = 0;
                    cout << "\n\t\t\t\t\tProcessing";

                    for (int process = 0; process < 7; process++)
                    {
                        cout << ".";
                    }
                    cout << "\n\t\t\t\t\t";
                    cout << "Prisoner released successfully";
                }
            }
            else
            {
                cout << "\n\t\t\t\t\t";
                cout << "Prisoner is not ready for release";
            }

            cout << "\n\n";
            cout << "\n\t\t\t\t\t";
            cout << "Press y to choose another prisoner and press n to exit :";
            cin >> ch;
        }
        else
        {
            int a;
            cout << "\t\t\t\t\t";
            cout << "\n";
            cout << "\t\t\t\t\t";
            cout << "\t\t\t\t                                                    \n";
            cout << "\t\t\t\t    ------------------------------------------------\n";
            cout << "\t\t\t\t    |             No prisoners present             |\n";
            cout << "\t\t\t\t    ------------------------------------------------\n";
            break;
        }
    } while (ch == 'y');
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "Press 1 to return : ";
    scanf("%d", &s);
    if (s == 1)
    {
        Prison::Prisonermenu();
    }
}

void Prison ::SearchPrison()
{
    int *info=new int;  //file handling or memory allocation
    int *CN=new int;
    int *i=new int;
    int *a=new int;
    int *s=new int;
    int *l=new int;

    // int info;
    // int CN, i, a, s, l;
    // int c = 0, p = 0;

    system("cls");
    cout << "\t\t\t\t    ----------------------------------------\n";
    cout << "\t\t\t\t    |             Search Menu              |\n";
    cout << "\t\t\t\t    ----------------------------------------\n";
    cout << "\n\n";
    cout << "\t\t\t\t";
    cout << "Enter the prisoner cell id to be searched : ";
    cin >> *CN;
    cout << "\n\t\t\t\t";
    cout << "\n===========================================================================================================\n";
    cout << "NAME\t\t\tCell Block\tAge\tGender\tHeight\tEye Colour\tCrime\tPunishment\n";
    cout << "===========================================================================================================\n";
    *l = *CN - 1001;
    *info = CellNo[*l];
    if (*CN == *info)
    {
        if (First_Name[*l] != " ")
        {
            cout << First_Name[*l] << "" << Second_Name[*l] << "\t\t" << CellNo[*l] << "\t\t" << Age[*l] << "\t" << Gender[*l] << "\t" << Height[*l] << "\t" << Eyecolor[*l] << "\t\t" << Crime[*l] << "\t\t" << Punishmentmonths[*l] << endl;
            cout << "\n"
                 << endl;
        }
        else
        {
            cout << "\n";
            cout << "\t\t\t\t";
            cout << "\n";
            cout << "\t\t\t\t";
            cout << "cell block empty" << endl;
        }
    }
    else
    {
        cout << "\n";
        cout << "\t\t\t\t";
        cout << "\n";
        cout << "\t\t\t\t";
        cout << "invalid cell id" << endl;
    }
    cout << "\n";
    cout << "\t\t\t\t";
    cout << "\n";
    cout << "\t\t\t\t";
    cout << "Press 1 to return : ";
    scanf("%d", s);
    if (*s == 1)
    {
        Prison::Prisonermenu();
    }
    delete info;
    delete CN;
    delete i;
    delete a;
    delete s;
    delete l;
}

void Prison ::Prisonermenu()
{
    int a, c;
    int v;
    do
    {
        v = 0;
        system("cls");
        cout << "\n\n\t\t\t\t";
        Time();
        cout << "\n\n\n";
        cout << "\t\t\t\t---------------------------------------------------------------------------\n";
        cout << "\t\t\t\t|                                                                         |\n";
        cout << "\t\t\t\t|                     1)   New prisoner entry                             |\n";
        cout << "\t\t\t\t|                                                                         |\n";
        cout << "\t\t\t\t|                     2)   Prisoner details                               |\n";
        cout << "\t\t\t\t|                                                                         |\n";
        cout << "\t\t\t\t|                     3)   Attendace prisoner                             |\n";
        cout << "\t\t\t\t|                                                                         |\n";
        cout << "\t\t\t\t|                     4)   Release prisoner                               |\n";
        cout << "\t\t\t\t|                                                                         |\n";
        cout << "\t\t\t\t|                     5)   Search prisoner                                |\n";
        cout << "\t\t\t\t|                                                                         |\n";
        cout << "\t\t\t\t|                     6)   Exit                                           |\n";
        cout << "\t\t\t\t|                                                                         |\n";
        cout << "\t\t\t\t|                                                                         |\n";
        cout << "\t\t\t\t---------------------------------------------------------------------------\n";
        cout << "\n";
        cout << "\t\t\t\t\t\t\t";
        cout << "\n";
        cout << "\t\t\t\t\t\t\t";
        cout << "Enter your choice : ";
        cin >> c;
        switch (c)
        {
        case 1:
            Prison ::SetData();
            break;
        case 2:
            Prison ::Details();
            break;
        case 3:
            Prison ::Attendance();
            break;
        case 4:
            Prison ::Release();
            break;
        case 5:
            Prison ::SearchPrison();
            break;
        case 6:
            break;
        default:
            cout << "\n\t\t\t\tInvalid choice\n";
            cout << "\t\t\t\tPress 1 to return : ";
            cin >> v;
        }
    } while (v == 1);
}
void Prison::Time()  //Defination of Function Overriding 
{
    time_t curr_time;
    curr_time = time(NULL);

    tm *tm_local = localtime(&curr_time);
    if(tm_local->tm_hour>=12)
    {
    cout << "Time : " << abs(tm_local->tm_hour -12) 
    << ":" << tm_local->tm_min << ":" << tm_local->tm_sec << endl;
    }
    else{
    cout << "Time : " << abs(tm_local->tm_hour ) << ":" 
    << tm_local->tm_min << ":" << tm_local->tm_sec << endl;
    }
    
}
int main()
{
    date l;
    Date(l);
    Prison a;
    a.Prisonermenu();
    return 0;
}