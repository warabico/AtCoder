#include <iostream>
#include <string>
using namespace std;

int a, b;

int main()
{
    cin >> a >> b;

    if( ( a % 2 != 0 ) && ( b % 2 != 0 ) )
    {
        cout << "Odd" << endl;
    }
    else
    {
        cout << "Even" << endl;
    }

    return 0;
}