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
ll k;
string s;
string t;
bool result;

/* methods ********************************************************************/
void input()
{
    cin >> k;
    cin >> s;
    cin >> t;
}

void solve()
{
    ll s_len = s.length();
    ll t_len = t.length();

    result = true;
    if( s_len == t_len )
    {
        ll mismatch_cnt = 0;
        REP(i, s_len)
        {
            if( s[i-1] != t[i-1] )
            {
                mismatch_cnt++;
                if( mismatch_cnt > k )
                {
                    result = false;
                    break;
                }
            }
        }
    }
    else if( s_len == t_len - 1 )
    {
        ll offset = 0;
        REP(i, s_len)
        {
            if( s[i-1] != t[i-1+offset] )
            {
                offset++;
                if( offset > k )
                {
                    result = false;
                    break;
                }
            }
        }
    }
    else if( s_len == t_len + 1 )
    {
        ll offset = 0;
        REP(i, t_len)
        {
            if( s[i-1+offset] != t[i-1] )
            {
                offset++;
                if( offset > k )
                {
                    result = false;
                    break;
                }
            }
        }
    }
    else
    {
        result = false;
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

