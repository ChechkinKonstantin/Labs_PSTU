#include <iostream>
using namespace std;

int main()
{
	int a = 5;
	int* p = &a; //разадресация
	cout << *p << endl; // получение значения, хранящегося по адресу переменной a (разыменовывание)
	cout << p << endl; // вывод адреса, хранящегося в указателе p
	return 0;
}
