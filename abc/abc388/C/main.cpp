/* includes *******************************************************************/
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
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

#define PI         ((double)3.14159265358979323846)

/* type definitions ***********************************************************/
typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;

/* library definitions ********************************************************/
void input_vector(vi  *v, int size);
void input_vector(vll *v, int size);
void input_vector(vs  *v, int size);

/* variable definitions *******************************************************/
ll n;
vll a;
ll ans;

/* methods ********************************************************************/
void input()
{
    cin >> n;
    input_vector(&a, n);
}

int findIdx( vll *v, ll a )
{
    ll idx = 0;
    ll div = 2;
    bool next = true;
    while( next )
    {
        ll offset = (v->size() + div / 2) / div;
        div = div * 2;

        if( (idx + offset) < v->size() )
        {
            if( v->at(idx + offset) < a )
            {
                idx = idx + offset;
            }
        }

        if( offset == 0 )
        {
            next = false;
        }
    }
    return idx;
}

void solve()
{
    ans = 0;
    for(int i=0; i<n; i++)
    {
        ll idx = findIdx(&a, a[i] * 2);
        if( ( idx + 1 < n            ) &&
            ( a[idx + 1] >= a[i] * 2 ) )
        {
            ans += n - (idx + 1);
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
void input_vector(vi *v, int size)
{
    int element;
    for( int i = 0; i < size; i++ )
    {
        cin >> element;
        v->push_back(element);
    }
}

void input_vector(vll *v, int size)
{
    ll element;
    for( int i = 0; i < size; i++ )
    {
        cin >> element;
        v->push_back(element);
    }
}

void input_vector(vs *v, int size)
{
    string element;
    for( int i = 0; i < size; i++ )
    {
        cin >> element;
        v->push_back(element);
    }
}
