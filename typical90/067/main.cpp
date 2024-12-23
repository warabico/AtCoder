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
#define FOR(i,a,b) for(long long i=a; i<=(long long)b; i++)
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
string n;
int k;

/* methods ********************************************************************/
void input()
{
    cin >> n >> k;
}

string base_n2m(string baseN, int n, int m)
{
    // 2 <= n, m <= 10
    ll coef;
    ll base10;
    string baseM;

    coef = 1;
    base10 = 0;

    // Convert base_n to base_10
    for(int i=baseN.size()-1; i >= 0; i--)
    {
        base10 += 1LL * (baseN[i]-'0') * coef;
        coef   *= n;
    }

    // Convert base_10 to base_m
    while(base10>0)
    {
        char c  = ((base10 % m) + '0');
        baseM   = c + baseM;
        base10 /= m;
    }
    if( baseM.size() == 0 )
    {
        baseM = "0";
    }

    return baseM;
}

string base9_8to5(string base9)
{
    REP(i, base9.size())
    {
        if( base9[i-1] == '8' )
        {
            base9[i-1] = '5';
        }
    }
    return base9;
}

void solve()
{
    REP(i, k)
    {
        n = base_n2m(n, 8, 9);
        n = base9_8to5(n);
    }
}

void output()
{
    cout << n << endl;
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

