#include <iostream>
using namespace std;

int main()
{
	int h1, m1, s1, h2, m2, s2, t;
	cout << "Enter the beginning of the time span, separated by a space(hh mm ss): ";
	cin >> h1 >> m1 >> s1;
	cout << "Enter the end of the time span, separated by a space(hh mm ss): ";
	cin >> h2 >> m2 >> s2;
	t = (h2 * 3600 + m2 * 60 + s2) - (h1 * 3600 + m1 * 60 + s1);
	cout << "Time passed: " << t / 3600 << " hours " << t % 3600 / 60 << " minutes " << t % 60 << " secondes " << endl;
	return 0;
}
