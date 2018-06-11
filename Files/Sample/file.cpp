#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int n;
ifstream fin("text.txt",ios::in);
ofstream fout("text.txt", ios::app);

int main()
{
    int x,y;
    string z;
    /*
     Here we read the file one by line (not the whole file)
     and store the value of the given line into a variable
    */
    // Тук започваме да четем файла ред по ред (не целия файл)
    // и пазим стойността на текущия ред от файла в променлива,
    // чиято стойност можем да отпечатаме на екрана
    fin>>x>>y>>z;
    cout<<x<<endl;
    cout<<y<<endl;
    cout<<z<<endl;
    // Вземаме числата, които сме прочели от първите два реда на файла
    // и ги сумираме.
    int sum = x + y;
    // Казваме на курсора да слезе на долния ред, защото иначе
    // ще започне да пище на същия
    fout<<endl;
    // Сумата им добавяме като последен ред на файла.
    fout<<sum<<endl;
    return 0;
}
