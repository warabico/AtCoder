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
int n, a, b;
int result;

/* methods ********************************************************************/
void input()
{
    cin >> n >> a >> b;
}

void solve()
{
    result = 0;
    for(int i=1; i<=n; i++)
    {
        int a0 = i % 10;
        int a1 = (i / 10) % 10;
        int a2 = (i / 100) % 10;
        int a3 = (i / 1000) % 10;
        int a4 = (i / 10000) % 10;
        int sum = a0 + a1 + a2 + a3 + a4;
        if( sum >= a && sum <= b )
        {
            result += i;
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

