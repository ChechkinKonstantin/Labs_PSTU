#include <iostream>
using namespace std;

int main()
{
	int a = 5;
	int* p = &a; //������������
	cout << *p << endl; // ��������� ��������, ����������� �� ������ ���������� a (���������������)
	cout << p << endl; // ����� ������, ����������� � ��������� p
	return 0;
}
