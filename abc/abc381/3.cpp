#include <iostream>
#include <string>
using namespace std;

long n;
string s;
long result;
long n_left;
long n_right;
int phase;

int main()
{
    cin >> n;
    cin >> s;

    result = 0;
    n_left = 0;
    n_right = 0;
    phase = 0;
    for( int i=0; i<n; i++ )
    {
        switch( s[i] )
        {
            case '1':
                if( phase != 0 )
                {
                    if( n_left >= n_right )
                    {
                        if( (n_right * 2 + 1) > result )
                        {
                            result = n_right * 2 + 1;
                        }
                    }
                    else
                    {
                        if( (n_left * 2 + 1) > result )
                        {
                            result = n_left * 2 + 1;
                        }
                    }
                    n_left = 0;
                    n_right = 0;
                }
                n_left++;
                phase = 0;
                break;
            case '/':
                if( phase != 0 )
                {
                    if( n_left >= n_right )
                    {
                        if( (n_right * 2 + 1) > result )
                        {
                            result = n_right * 2 + 1;
                        }
                    }
                    else
                    {
                        if( (n_left * 2 + 1) > result )
                        {
                            result = n_left * 2 + 1;
                        }
                    }
                    n_left = 0;
                    n_right = 0;
                }
                if( result == 0 )
                {
                    result = 1;
                }
                phase = 1;
                break;
            case '2':
                if( phase == 0 )
                {
                    n_left = 0;
                }
                else
                {
                    n_right++;
                }
                if( i == n - 1 )
                {
                    if( n_left >= n_right )
                    {
                        if( (n_right * 2 + 1) > result )
                        {
                            result = n_right * 2 + 1;
                        }
                    }
                    else
                    {
                        if( (n_left * 2 + 1) > result )
                        {
                            result = n_left * 2 + 1;
                        }
                    }
                    n_left = 0;
                    n_right = 0;
                }
                phase = 2;
                break;
            default:
                break;
        }
    }

    cout << result << endl;
    
    return 0;
}