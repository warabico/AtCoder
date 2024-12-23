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
int n;
int y;
int a, b, c;

/* methods ********************************************************************/
void input()
{
    cin >> n >> y;
}

void solve()
{
    a = -1;
    b = -1;
    c = -1;

    int c_start;
    c_start = (y / 1000) % 5;
    for( int i = c_start; i <= n; i += 5 )
    {
        for( int j = 0; j <= (n - i); j++ )
        {
            int k = n - i - j;
            int sum = k * 10000 + j * 5000  + i * 1000;
            if( sum == y )
            {
                a = k;
                b = j;
                c = i;
                return;
            }
        }
    }
}

void output()
{
    cout << a << " " << b << " " << c << endl;
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

