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
int counts[10];
bool result;

/* methods ********************************************************************/
void input()
{
    cin >> s;
}

void solve()
{
    int n = s.length();

    REP(i,n)
    {
        counts[s[i]-'0']++;
    }

    if( ( counts[1] == 1 ) &&
        ( counts[2] == 2 ) &&
        ( counts[3] == 3 ) )
    {
        result = true;
    }
    else
    {
        result = false;
    }
}

void output()
{
    cout << (result ? YES : NO) << endl;
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

