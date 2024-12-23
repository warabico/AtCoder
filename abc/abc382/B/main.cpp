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
int n, d;
string s;

/* methods ********************************************************************/
void input()
{
    cin >> n >> d;
    cin >> s;
}


void solve()
{
    REP(i, s.length())
    {
        int idx = s.length() - 1 - i;
        if( s[idx] == '@' )
        {
            if( d > 0 )
            {
                s[idx] = '.';
                d--;
            }
        }
    }
}

void output()
{
    cout << s << endl;
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

