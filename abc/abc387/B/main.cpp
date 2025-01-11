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
int x;
int sum;

/* methods ********************************************************************/
void input()
{
    cin >> x;
}

void solve()
{
    sum = 0;
    for(int i=1; i<=9; i++)
    {
        for(int j=1; j<=9; j++) {
            if( ( i * j ) != x )
            {
                sum += (i * j);
            }
        }
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
