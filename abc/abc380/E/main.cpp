#include <algorithm>
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
LL n;
LL q;
vector<LL> answer;

/* methods ********************************************************************/
void input()
{
    cin >> n >> q;
}

void solve()
{
    int type;
    LL x;
    LL c;
    vector<LL> cnt(n,1);
    set<pair<LL,LL>> s;

    REP(i,n)
    {
        s.insert({i,i});
    }
    s.insert({-1,2e9});
    s.insert({n,2e9});

    REP(i,q)
    {
        cin >> type;
        switch (type)
        {
            case 1:
                cin >> x >> c;
                x--;
                c--;
                auto it    = s.lower_bound({x,2e9});
                auto[R,Rc] = *it;
                auto[L,Mc] = *--it;
                auto[_,Lc] = *--it;
                cnt[Mc]   -= R-L;
                cnt[c]    += R-L;
                it++;
                it = s.erase(it);
                if(c == Rc)
                {
                    it = s.erase(it);
                }
                if(c == Lc)
                {
                    // pass
                }
                else{
                    s.insert({L,c});
                }
                break;

            case 2:
                cin >> c;
                c--;
                answer.push_back(cnt[c]);
                break;
            
            default:
                break;
        }
    }
}

void output()
{
    REP(i,q)
    {
        cout << answer[i] << endl;
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

