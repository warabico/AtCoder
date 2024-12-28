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
string s;
int btn_cnt;
bool bf_is_zero = false;

/* methods ********************************************************************/
void input()
{
    cin >> s;
}

void solve()
{
    REP(i, s.length())
    {
        if( s[i-1] == '0' )
        {
            if(bf_is_zero)
            {
                bf_is_zero = false;
            }
            else
            {
                bf_is_zero = true;
                btn_cnt++;
            }
        }
        else
        {
            bf_is_zero = false;
            btn_cnt++;
        }
    }
}

void output()
{
    cout << btn_cnt << endl;
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

