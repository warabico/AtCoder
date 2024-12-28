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
#define FOR(i,a,b) for(long long i=a; i<=b; i++)
#define REP(i,n)   FOR(i,1,n)
#define MIN_V(v)   *min_element(v.begin(), v.end())
#define MAX_V(v)   *max_element(v.begin(), v.end())

#define YES        "YES"
#define NO         "NO"
#define Yes        "Yes"
#define No         "No"

/* type definitions ***********************************************************/
typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<string> vs;

/* library definitions ********************************************************/

/* variable definitions *******************************************************/
int n, m;
vector<pair<pair<int, int>, char>> xyc;
bool result = true;

/* methods ********************************************************************/
void input()
{
    cin >> n >> m;
}

void solve()
{
    int x, y;
    char c;

    REP(i, m)
    {
        cin >> x >> y >> c;
        xyc.push_back({{x, y}, c});
    }

    sort(xyc.begin(), xyc.end());

    result = true;
    int white_min = 1000000009;
    REP(i, m)
    {
        int  x = xyc[i-1].first.first;
        int  y = xyc[i-1].first.second;
        char c = xyc[i-1].second;
        if( c == 'W' )
        {
            if( y < white_min )
            {
                white_min = y;
            }
        }
        else
        {
            if( y >= white_min )
            {
                result = false;
                break;
            }
        }
    }
}

void output()
{
    cout << ( result ? Yes : No ) << endl;
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

