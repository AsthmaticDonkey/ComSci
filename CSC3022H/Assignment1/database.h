/**
*.h file:
*/
#ifndef DATABASE_H
#define DATABASE_H
//any includes here
#include <iostream>
#include <vector>
using namespace std;

namespace NDXMYR001
{
    struct student
    {
        string name;
        string surname;
        string StudentNumber;
        string ClassRecord;
    };
    void addStudent(string name1, string surname1, string StudentNumber1, string ClassRecord1, vector<student> s, int c);
    void readDatabase(vector<student> s, int c);
    void save_database(vector<student> s, int c);
    int display_data(std::string StudentN1);
    void grade_student(std::string StudentN1);
    int checkData(string StudentN1);
}
#endif
