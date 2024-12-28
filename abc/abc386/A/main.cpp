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
int a, b, c, d;
int cnt[14] = {0};
bool result = false;
bool one_pair = false;

/* methods ********************************************************************/
void input()
{
    cin >> a >> b >> c >> d;
}

void solve()
{
    cnt[a]++;
    cnt[b]++;
    cnt[c]++;
    cnt[d]++;

    REP(i, 13)
    {
        if(cnt[i] == 3)
        {
            result = true;
        }
        if(cnt[i] == 2)
        {
            if( one_pair == false)
            {
                one_pair = true;
            }
            else
            {
                result = true;
            }
        }
    }
}

void output()
{
    cout << (result ? Yes : No) << endl;
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

