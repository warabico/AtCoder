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
int a, b, c;
int x;

int result;

/* methods ********************************************************************/
void input()
{
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> x;
}

void solve()
{
    result = 0;
    REP(i, a+1)
    {
        REP(j, b+1)
        {
            REP(k, c+1)
            {
                int sum = 500 * i + 100 * j + 50 * k;
                if( x == sum )
                {
                    result++;
                }
            }
        }
    }
}

void output()
{
    cout << result << endl;
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

