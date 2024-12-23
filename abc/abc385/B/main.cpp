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
int h, w;
int x, y;
vector<string> s;
string t;
int mapping[100][100];
int answer;


/* methods ********************************************************************/
void input()
{
    string si;
    cin >> h >> w >> x >> y;
    x--;
    y--;
    REP(i, h)
    {
        cin >> si;
        s.push_back(si);
    }
    REP(i, h)
    {
        REP(j, w)
        {
            if( s[i][j] == '#' )
            {
                mapping[i][j] = -1;
            }
            else if( s[i][j] == '.' )
            {
                mapping[i][j] = 0;
            }
            else
            {
                mapping[i][j] = 1;
            }
        }
    }
    cin >> t;
}

void solve()
{
    answer = 0;

    REP(i, t.length())
    {
        switch(t[i])
        {
            case 'U':
                if( mapping[x-1][y] != -1 )
                {
                    x = x - 1;
                    answer += mapping[x][y];
                    mapping[x][y] = 0;
                }
                break;
            case 'D':
                if( mapping[x+1][y] != -1 )
                {
                    x = x + 1;
                    answer += mapping[x][y];
                    mapping[x][y] = 0;
                }
                break;
            case 'L':
                if( mapping[x][y-1] != -1 )
                {
                    y = y - 1;
                    answer += mapping[x][y];
                    mapping[x][y] = 0;
                }
                break;
            case 'R':
                if( mapping[x][y+1] != -1 )
                {
                    y = y + 1;
                    answer += mapping[x][y];
                    mapping[x][y] = 0;
                }
                break;
            default:
                break;
        }
    }
}

void output()
{
    x++;
    y++;
    cout << x << " " << y << " " << answer << endl;
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

