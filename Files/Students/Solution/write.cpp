#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main () {
    string firstName, lastName;
    int schoolYear;
    double averageGrade;

    cout<<"First Name: ";
    getline(cin, firstName);

    cout<<"Last Name: ";
    getline(cin, lastName);

    cout<<"Class: ";
    cin>>schoolYear;

    cout<<"Average Grade: ";
    cin>>averageGrade;

   string data;

   //
   ofstream outfile;

   outfile.open("Data/students_data.txt", ios::app);

   //outfile << '\n'<<endl;
   outfile << endl;
   outfile << firstName << endl;
   outfile << lastName << endl;
   outfile << schoolYear << endl;
   outfile << averageGrade << endl;
   //
   // close the opened file.
   outfile.close();
   return 0;
}
