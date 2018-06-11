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

    // underpaid -> ������������ ���������
    /* employee underpaid[n]; -> �����, ����� �� ���� �������������� ���������
    ���� �� ��� �� 0 �� n ��������.
    */
    employee underpaids[n];
    int index = 0;

    /* ��������� �� ��������� ������������ �� �����
       �������� (���� �������� �� �� ������� n ���� -
       ������� ���� �� �� ������� � ������)
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

        /* ��������� ��� �������� (��� ���� �� ������
           �� ������� ������ � ������� �� �����), �����
           �� ������� � ���� �� ���������� ����� ����� �����
        */
        employee rabotnik;
        rabotnik.name = ime;
        rabotnik.egn = egn;
        rabotnik.duty = poziciq;
        rabotnik.payment = zaplata;

        /* ��� ��������� �� � ��� 700 ����, ��� �� �������
        ��� �������������� ��������� */
        if(rabotnik.payment < 700) {

        /*�������� �� � ������ �� ������������ �� �������
          �������� �������, ����� � index*/
            underpaids[index] = rabotnik;
            index++;
        }
    }
     // ������� ���� �� �������������� ���������, �����
     // ��� �������� � ������
    int broiNiskoplateni = index;

    /*���� �� ������ ���� �� ���� ��������������
      ��������� � �� ���������� ����� ��*/
    for(int i = 0; i < broiNiskoplateni; i++) {
        /*
        ���� �� ������� ���� �� �������������� ��������� ��
        ������, �� �� ����� �� ���������� ����� ��
        */
        // (����� �������� �� �����)
        employee currentUnderpaid = underpaids[i];
        //
        cout<<currentUnderpaid.name<<endl;
    }
    return 0;
}

/*
���������:
����� �� ��������� ���� �� ���� ���� �� ���
*/

/*
�������� ����:
2
Ivan
1234567890
Manager
789
Dragan
9876543210
Guard
699.993

�������� �����:
Ivan

�������� ����:
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

�������� �����:
Dragan
Maria
*/
