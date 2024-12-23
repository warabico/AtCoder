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
vector<vector<int>> s;
vector<int> floor_pos;

string s_ij;
int result;

/* methods ********************************************************************/
void input()
{
    cin >> h >> w >> d;
    REP(j, h)
    {
        s.push_back({});
        cin >> s_ij;
        REP(i, w)
        {
            if( s_ij[i] == '.' )
            {
                floor_pos.push_back(j * w + i);
                s[s.size()-1].push_back(1);
            }
            else
            {
                s[s.size()-1].push_back(0);
            }
        }
    }
}

void solve()
{
    int temp;
    int i1, j1;
    int i2, j2;
    int d1, d2;
    result = 0;
    REP(x, floor_pos.size())
    {
        REP(y, floor_pos.size())
        {
            if( x != y )
            {
                i1 = floor_pos[x] % w;
                j1 = floor_pos[x] / w;
                i2 = floor_pos[y] % w;
                j2 = floor_pos[y] / w;

                temp = 0;
                REP(j,h)
                {
                    REP(i,w)
                    {
                        d1 = abs(i-i1) + abs(j-j1);
                        d2 = abs(i-i2) + abs(j-j2);

                        if( d1 <= d || d2 <= d )
                        {
                            temp += s[j][i];
                        }
                    }
                }
                if( result < temp )
                {
                    result = temp;
                }
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

