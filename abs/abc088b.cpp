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
int alice;
int bob;
vector<int> a;
vector<int> A;

/* methods ********************************************************************/
void input()
{
    int ai;

    cin >> n;
    REP(i, n)
    {
        cin >> ai;
        a.push_back(ai);
    }
}

vector<int> quicksort(vector<int> v)
{
    int pivot;
    vector<int> left;
    vector<int> right;
    vector<int> LEFT;
    vector<int> RIGHT;
    vector<int> sorted;

    if( v.size() <= 1 )
    {
        return v;
    }
    else
    {
        pivot = v.at(0);
        for(int i = 1; i < v.size(); i++)
        {
            if( v.at(i) >= pivot )
            {
                left.push_back(v.at(i));
            }
            else
            {
                right.push_back(v.at(i));
            }
        }
        LEFT  = quicksort(left);
        RIGHT = quicksort(right);
        sorted.insert(sorted.end(), LEFT.begin(), LEFT.end());
        sorted.push_back(pivot);
        sorted.insert(sorted.end(), RIGHT.begin(), RIGHT.end());
    }
    return sorted;
}

void solve()
{
    A = quicksort(a);
    REP(i, n)
    {
        if(i % 2 == 0)
        {
            alice += A[i];
        }
        else
        {
            bob += A[i];
        }
    }
}

void output()
{
    cout << (alice - bob) << endl;
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

