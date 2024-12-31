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
int n;
vector<vi> a;
int m;
bool bad_relation[10][10] = {{false}};
vi runners;
int result = 99999999;

/* methods ********************************************************************/
void input()
{
    cin >> n;
    for( int i = 0; i < n; i++ )
    {
        a.push_back({});
        input_vector(&a[i], n);
        runners.push_back(i);
    }
    cin >> m;
    for( int i = 0; i < m; i++ )
    {
        int x, y;
        cin >> x >> y;
        bad_relation[x-1][y-1] = true;
        bad_relation[y-1][x-1] = true;
    }
}

void solve()
{
    // Brute force
    do
    {
        bool flag = true;
        int sum = 0;
        for( int i = 0; i < n; i++ )
        {
            sum += a[runners[i]][i];
            if( i != n - 1 )
            {
                if( bad_relation[runners[i]][runners[i+1]] == true )
                {
                    flag = false;
                }
            }
        }
        if( flag == true )
        {
            result = min( result, sum );
        }
    } while( next_permutation( runners.begin(), runners.end() ) );
}

void output()
{
    if( result != 99999999 )
    {
        cout << result << endl;
    }
    else
    {
        cout << -1 << endl;
    }
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