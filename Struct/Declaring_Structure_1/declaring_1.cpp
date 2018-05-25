#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;

struct person {
    string firstName;
    string lastName;
    int age;
    bool isStudent;
} pesho;

int main()
{
    // Here we check the type of object pesho
    if(typeid(pesho) == typeid(person)){
        cout<<"Type of pesho: "<<"person"<<endl;
    }
    return 0;
}
