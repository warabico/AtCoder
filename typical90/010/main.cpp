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
#define FOR(i,a,b) for(long long (i)=(a); (i)<=b; (i)++)
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
int n;
int p1[100001];
int p2[100001];
int q;
int lr[100001][2];

int sum1[100001];
int sum2[100001];

/* methods ********************************************************************/
void input()
{
    int ci;

    cin >> n;
    REP(i, n)
    {
        cin >> ci;
        if( ci == 1 )
        {
            cin >> p1[i];
        }
        else
        {
            cin >> p2[i];
        }

        sum1[i] = sum1[i - 1] + p1[i];
        sum2[i] = sum2[i - 1] + p2[i];
    }
    cin >> q;
    REP(i, q)
    {
        cin >> lr[i][0] >> lr[i][1];
    }
}

void solve()
{

}

void output()
{
    int l;
    int r;

    REP(i, q)
    {
        l = lr[i][0];
        r = lr[i][1];

        cout << sum1[r] - sum1[l-1] << " " << sum2[r] - sum2[l-1] << endl;
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

