#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string studentsInfo[1000][4];
    int studentsCounter = 0;
    int indexData;

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

    for(int outerIndex = 0; outerIndex < studentsCounter; outerIndex++) {
        for(int innerIndex = 0; innerIndex < 4; innerIndex++) {
            cout<<studentsInfo[outerIndex][innerIndex]<<endl;
        }
    }
    return 0;
}
