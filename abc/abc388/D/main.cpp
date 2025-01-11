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
ll a[500010];
ll x[500010] = {0};

/* methods ********************************************************************/
void input()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
}

void solve()
{
    for(int i=0; i<n; i++)
    {
        a[i] = a[i] - ( (n-1) - i ) + i - x[i];
        if( a[i] < 0 )
        {
            int idx = n - a[i] * -1;
            x[idx]++;
            a[i] = 0;
        }
        x[i+1] += x[i];
    }
}

void output()
{
    for(int i=0; i<n; i++)
    {
       cout << a[i] << " ";
    }
    cout << endl;
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
