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
bool result;

/* methods ********************************************************************/
void input()
{
    cin >> a >> b >> c;
}

void solve()
{
    result = false;
    if( a == b && b == c )
    {
        result = true;
    }
    if( a == (b + c) || b == (a + c) || c == (a + b) )
    {
        result = true;
    }
}

void output()
{
    cout << ( result ? "Yes" : "No" ) << endl;
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

