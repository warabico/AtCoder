#include <iostream>
#include <string>
using namespace std;

long query( string s, long l, long r )
{
    long result;
    long n_left;
    long n_right;
    int phase;

    result = 0;
    n_left = 0;
    n_right = 0;
    phase = 0;
    for( long i=(l-1); i<r; i++ )
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
                if( i == r - 1 )
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
        cout << l << ", " << r << " : " << n_left << " , " << n_right << " @ " << i << " = " << result << endl;
    }

    return result;
}

int main()
{
    long n;
    long q;
    string str;
    long l, r;
    long results[100000];

    cin >> n;
    cin >> q;
    cin >> str;

    for( int idx=0; idx<q; idx++ )
    {
        cin >> l >> r;
        results[idx] = query(str, l, r);
    }

    for( int idx=0; idx<q; idx++ )
    {
        cout << results[idx] << endl;
    }
    return 0;
}