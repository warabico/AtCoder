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
LL n;
vector<LL> primes;
LL cnt;

/* methods ********************************************************************/
void input()
{
    cin >> n;
}

void solve()
{
    bool isPrime;
    cnt = 0;
    for(int i=2; i<=n/2; i++)
    {
        isPrime = true;
        REP(j,primes.size())
        {
            if( i % primes[j] == 0 )
            {
                isPrime = false;
                break;
            }
        }
        if(isPrime)
        {
            primes.push_back(i);
        }
    }
    REP(i, primes.size())
    {
        cout << primes[i] << endl;
        for( LL j=i; j<primes.size(); j++ )
        {
            if( i == j )
            {
                if( primes[i] * primes[i] * primes[i] * primes[i] * primes[i] * primes[i] * primes[i] * primes[i] <= n )
                {
                    cnt++;
                }
            }
            else
            {
                if( primes[i] * primes[i] * primes[j] * primes[j] <= n )
                {
                    cnt++;
                }
            }
        }
    }
}

void output()
{
    cout << cnt << endl;
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

