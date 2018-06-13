#include<iostream>
#include<string>
#include<fstream>
using namespace std;
/*
ifstream fin("Data/input.txt",ios::in);
ofstream fout("Data/output.txt", ios::app);
*/
int main()
{
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

    cout<<"File Name: " <<fileName<<endl;

    string filePath = "Data/" + fileName + ".txt";
     cout<<"File Name: " <<filePath<<endl;

    ofstream myfile;
    myfile.open (filePath);
    myfile << "Writing this to a file.\n";
    myfile.close();
    //fout.open(filePath.c_str());
    // fout(filePath);
    //fout<<firstName<<endl;
    /*
   for(string line; getline(fin, line);) {
        cout<<line<<endl;
   }
    // Data/output.txt*/
    return 0;
}
