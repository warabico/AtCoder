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
string answer;

/* methods ********************************************************************/
void input()
{
    cin >> n;
}

void solve()
{
    int t0;
    int x0;
    int y0;
    int t1;
    int x1;
    int y1;
    int dt;
    int distance;

    t0 = 0;
    x0 = 0;
    y0 = 0;

    answer = "Yes";
    REP(i, n)
    {
        cin >> t1 >> x1 >> y1;
        dt = t1 - t0;
        distance = abs(x1 - x0) + abs(y1 - y0);
        if( dt >= distance )
        {
            if( (dt - distance) % 2 == 0 )
            {
                t0 = t1;
                x0 = x1;
                y0 = y1;
            }
            else
            {
                answer = "No";
            }
        }
        else
        {
            answer = "No";
        }
    }
}

void output()
{
    cout << answer << endl;
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

