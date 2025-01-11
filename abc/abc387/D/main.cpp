/* includes *******************************************************************/
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
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
int h, w;
vs s;
int ans;

const int inf = 1e9;

/* methods ********************************************************************/
void input()
{
    cin >> h >> w;
    input_vector(&s, h);
}

void solve()
{
    int si, sj, gi, gj;
    for(int i=0; i < h; i++)
    {
        for(int j=0; j < w; j++)
        {
            if(s[i][j] == 'S')
            {
                si = i;
                sj = j;
            }
            if(s[i][j] == 'G')
            {
                gi = i;
                gj = j;
            }
        }
    }
    
    ans = inf;

    vector<vector<pair<int, int>>> moves(2);
    moves[0] = {{0,1}, {0,-1}};
    moves[1] = {{1,0}, {-1,0}};

    for(int p=0; p < 2; p++)
    {
        vector d(h, vector<int>(w, inf));
        d[si][sj] = 0;
        queue<pair<int, int>> q;
        q.emplace(si, sj);
        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (auto [di, dj]: moves[(i+j+p) & 1])
            {
                int ni = i + di;
                int nj = j + dj;

                // 範囲外
                if(ni<0 or ni >= h or nj < 0 or nj >= w) continue;

                // 壁
                if(s[ni][nj] == '#') continue;

                // 未到達の空白エリア
                if(d[ni][nj] == inf) {
                    d[ni][nj] = d[i][j] + 1;
                    q.emplace(ni, nj);
                }
            }
        }
        ans = min(ans, d[gi][gj]);
    }
    if (ans==inf) ans = -1;
}

void output()
{
    cout << ans << endl;
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
