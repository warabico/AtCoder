#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <string>
#include <vector>

/* namespaces *****************************************************************/
using namespace std;

/* macro definitions **********************************************************/
#define FOR(i,a,b) for(long long (i)=(a); (i)<b; (i)++)
#define REP(i,n)   FOR(i,0,n)
#define MIN_V(v)   *min_element(v.begin(), v.end())
#define MAX_V(v)   *max_element(v.begin(), v.end())

#define YES        "Yes"
#define NO         "No"

/* type definitions ***********************************************************/
typedef long long LL;
typedef unsigned long long ULL;

/* library definitions ********************************************************/

/* variable definitions *******************************************************/
string s;
int q;
LL k[200000];

/* methods ********************************************************************/
void input()
{
    cin >> s;
    cin >> q;
    REP(i, q)
    {
        cin >> k[i];
    }
}

void solve()
{

}

void output()
{
    LL x;
    LL m;
    LL cnt;

    REP(i, q)
    {
        cnt = 0;
        m = k[i] % s.length();
        if( m == 0 )
        {
            m = s.length();
        }

        x = ( k[i] - m ) / s.length();
        while( x > 0 )
        {
            if( x & 1 == 1 )
            {
                cnt++;
            }
            x = x >> 1;
        }

        if( cnt % 2 == 0 )
        {
            cout << s[m-1];
        }
        else
        {
            if( s[m-1] >= 'a' )
            {
                cout << char(toupper(s[m-1]));
            }
            else
            {
                cout << char(tolower(s[m-1]));
            }
        }
        if( i != (q-1) )
        {
            cout << " ";
        }
    }
    cout << endl;
}

/* main ***********************************************************************/
int main()
{
    input();
    solve();
    output();
    return 0;
}

/* libraries ******************************************************************/

