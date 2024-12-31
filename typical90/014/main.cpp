/* includes *******************************************************************/
#include <algorithm>
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
void input_vi(vi *v, int size);

/* variable definitions *******************************************************/
int n;
vi a, b;
ll sum;

/* methods ********************************************************************/
void input()
{
    cin >> n;
    input_vi(&a, n);
    input_vi(&b, n);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

void solve()
{
    sum = 0;
    for( int i = 0; i < n; i++ )
    {
        sum += (ll)abs(a[i] - b[i]);
    }
}

void output()
{
    cout << sum << endl;
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
void input_vi(vi *v, int size)
{
    int element;
    for( int i = 0; i < size; i++ )
    {
        cin >> element;
        v->push_back(element);
    }
}
