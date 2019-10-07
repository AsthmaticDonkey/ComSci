#include "database.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>


namespace NDXMYR001{
using namespace std;

vector<student> sz;


void addStudent(string name1, string surname1, string StudentNumber1, string ClassRecord1, vector<student> stu, int c)
{
    student st;
    st.name = name1;
    st.surname = surname1;
    st.StudentNumber = StudentNumber1;
    st.ClassRecord = ClassRecord1;
    sz.push_back(st);
    
}

void readDatabase(vector<student> st, int ch)
{
    
    
    string numb;
    ifstream file;
    file.open("database.txt");
    if(!file)
    {} 
    getline(file, numb, '!');
    getline(file, numb, '!');
    int i = stoi(numb);
    
    string a1, b1, c1, d1;
    
    for(int q = 0; q< i; q = q+1)
    {
        getline(file, a1, ',');
        getline(file, b1, ',');
        
        getline(file, c1, ',');
        getline(file, d1, ',');

        
        cout<<c1<<endl;
        
        student stud;
        stud.name = a1;
        stud.surname = b1;
        stud.StudentNumber = c1;
        stud.ClassRecord = d1;
        ch = ch+1;
        sz.push_back(stud);
    }
    
}
void save_database(vector<student> st, int ch)
{
    remove("database.txt");
    ofstream outputFile;
    outputFile.open("database.txt");
 //   int i= 0;
    outputFile<<"!"<<ch<<"!\n";
    for(vector<student>::iterator it = sz.begin(); it != sz.end(); ++it)
    {
        outputFile<<""<<(*it).name<<","<<(*it).surname<<","<<(*it).StudentNumber<<","<<(*it).ClassRecord<<",\n";
    }
    outputFile.close();
}

int display_data(string StudentN1)
{
    int i = 0;
    for(vector<student>::iterator it = sz.begin(); it != sz.end(); ++it)
    {
        if((*it).StudentNumber.compare(StudentN1) == 0)
        {
            cout << ""<<(*it).name<<" "<<(*it).surname<<" "<<(*it).StudentNumber<<" "<<(*it).ClassRecord<<endl;
            return 0;
        }
        i++;
    }
    cout <<"Student Number not found"<<endl;
    return 1;
    
}
void grade_student(string StudentN1)
{
    int i = 0;
    for (vector<student>::iterator it = sz.begin(); it != sz.end(); ++it)
    {
        if((*it).StudentNumber.compare(StudentN1) == 0)
        {
            cout << ""<<(*it).name<<" "<<(*it).surname<<" "<<(*it).StudentNumber<<" has a class record of "<<(*it).ClassRecord<<endl;
            return;
        }
        i++;
    }
    cout <<"Student Number not found"<<endl;
}


int checkData(string StudentN1)
{
    int i = 0;
    for(vector<student>::iterator it = sz.begin(); it != sz.end(); ++it)
    {
        if((*it).StudentNumber.compare(StudentN1) == 0)
        {
            return 0;
        }
        i++;
    }
    return 1;
    
}
}
