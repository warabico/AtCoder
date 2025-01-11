/* includes *******************************************************************/
#include <algorithm>
#include <cmath>
#include <iomanip>
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
int n, q;
vi a;
stringstream ss;

/* methods ********************************************************************/
void input()
{
    cin >> n >> q;
    input_vector(&a, n);
}

int getIndex(int idx, int n, int offset)
{
    return (idx + offset) % n;
}

void solve()
{
    int t, x, y;
    int offset;
    offset = 0;
    for(int i=0; i<q; i++)
    {
        cin >> t >> x >> y;
        if(t == 1)
        {
            int tmp = a[getIndex(x-1, n, offset)];
            a[getIndex(x-1, n, offset)] = a[getIndex(y-1, n, offset)];
            a[getIndex(y-1, n, offset)] = tmp;
        }
        else if( t == 2)
        {
            offset = (offset + n - 1) % n;
        }
        else if( t == 3 )
        {
            ss << a[getIndex(x-1, n, offset)] << endl;
        }
        else
        {

        }
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
