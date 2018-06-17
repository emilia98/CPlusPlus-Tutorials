#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <locale>
using namespace std;

struct Student {
    string firstName;
    string lastName;
    int schoolYear;
    double averageGrade;
};

void AnalyzeBySchoolYear(Student students[], int studentsCount)
{
    int schoolYear;
    cout<<"Enter a SchoolYear: ";
    cin>>schoolYear;
    string analyzeToWrite;

    for(int index = 0; index < studentsCount; index++)
    {
       Student student = students[index];

       if(student.schoolYear == schoolYear) {
          analyzeToWrite += student.firstName + " ";
          analyzeToWrite += student.lastName + " ";
          analyzeToWrite += to_string(student.schoolYear) + " ";
          analyzeToWrite += to_string(student.averageGrade).substr(0, 4) + "\r\n";
        }
    }

    cout<<analyzeToWrite;

    ofstream outfile;
    outfile.open("Data/analyze_bySchoolYear.txt", ios::out);
    outfile << "School Year = " <<schoolYear << endl;
    outfile << analyzeToWrite << endl;
    outfile.close();
}

void AnalyzeByGrade(Student students[], int studentsCount)
{
    double grade;
    cout<<"Enter a grade: ";
    cin>>grade;
    string analyzeToWrite;

    for(int index = 0; index < studentsCount; index++)
    {
       Student student = students[index];

       if(student.averageGrade >= grade) {
          analyzeToWrite += student.firstName + " ";
          analyzeToWrite += student.lastName + " ";
          analyzeToWrite += to_string(student.schoolYear) + " ";
          analyzeToWrite += to_string(student.averageGrade).substr(0, 4) + "\r\n";
        }
    }

    cout<<analyzeToWrite;

    ofstream outfile;
    outfile.open("Data/analyze_byGrade.txt", ios::out);
    outfile << "Students with grade >= " <<grade<< endl;
    outfile << analyzeToWrite << endl;
    outfile.close();
}

void GetAllStudents(Student students[], int studentsCount)
{
    string analyzeToWrite;
    for(int index = 0; index < studentsCount; index++)
    {
       Student student = students[index];

       string fullName = student.firstName + " " + student.lastName;
       locale loc;
       string hello;

       string result = "";
       for (string::size_type i = 0; i < fullName.length(); ++i)
       {
          result += toupper(fullName[i],loc);
       }

      analyzeToWrite += result + "\n\r";
    }

    cout<<analyzeToWrite;

    ofstream outfile;
    outfile.open("Data/analyze_allStudents.txt", ios::out);
    outfile << "All Students With Name: "<< endl;
    outfile << analyzeToWrite << endl;
    outfile.close();
}

void Analyze(Student students[], int studentsCount)
{
    cout<<"Options list:"<<endl;
    cout<<"1) List Students By Given Class..."<<endl;
    cout<<"2) List Students With Grade Less Than Given Grade..."<<endl;
    cout<<"3) Make all students's names uppercase..."<<endl;
    int option;

    cout<<"Choose an option: ";
    cin>>option;

    while(true)
    {
         if(option == 1) {
            AnalyzeBySchoolYear(students, studentsCount);
            break;
         }

         if(option == 2) {
            AnalyzeByGrade(students, studentsCount);
            break;
         }

         if(option == 3) {
            GetAllStudents(students, studentsCount);
            break;
         }


         cout<<"Wrong command..."<<endl;
         cout<<"Choose an option: ";
         cin>>option;
    }
}

int main()
{
    string studentsInfo[1000][4];
    int studentsCounter = 0;
    int indexData;
    Student students[1000];

    ifstream file;
    file.open("Data/students_data.txt");
    string buffer;
    string line;

    int lineCounter = 1;
    while(file){
        getline(file, line);

        if(lineCounter % 5 == 0) {
            lineCounter++;
            continue;
        }

        if(lineCounter % 5 == 1) {
            indexData = 0;
        }

        studentsInfo[studentsCounter][indexData] = line;

        if(lineCounter % 5 == 4) {
            studentsCounter++;
        }
        indexData++;
        lineCounter++;
    }

    for(int studentIndex = 0; studentIndex < studentsCounter; studentIndex++) {
        Student newStudent;
        newStudent.firstName = studentsInfo[studentIndex][0];
        newStudent.lastName = studentsInfo[studentIndex][1];

        int schoolYear = atoi(studentsInfo[studentIndex][2].c_str());
        double averageGrade = atof(studentsInfo[studentIndex][3].c_str());
        newStudent.schoolYear = schoolYear;
        newStudent.averageGrade = averageGrade;

        students[studentIndex] = newStudent;
    }

    Analyze(students, studentsCounter);
    return 0;
}
