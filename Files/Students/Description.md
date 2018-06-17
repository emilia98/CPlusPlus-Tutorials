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

<p align="center"><b>analyze.cpp</b></p>
```
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <locale>
using namespace std;

/* Създаваме структурата - определяме какви полета ще има и от какъв тип ще бъдат те */
struct Student {
    string firstName;
    string lastName;
    int schoolYear;
    double averageGrade;
};

/* Методът, който се извиква, когато сме избрали опция №1 */
void AnalyzeBySchoolYear(Student students[], int studentsCount)
{
    int schoolYear;
    cout<<"Enter a SchoolYear: ";
    cin>>schoolYear;
     /* Пазим цялата информация, която ще вземем от всеки ученик в тази променлива */
    string analyzeToWrite;

    for(int index = 0; index < studentsCount; index++)
    {
       Student student = students[index];

       if(student.schoolYear == schoolYear) {
          analyzeToWrite += student.firstName + " ";
          analyzeToWrite += student.lastName + " ";
          analyzeToWrite += to_string(student.schoolYear) + " ";
          analyzeToWrite += to_string(student.averageGrade).substr(0, 4) + "\r\n";
        }
    }

    /* Печатаме на екрана цялата информация, която е като резултат от горните ни действия */
    cout<<analyzeToWrite;

    /* Пишем във файла същата тази информация (още за писане във файл - виж по-горе описаните на write.cpp) */
    ofstream outfile;
    outfile.open("Data/analyze_bySchoolYear.txt", ios::out);
    outfile << "School Year = " <<schoolYear << endl;
    outfile << analyzeToWrite << endl;
    outfile.close();
}

/* Методът, който се извиква, когато сме избрали опция №2 */
void AnalyzeByGrade(Student students[], int studentsCount)
{
    double grade;
    cout<<"Enter a grade: ";
    cin>>grade;
    /* Пазим цялата информация, която ще вземем от всеки ученик в тази променлива */
    string analyzeToWrite;

    for(int index = 0; index < studentsCount; index++)
    {
       Student student = students[index];

       if(student.averageGrade >= grade) {
          analyzeToWrite += student.firstName + " ";
          analyzeToWrite += student.lastName + " ";
          analyzeToWrite += to_string(student.schoolYear) + " ";
          analyzeToWrite += to_string(student.averageGrade).substr(0, 4) + "\r\n";
        }
    }

    /* Печатаме на екрана цялата информация, която е като резултат от горните ни действия */
    cout<<analyzeToWrite;

    /* Пишем във файла същата тази информация (още за писане във файл - виж по-горе описаните на write.cpp) */
    ofstream outfile;
    outfile.open("Data/analyze_byGrade.txt", ios::out);
    outfile << "Students with grade >= " <<grade<< endl;
    outfile << analyzeToWrite << endl;
    outfile.close();
}

/* Методът, който се извиква, когато сме избрали опция №3 */
void GetAllStudents(Student students[], int studentsCount)
{
    /* Пазим цялата информация, която ще вземем от всеки ученик в тази променлива */
    string analyzeToWrite;
    for(int index = 0; index < studentsCount; index++)
    {
       Student student = students[index];

       string fullName = student.firstName + " " + student.lastName;
       locale loc;
       string hello;

       string result = "";
       for (string::size_type i = 0; i < fullName.length(); ++i)
       {
          result += toupper(fullName[i],loc);
       }

      analyzeToWrite += result + "\n\r";
    }

    /* Печатаме на екрана цялата информация, която е като резултат от горните ни действия */
    cout<<analyzeToWrite;

    /* Пишем във файла същата тази информация (още за писане във файл - виж по-горе описаните на write.cpp) */
    ofstream outfile;
    outfile.open("Data/analyze_allStudents.txt", ios::out);
    outfile << "All Students With Name: "<< endl;
    outfile << analyzeToWrite << endl;
    outfile.close();
}

/* Методът, който ще ни позволи да изберем опция за  анализиране на прочетената информация */
void Analyze(Student students[], int studentsCount)
{
    // Списъкът с опциите, между които можем да избираме 
    // (подробно описание в условието)
    cout<<"Options list:"<<endl;
    cout<<"1) List Students By Given Class..."<<endl;
    cout<<"2) List Students With Grade Less Than Given Grade..."<<endl;
    cout<<"3) Make all students's names uppercase..."<<endl;
    int option;

    /* Избираме се опция. 
       На база на избрана опция, се извиква определена функция,
       която анализира по определен от нас критерий
    */
    cout<<"Choose an option: ";
    cin>>option;

    while(true)
    {
         if(option == 1) {
            AnalyzeBySchoolYear(students, studentsCount);
            break;
         }

         if(option == 2) {
            AnalyzeByGrade(students, studentsCount);
            break;
         }

         if(option == 3) {
            GetAllStudents(students, studentsCount);
            break;
         }
          
         /* Ако въведем грешна команда (не е цяло число между 1 до 3),
         програмата ще иска от нас да въвеждаме отново и отново
         числа, докато не въведем правилна команда */
         cout<<"Wrong command..."<<endl;
         cout<<"Choose an option: ";
         cin>>option;
    }
}

int main()
{
    /*
        Декларираме двумерен масив (матрица) от string-ове, в който ще пазим
        не повече от 1000 ученика, като всеки ученик ще има 4 елемента (всички те 
        ще са string-ове и ще бъдат тези стойности, които сме прочели от файла).
    */
    string studentsInfo[1000][4];
    /*
      Брояч, който ще следи за броят прочетени вече ученици от файла.
    */
    int studentsCounter = 0;
    /*
      Това е брояч, който ще следи за редовете, които сме прочели, но
      и ще го използваме при запазването на данните за всеки ученик
    */
    int indexData;
    /*
      Декларираме масив, който ще пази всички прочетени ученици, които
      сме ги запазили като структура Student
    */
    Student students[1000];

    /* Следващите няколко реда са за файла, който искаме да четем */
    ifstream file;
    file.open("Data/students_data.txt");
    string buffer;
    string line;

    /* Променлива, която ще отговаря за броя редове във файла. */
    int lineCounter = 1;
    while(file){
        getline(file, line);

        /*
           Във файла, който четем, всеки 5-ти ред е празен, затова на нас не ни трябва.
           Правим проверка дали номерът на реда се дели на 5 без остатък и ако е така, го пропускаме (виж файл read.cpp)       
        */
        if(lineCounter % 5 == 0) {
            lineCounter++;
            continue;
        }
        
        /*
           Създаваме нов масив, който ще пази данните на нов ученик
        */
        if(lineCounter % 5 == 1) {
            indexData = 0;
        }

        // Добавяме към данните на текущия ученик още информация.
        studentsInfo[studentsCounter][indexData] = line;

        /*
            Цялата информация за един ученик се намира на 4 реда.
            Моментът, в който вече сме прочели всички данни за един ученик, увеличаваме броя на прочетените ученици.
        */
        if(lineCounter % 5 == 4) {
            studentsCounter++;
        }
        // Увеличаваме броя прочетени 
        indexData++;
        lineCounter++;
    }

    /* За всеки един ученик, чиито данни сме запазили, създаваме структура, чиято цел е да структурира данните ни, така че като искаме да вземем първото име на дадения ученик, ние го достъпваме със student.firstName
    */
    for(int studentIndex = 0; studentIndex < studentsCounter; studentIndex++) {
        // Създаваме нов ученик.
        Student newStudent;
        // Започваме да попълваме данните на ученика
        newStudent.firstName = studentsInfo[studentIndex][0];
        newStudent.lastName = studentsInfo[studentIndex][1];

        // Тук имаме данни, които са от тип string, но искаме да ги пазим като числа, затова трябва да ги превърнем в такива 
        int schoolYear = atoi(studentsInfo[studentIndex][2].c_str());
        double averageGrade = atof(studentsInfo[studentIndex][3].c_str());
        newStudent.schoolYear = schoolYear;
        newStudent.averageGrade = averageGrade;

        /* Запазваме новосъздадения ученик в масивът (students), който пази всички ученици, вече преминали през */
        students[studentIndex] = newStudent;
    }

    /* След като сме прочели всички данни за всеки ученик, ние вече можем да преминем към анализирането на данните 
      Затова извикваме функцията, която ни позволява да си изберем от една измежду 3 опции, всяка от които прави различен анализ */
    Analyze(students, studentsCounter);
    return 0;
}
```


Няколко непознати функции, използвани в програмата
- Метод за превръщане на string към int 
```
atoi(<някакво цяло число>.c_str());
```
- Метод за превръщане на string към double 
```
atof(<някакво дробно число>.c_str());
```