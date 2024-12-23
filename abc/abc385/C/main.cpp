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
vector<int> h;
int answer;

/* methods ********************************************************************/
void input()
{
    int hi;
    cin >> n;
    REP(i, n)
    {
        cin >> hi;
        h.push_back(hi);
    }
}

void solve()
{
    answer = 1;
    for(int i=1; i<n; i++)          // distance
    {
        for(int j=0; j<i; j++)      // start position
        {
            int height = -1;
            int temp = 1;
            for(int k=j; k<n; k+=i)  // search
            {
                if( h[k] == height )
                {
                    temp++;
                }
                else
                {
                    height = h[k];
                    temp = 1;
                }
                if( temp > answer )
                {
                    answer = temp;
                }
            }
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

