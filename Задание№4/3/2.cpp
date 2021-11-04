#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cout << "Enter 5 symbols: ";
    cin >> s;
    cout << "Reversed 5 symbols: ";
    for (int i = s.size() - 1; i >= 0; i--)
    {
        cout << s[i];
    }
    cout << endl;
    return 0;
}
