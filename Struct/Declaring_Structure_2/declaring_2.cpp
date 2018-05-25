#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;

struct person {
    string firstName;
    string lastName;
    int age;
    bool isStudent;
};

person pesho;
person didka;

int main()
{
    // Here we check the type of object pesho
    if(typeid(pesho) == typeid(person)){
        cout<<"Type of pesho: "<<"person"<<endl;
    }

    // Here we check the type of object didka
    if(typeid(didka) == typeid(person)){
        cout<<"Type of didka: "<<"person"<<endl;
    }
    return 0;
}
