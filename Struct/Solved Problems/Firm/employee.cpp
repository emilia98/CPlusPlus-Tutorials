#include <iostream>
#include <string>
using namespace std;

/* Define the structure */
struct employee {
	string name;
	int egn;
	string duty;
	double payment;
};

int main()
{
    // N = Number of employees we will enter
    int n;
    cin>>n;

    string ime;
    int egn;
    string poziciq;
    double zaplata;

    // underpaid -> Нископлатени служители
    /* employee underpaid[n]; -> масив, който ще пази нископлатените служители
    Може да има от 0 до n елемента.
    */
    employee underpaids[n];
    int index = 0;

    /* Започваме да въвеждаме информацията за всеки
       служител (това действие ще се изпълни n пъти -
       толкова пъти ще се завърти и цикъла)
    */
    for(int i = 1; i <= n; i++) {
        cout<<"Ime = "<<endl;
        cin>>ime;
        cout<<"Egn = ";
        cin>>egn;
        cout<<"Poziciq = ";
        cin>>poziciq;
        cout<<"Zaplata = ";
        cin>>zaplata;

        /* Създаваме нов работник (все едно му даваме
           да попълни бланка с личните си данни), който
           ще съдържа в себе си въведените преди малко данни
        */
        employee rabotnik;
        rabotnik.name = ime;
        rabotnik.egn = egn;
        rabotnik.duty = poziciq;
        rabotnik.payment = zaplata;

        /* Ако заплатата му е под 700 лева, ние го слагаме
        при нископлатените работници */
        if(rabotnik.payment < 700) {

        /*Добавяме го в масива от нископлатени на първата
          свободна позиция, която е index*/
            underpaids[index] = rabotnik;
            index++;
        }
    }
     // Вземаме броя на нископлатените работници, които
     // сме добавили в масива
    int broiNiskoplateni = index;

    /*Сега ще вземем един по един нископлатените
      работници и ще отпечатаме името му*/
    for(int i = 0; i < broiNiskoplateni; i++) {
        /*
        Сега ще извадим един от нископлатените работници от
        масива, за да можем да отпечатаме името му
        */
        // (Вадим бланката от джоба)
        employee currentUnderpaid = underpaids[i];
        //
        cout<<currentUnderpaid.name<<endl;
    }
    return 0;
}

/*
Забележка:
Можем да въвеждаме само по една дума на ред
*/

/*
Примерен вход:
2
Ivan
1234567890
Manager
789
Dragan
9876543210
Guard
699.993

Примерен изход:
Ivan

Примерен вход:
3
Ivan
1234567890
Manager
789
Dragan
9876543210
Guard
699.99
Maria
46578912
Chef
650

Примерен изход:
Dragan
Maria
*/
