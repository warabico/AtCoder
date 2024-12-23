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
int n, m;
stringstream ss;
vector<vector<int>> x;

/* methods ********************************************************************/
void input()
{
    cin >> n >> m;
}

void dive( vector<int> v, int num, int margin )
{
    for( int i = 0; i <= margin; i++ )
    {
        if( num == 0 )
        {
            vector<int> v2(v.size());
            copy(v.begin(), v.end(), v2.begin());
            v2.push_back( v[v.size()-1] + 10 + i );
            x.push_back( v2 );
            break;
        }
        else
        {
            vector<int> v2(v.size());
            copy(v.begin(), v.end(), v2.begin());
            v2.push_back( v[v.size()-1] + 10 + i );
            dive( v2, num-1, margin-i );
        }
    }
}

void solve()
{
    int margin;
    for( int i = 1; i <= m; i++ )
    {
        margin = m - 10 * (n - 1) - i;
        if( margin >= 0 )
        {
            vector<int> v;
            v.push_back(i);
            dive( v, n-1, margin );
        }
    }
}

void output()
{
    cout << x.size() << endl;
    REP(i,x.size())
    {
        REP(j,n)
        {
            if( j == n-1 )
            {
                cout << x[i][j] << endl;
            }
            else
            {
                cout << x[i][j] << " ";
            }
        }
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

