#include <iostream>
#include <string>
using namespace std;

string s;
int len;
bool result;
int cnt[26];

int main()
{
    cin >> s;
    
    len = s.length();

    result = true;
    if( len % 2 != 0 )
    {
        result = false;
    }
    else
    {
        for (int i = 0; i < len-1; i = i + 2)
        {
            if( s[i] != s[i+1] )
            {
                result = false;
            }
            else
            {
                if( cnt[s[i] - 'a'] != 0 )
                {
                    result = false;
                }
                else
                {
                    cnt[s[i] - 'a'] = 2;
                }
            }
        }
    }

    if( result == true )
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    
    return 0;
}