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
    // ��� ��������� �� ����� ����� ��� �� ��� (�� ����� ����)
    // � ����� ���������� �� ������� ��� �� ����� � ����������,
    // ����� �������� ����� �� ���������� �� ������
    fin>>x>>y>>z;
    cout<<x<<endl;
    cout<<y<<endl;
    cout<<z<<endl;
    // ������� �������, ����� ��� ������� �� ������� ��� ���� �� �����
    // � �� ��������.
    int sum = x + y;
    // ������� �� ������� �� ����� �� ������ ���, ������ �����
    // �� ������� �� ���� �� �����
    fout<<endl;
    // ������ �� �������� ���� �������� ��� �� �����.
    fout<<sum<<endl;
    return 0;
}
