#include <iostream>
#include <string>
using namespace std;

int n;
long a;
long cnt;
long min_cnt;

int main()
{
    cin >> n;

    min_cnt = 1000000000;
    for (int i=0; i<n; i++)
    {
        cin >> a;
        cnt = 0;
        while( a % 2 == 0 )
        {
            cnt++;
            a = a / 2;
        }
        if( cnt < min_cnt )
        {
            min_cnt = cnt;
        }
    }

    cout << min_cnt << endl;

    return 0;
}