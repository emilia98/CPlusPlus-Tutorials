#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main () {
    string fileName;
    string firstName, lastName;
    int schoolYear;
    double averageGrade;
    cout<<"First Name: ";
    getline(cin, firstName);
    cout<<"Last Name: ";
    getline(cin, lastName);

    fileName = "st_" + firstName + "_" + lastName;
    cout<<"Class: ";
    cin>>schoolYear;
    cout<<"Average Grade: ";
    cin>>averageGrade;

   string data;

   // open a file in write mode.
   ofstream outfile;
   //outfile.open(fileName + ".txt", ios::app);

   outfile.open("s", ios::app);

   outfile << firstName << endl;
   outfile << lastName << endl;
   outfile << schoolYear << endl;
   outfile << averageGrade << endl;

  /*
   cout << "Writing to the file" << endl;
   cout << "Enter your name: ";
   //cin.getline(data, 100);
   getline(cin, data);

   // write inputted data into the file.
   outfile << data << endl;

   cout << "Enter your age: ";
   cin >> data;
   cin.ignore();
*/
   // again write inputted data into the file.
   //outfile << data << endl;

   // close the opened file.
   outfile.close();

   /*
   // open a file in read mode.
   ifstream infile;
   infile.open("afile.dat");

   cout << "Reading from the file" << endl;
   infile >> data;

   // write the data at the screen.
   cout << data << endl;

   // again read the data from the file and display it.
   infile >> data;
   cout << data << endl;

   // close the opened file.
   infile.close();*/

   return 0;
}
