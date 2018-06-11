#include <iostream>
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
    cout<<pesho.firstName<<endl; // returns default value -> "" (empty string)
    cout<<pesho.lastName<<endl; // returns default value -> "" (empty string)
    cout<<pesho.age<<endl; // returns default value -> 0
    cout<<pesho.isStudent<<endl; // return default value -> 0 (false)
    return 0;
}
