/* includes *******************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

/* namespaces *****************************************************************/
using namespace std;

/* macro definitions **********************************************************/
#define YES        "YES"
#define NO         "NO"
#define Yes        "Yes"
#define No         "No"

/* type definitions ***********************************************************/
typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;

/* library definitions ********************************************************/

/* variable definitions *******************************************************/
int n, q;
vll a, b;
stringstream ss;

/* methods ********************************************************************/
void input()
{
    ll ai;
    cin >> n;
    for( int i = 0; i < n; i++ )
    {
        cin >> ai;
        a.push_back(ai);
    }
    // add dummy data to use lower_bound function properly
    a.push_back(9999999999);
    // sort classes data
    sort(a.begin(), a.end());
    cin >> q;
}

ll calc_complaints( ll rating, vll *classes )
{
    ll complaints_l = 9999999999;
    ll complaints_r = 9999999999;

    // get index
    auto it = lower_bound(classes->begin(), classes->end(), rating);

    // get minimum complaints
    if( it == classes->begin() )
    {
        complaints_r = abs( rating - *it );
    }
    else if( it == classes->end() )
    {
        it--;
        complaints_l = abs( rating - *it );
    }
    else
    {
        complaints_r = abs( rating - *it );
        it--;
        complaints_l = abs( rating - *it );
    }

    return min( complaints_l, complaints_r );
}

void solve()
{
    ll bj;
    for( int j = 0; j < q; j++ )
    {
        cin >> bj;
        b.push_back(bj);
    }
    for( int j = 0; j < q; j++ )
    {
        ss << calc_complaints(b[j], &a) << endl;
    }
}

void output()
{
    cout << ss.str();
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

