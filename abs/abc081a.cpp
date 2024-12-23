#include <iostream>
#include <string>
using namespace std;

string s;
int cnt;

int main()
{
    cin >> s;

    cnt = 0;
    for(int i=0; i<3; i++)
    {
        if( s[i] == '1' )
        {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}