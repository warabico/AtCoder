#include <iostream>
#include <string>
using namespace std;

long n;
string s;
int result;

int main()
{
    cin >> n;
    cin >> s;

    result = 1;
    if( n % 2 == 0 )
    {
        result = 0;
    }
    else
    {
        for (int i=1; i<=n; i++)
        {
            if( i <= (n / 2) )
            {
                if( s[i-1] != '1' )
                {
                    result = 0;
                }
            }
            else if( i == ( n / 2 + 1 ) )
            {
                if( s[i-1] != '/' )
                {
                    result = 0;
                }
            }
            else
            {
                if( s[i-1] != '2' )
                {
                    result = 0;
                }
            }
        }
    }

    if( result == 1 )
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    
    return 0;
}