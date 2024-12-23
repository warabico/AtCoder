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
#define FOR(i,a,b) for(long long (i)=(a); (i)<=b; (i)++)
#define REP(i,n)   FOR(i,1,n)
#define MIN_V(v)   *min_element(v.begin(), v.end())
#define MAX_V(v)   *max_element(v.begin(), v.end())

#define YES        "Yes"
#define NO         "No"

/* type definitions ***********************************************************/
typedef long long LL;
typedef unsigned long long ULL;

/* library definitions ********************************************************/

/* variable definitions *******************************************************/
int n;
string s;
bool result;

/* methods ********************************************************************/
void input()
{
    cin >> n;
    cin >> s;
}

void solve()
{
    result = true;

    if( n % 2 == 0 )
    {
        result = false;
    }
    else
    {
        REP(i,n)
        {
            if( i <= (n / 2) )
            {
                if( s[i-1] != '1' )
                {
                    result = false;
                }
            }
            else if( i == ( n / 2 + 1 ) )
            {
                if( s[i-1] != '/' )
                {
                    result = false;
                }
            }
            else
            {
                if( s[i-1] != '2' )
                {
                    result = false;
                }
            }
        }
    }
}

void output()
{
    if( result )
    {
        cout << YES << endl;
    }
    else
    {
        cout << NO << endl;
    }
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

