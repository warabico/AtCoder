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
ll n, k;
ll a[1001];
ll b[1001];
ll diff;
bool result;

/* methods ********************************************************************/
void input()
{
    cin >> n >> k;
    REP(i, n)
    {
        cin >> a[i];
    }
    REP(i, n)
    {
        cin >> b[i];
        diff += abs(b[i] - a[i]);
    }
}

void solve()
{
    if( k >= diff )
    {
        if( (k - diff) % 2 == 0 )
        {
            result = true;
        }
        else
        {
            result = false;
        }
    }
    else
    {
        result = false;
    }
}

void output()
{
    cout << (result ? Yes : No) << endl;
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

