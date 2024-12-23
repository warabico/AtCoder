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
LL n, m;
LL who[200001];
LL min_a;
LL idx;
stringstream ss;

/* methods ********************************************************************/
void input()
{
    min_a = 200001;
    idx = 200000;
    REP(i,200001)
    {
        who[i] = -1;
    }
    cin >> n >> m;
    REP(i, n)
    {
        LL ai;
        cin >> ai;
        if( min_a > ai )
        {
            for(LL x=idx; x>=ai; x--)
            {
                who[x] = i+1;
            }
            min_a = ai;
            idx = ai - 1;
        }
    }
    REP(i, m)
    {
        LL bi;
        cin >> bi;
        ss << who[bi] << endl;
    }
}

void solve()
{
    
}

void output()
{
    cout << ss.str();
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

