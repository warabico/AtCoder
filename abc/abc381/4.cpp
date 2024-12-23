#include <iostream>
#include <string>
using namespace std;

long n;
long a[200002];
long indices_even[200002];
long indices_odd[200002];
long idx_left_even;
long idx_left_odd;
long max_cnt_even;
long max_cnt_odd;
long cnt;
bool valid_even;
bool valid_odd;

int main()
{
    cin >> n;
    for( int i=1; i<=n; i++ )
    {
        cin >> a[i];
    }

    idx_left_even = 0;
    idx_left_odd = 0;
    max_cnt_even = 0;
    max_cnt_odd = 0;
    valid_even = false;
    valid_odd = false;
    
    for( int i=1; i<n; i++ )
    {
        if( i%2 == 0 )
        {
            if( a[i] == a[i+1] )
            {
                if( valid_even == false )
                {
                    idx_left_even = i;
                }
                else
                {
                    if( indices_even[a[i]] >= idx_left_even )
                    {
                        cnt = i - idx_left_even;
                        if( cnt > max_cnt_even )
                        {
                            max_cnt_even = cnt;
                        }
                        idx_left_even = indices_even[a[i]] + 2;
                    }
                }
                cnt = i + 2 - idx_left_even;
                if( cnt > max_cnt_even )
                {
                    max_cnt_even = cnt;
                }
                valid_even = true;
                indices_even[a[i]] = i;
            }
            else
            {
                if( valid_even == true )
                {
                    if( idx_left_even != 0 )
                    {
                        cnt = i - idx_left_even;
                        if( cnt > max_cnt_even )
                        {
                            max_cnt_even = cnt;
                        }
                    }
                }
                idx_left_even = 0;
                valid_even = false;
            }
        }
        else
        {
            if( a[i] == a[i+1] )
            {
                if( valid_odd == false )
                {
                    idx_left_odd = i;
                }
                else
                {
                    if( indices_odd[a[i]] >= idx_left_odd )
                    {
                        cnt = i - idx_left_odd;
                        if( cnt > max_cnt_odd )
                        {
                            max_cnt_odd = cnt;
                        }
                        idx_left_odd = indices_odd[a[i]] + 2;
                    }
                }
                cnt = i + 2 - idx_left_odd;
                if( cnt > max_cnt_odd )
                {
                    max_cnt_odd = cnt;
                }
                valid_odd = true;
                indices_odd[a[i]] = i;
            }
            else
            {
                if( valid_odd == true )
                {
                    if( idx_left_odd != 0 )
                    {
                        cnt = i - idx_left_odd;
                        if( cnt > max_cnt_odd )
                        {
                            max_cnt_odd = cnt;
                        }
                    }
                }
                idx_left_odd = 0;
                valid_odd = false;
            }
        }
    }

    if( max_cnt_even >= max_cnt_odd )
    {
        cout << max_cnt_even << endl;
    }
    else
    {
        cout << max_cnt_odd << endl;
    }

    return 0;
}