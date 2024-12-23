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
int q;
ll deck[200009];
vi answer;
int l, r;

/* methods ********************************************************************/
void input()
{
    int ti;
    ll xi;
    cin >> q;

    l = 100000;
    r = 100001;
    REP(i, q)
    {
        cin >> ti >> xi;
        switch (ti)
        {
        case 1:
            deck[l] = xi;
            l--;
            break;
        case 2:
            deck[r] = xi;
            r++;
            break;
        case 3:
            answer.push_back(deck[l+xi]);
            break;
        
        default:
            break;
        }
    }
}

void solve()
{
    
}

void output()
{
    REP(i, answer.size())
    {
        cout << answer[i-1] << endl;
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

