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
string s;
vector<int> a;
int idx;

/* methods ********************************************************************/
void input()
{
    cin >> s;
}

void solve()
{
    idx = 0;
    REP(i,s.length())
    {
        if(s[i] == '|')
        {
            a.push_back(0);
            idx++;
        }
        else
        {
            a[idx-1]++;
        }
    }
}

void output()
{
    REP(i,a.size())
    {
        if( i != (a.size() - 1) )
        {
            cout << a[i] << " ";
        }
    }
    cout << endl;
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

