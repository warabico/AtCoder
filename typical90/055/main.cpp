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
ll n, p, q;
vector<ll> a;
ll ans;

/* methods ********************************************************************/
void input()
{
    ll ai;
    cin >> n >> p >> q;
    REP(i,n)
    {
        cin >> ai;
        a.push_back(ai);
    }
}

void solve()
{
    ll x;

    ans = 0;
    FOR(i, 1, n-4)
    {
        FOR(j, i+1, n-3)
        {
            FOR(k, j+1, n-2)
            {
                FOR(l, k+1, n-1)
                {
                    FOR(m, l+1, n)
                    {
                        x  = a[i-1] % p;
                        x  = x % p;
                        x *= a[j-1] % p;
                        x  = x % p;
                        x *= a[k-1] % p;
                        x  = x % p;
                        x *= a[l-1] % p;
                        x  = x % p;
                        x *= a[m-1] % p;
                        x  = x % p;
                        if( x == q )
                        {
                            ans++;
                        }
                    }
                }
            }
        }
    }
}

void output()
{
    cout << ans << endl;
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

