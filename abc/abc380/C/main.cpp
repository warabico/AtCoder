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
int n;
int k;
string s;
vector<string> vs0;
vector<string> vs1;
int phase;
int first;

/* methods ********************************************************************/
void input()
{
    cin >> n >> k;
    cin >> s;
}

void solve()
{
    first = -1;
    phase = -1;
    REP(i,n)
    {
        switch (s[i])
        {
            case '0':
                if( first == -1 )
                {
                    first = 0;
                }
                if( phase != 0 )
                {
                    vs0.push_back("0");
                }
                else
                {
                    vs0[vs0.size()-1] += "0";
                }
                phase = 0;
                break;
            
            case '1':
                if( first == -1 )
                {
                    first = 1;
                }
                if( phase != 1 )
                {
                    vs1.push_back("1");
                }
                else
                {
                    vs1[vs1.size()-1] += "1";
                }
                phase = 1;
                break;

            default:
                break;
        }
    }
}

void output()
{
    if( first == 0 )
    {
        REP(i,vs0.size())
        {
            if( i == (k - 1) )
            {
                cout << vs1[i] << vs0[i];
            }
            else
            {
                if( i >= vs1.size() )
                {
                    cout << vs0[i];
                }
                else
                {
                    cout << vs0[i] << vs1[i];
                }
            }
        }
    }
    else
    {
        cout << vs1[0];
        REP(i,vs0.size())
        {
            if( i == (k - 2) )
            {
                cout << vs1[i+1] << vs0[i];
            }
            else
            {
                if( i >= (vs1.size() - 1) )
                {
                    cout << vs0[i];
                }
                else
                {
                    cout << vs0[i] << vs1[i+1];
                }
            }
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

