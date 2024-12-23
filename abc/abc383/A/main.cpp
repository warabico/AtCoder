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
int n;
int t;
int v;

int t_buf;
int result;

/* methods ********************************************************************/
void input()
{
    cin >> n;
}

void solve()
{
    t_buf = 0;
    result = 0;
    REP(i, n)
    {
        cin >> t >> v;
        if( (t - t_buf) >= result )
        {
            result = 0;
        }
        else
        {
            result = result - ( t - t_buf );
        }
        result += v;
        t_buf = t;
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

