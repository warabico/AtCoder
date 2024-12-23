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
int h, w, d;
int result;

const int INF=2100000000;

/* methods ********************************************************************/
void input()
{
    cin >> h >> w >> d;
}

void solve()
{
    result = 0;

    vector<pair<int, int>> order;
    vector<string> s(h);
    REP(i,h) cin >> s[i];
    vector p(h, vector<int>(w, INF));
    REP(i,h)
    {
        REP(j,w)
        {
            if(s[i][j] == 'H')
            {
                p[i][j] = 0;
                order.push_back({i,j});
            }
        }
    }
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    REP(idx,order.size())
    {
        auto [a, b] = order[idx];
        if( p[a][b] > d )
        {
            break;
        }
        result++;
        REP(k,4)
        {
            int x = a + dx[k];
            int y = b + dy[k];
            if( x == -1 || x == h || y == -1 || y == w )
            {
                continue;
            }
            if( s[x][y] == '#' )
            {
                continue;
            }
            if( p[x][y] > (p[a][b] + 1) )
            {
                p[x][y] = p[a][b] + 1;
                order.push_back({x, y});
            }
        }
    }
}

void output()
{
    cout << result << endl;
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

