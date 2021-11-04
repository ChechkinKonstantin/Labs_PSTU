#include <iostream>
using namespace std;

int main()
{
    cout << "Enter the temperature value in degrees Fahrenheit: ";
    double temp_F, temp_C;
    cin >> temp_F;
    temp_C = (temp_F - 32) / 1.8;
    cout << "Entered temperature value in degrees Celsius = " << temp_C;
    return 0;
}
