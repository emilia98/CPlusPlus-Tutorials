#include <iostream>
#include <string>
using namespace std;

struct person {
    string firstName;
    string lastName;
    int age;
    bool isStudent;
};

person pesho, tosho;

string isStudent(person p)
{
    return p.isStudent == 1 ? "true" : "false";
}

void printPerson(person p)
{
    cout<<"First name: "<<p.firstName<<endl;
    cout<<"Last name: "<<p.lastName<<endl;
    cout<<"Age: "<<p.age<<endl;
    cout<<"Student: "<<isStudent(p)<<endl;
}

int main()
{
    pesho.firstName = "Pesho";
    pesho.lastName = "Peshev";
    pesho.age = 25;
    pesho.isStudent = false;

    tosho.firstName = "Tosho";
    tosho.lastName = "Toshev";
    tosho.age = 18;
    tosho.isStudent = true;

    printPerson(pesho);
    cout<<"----------"<<endl;
    printPerson(tosho);

    return 0;
}
