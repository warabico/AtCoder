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
#define FOR(i,a,b) for(long long i=a; i<=b; i++)
#define REP(i,n)   FOR(i,1,n)
#define MIN_V(v)   *min_element(v.begin(), v.end())
#define MAX_V(v)   *max_element(v.begin(), v.end())

#define YES        "YES"
#define NO         "NO"
#define Yes        "Yes"
#define No         "No"

/* type definitions ***********************************************************/
typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<string> vs;

/* library definitions ********************************************************/

/* variable definitions *******************************************************/
ll a, b, c;
ll s;

/* methods ********************************************************************/
void input()
{
    cin >> a >> b >> c;
}

ll gcd(ll x, ll y)
{
    if( y == 0 )
    {
        return x;
    }
    return gcd(y, x % y);
}

void solve()
{
    s = gcd(a, gcd(b, c));
}

void output()
{
    cout << (a/s - 1LL) + (b/s - 1LL) + (c/s - 1LL) << endl;
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

