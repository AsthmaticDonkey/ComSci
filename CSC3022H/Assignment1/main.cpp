#include "database.h"
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;
using namespace NDXMYR001;


int main()
{
    vector<student> s;
    int count = 0;
    std::string n;
    std::string sur;
    int choice;
    std::string snum;
    std::string grade;
    int loop;
    int v;
        
    loop = 0;
    
    while(loop != -1)
    {
        cout << "Enter The Corresponding Number For Your Selection:" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Read Database" << endl;
        cout << "3. Save Database" << endl;
        cout << "4. Display Student" << endl;
        cout << "5. Display Grade" << endl;
        cout << "6. Quit" << endl;
        cout << "7. Clear Terminal" << endl;
        
        cin >> choice;
        switch(choice)
        {
            case 1:
                cout << "Enter the Student's name" << endl;
                cin >> n;
                cout << "Enter the Student's surname" << endl;
                cin >> sur;
                cout << "Enter the Student Number" << endl;
                cin >> snum;
                cout << "Enter the Student's Class Record" << endl;
                cin >> grade;
                if(checkData(snum) == 0)
                {
                    cout<<"Student already exists"<<endl;
                    break;
                }
                NDXMYR001::addStudent(n, sur, snum, grade, s, count);
                //loopi = s.begin();
                
                count++;
                break;
                
            case 2:
                NDXMYR001::readDatabase(s, count);
                break;
                
            case 3:
                NDXMYR001::save_database(s, count);
                break;
                
            case 4:
                cout << "Enter the Student's number" << endl;
                cin >> snum;
                v = NDXMYR001::display_data(snum);
                break;
                
            case 5:
                cout << "Enter the Student's number" << endl;
                cin >> snum;
                NDXMYR001::grade_student(snum);
                break;
                
            case 6:
                loop = -1;
                break;
            case 7:
                system("clear");
                break;
                
        }
    }
    return 0;
}
