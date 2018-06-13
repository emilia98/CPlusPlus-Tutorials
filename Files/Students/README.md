Ready-to-use файлове:

- ```write.cpp```
- ```условие.txt```

- За момента е завършена само логиката за писането във файл.
- Четенето от файл е на 50%.

<p align="center"><b>write.cpp</b></p>
```
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main () {
    string firstName, lastName;
    int schoolYear;
    double averageGrade;

    // В следващите няколко реда въвеждаме данни от клавиатурата
    // First Name
    cout<<"First Name: ";
    getline(cin, firstName);

    // Last Name
    cout<<"Last Name: ";
    getline(cin, lastName);

    // Клас
    cout<<"Class: ";
    cin>>schoolYear;

    // Средна оценка
    cout<<"Average Grade: ";
    cin>>averageGrade;

   string data;

   // Output file stream (ПИСАНЕ НА ФАЙЛОВЕ)
   ofstream outfile;

   // Отваряме файла, в който ще пишем, като трябва да му зададем 
   // къде точно се намира, спрямо този файл:
   // В случая файлът се намира една папка по-навътре (Data) спрямо
   // write.cpp файла и се казва students_data.txt
   outfile.open("Data/students_data.txt", ios::app);

   /*
    Казваме на файла да запази в себе си стойностите, които въведохме 
    преди малко от клавиатурата
   */
   outfile << firstName << endl;
   outfile << lastName << endl;
   outfile << schoolYear << endl;
   outfile << averageGrade << endl;

   // Затваряме файла
   outfile.close();
   return 0;
}

```