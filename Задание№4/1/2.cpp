#include <iostream>
using namespace std;

const double attitude = 7.481;

int main()
{
	cout << "Enter the number of gallons: ";
	double count_of_gallons;
	cin >> count_of_gallons;
	double count_of_m3 = count_of_gallons / attitude;
	cout << "The number of cubic meters = " << count_of_m3 << endl;
	return 0;
}
