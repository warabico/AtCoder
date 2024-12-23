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
string answer;

/* methods ********************************************************************/
void input()
{
    cin >> s;
}

void solve()
{
    answer = "YES";
    for( long long i = 0; i < s.length(); i++ )
    {
        if( (s.length() - i) >= 11 && s.substr(i, 11).compare("dreameraser") == 0 )
        {
            i += 10;
        }
        else if( (s.length() - i) >= 10 && s.substr(i, 10).compare("dreamerase") == 0 )
        {
            i += 9;
        }
        else if( (s.length() - i) >= 7 && s.substr(i, 7).compare("dreamer") == 0 )
        {
            i += 6;
        }
        else if( (s.length() - i) >= 6 && s.substr(i, 6).compare("eraser") == 0 )
        {
            i += 5;
        }
        else if( (s.length() - i) >= 5 && s.substr(i, 5).compare("dream") == 0 )
        {
            i += 4;
        }
        else if( (s.length() - i) >= 5 && s.substr(i, 5).compare("erase") == 0 )
        {
            i += 4;
        }
        else
        {
            answer = "NO";
            return;
        }
    }
}

void output()
{
    cout << answer << endl;
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

