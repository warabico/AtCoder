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
#define FOR(i,a,b) for(long long i=a; i<b; i++)
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
int h, w;
int a[2000][2000];
int hsum[2000];
int vsum[2000];

/* methods ********************************************************************/
void input()
{
    cin >> h >> w;
    REP(y, h)
    {
        REP(x, w)
        {
            cin >> a[y][x];
            hsum[y] += a[y][x];
            vsum[x] += a[y][x];
        }
    }
}

void solve()
{

}

void output()
{
    REP(y, h)
    {
        REP(x, w)
        {
            if( x < w-1 )
            {
                cout << hsum[y] + vsum[x] - a[y][x] << " ";
            }
            else
            {
                cout << hsum[y] + vsum[x] - a[y][x];
            }
        }
        cout << endl;
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

