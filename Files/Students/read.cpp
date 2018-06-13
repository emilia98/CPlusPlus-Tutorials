#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main () {
    ifstream file;
    file.open("Data/students_data.txt");
    string buffer;
    string line;

    int lineCounter = 1;
    while(file){
        getline(file, line);
        cout<<lineCounter<<" "<<line<<endl;
        lineCounter++;
    }
   return 0;
}
