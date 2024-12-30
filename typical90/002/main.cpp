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
int n;
vs result;

/* methods ********************************************************************/
void input()
{
    cin >> n;
}

vs parentheses(int left, int right, int depth, string base)
{
    vs temp;

    for( int i = left; i > 0; i-- )
    {
        int new_left;
        int new_depth;
        new_left  = left;
        new_depth = depth;

        string new_item;
        new_item += base;

        // add left parenthesis preferentially
        for( int j = 0; j < i; j++ )
        {
            new_item += "(";
            new_left--;
            new_depth++;
        }

        // check if it should be completely closed
        if( new_left == 0 )
        {
            for( int j = 0; j < right; j++ )
            {
                new_item += ")";
            }
            temp.push_back(new_item);
        }
        else
        {
            // if there is one or more room for left parenthesis, put right paraenthesis as little as possible
            for( int j = 1; j <= new_depth; j++ )
            {
                int new_right;
                int new_new_depth;
                new_right = right;
                new_new_depth = new_depth;

                string new_base;
                new_base += new_item;
                for( int k = 0; k < j; k++ )
                {
                    new_base += ")";
                    new_right--;
                    new_new_depth--;
                }

                // begin new search
                vs temp_add;
                temp_add = parentheses( new_left, new_right, new_new_depth, new_base );
                temp.insert(temp.end(), temp_add.begin(), temp_add.end());
            }
        }
    }
    return temp;
}

void solve()
{
    if( n % 2 != 0 )
    {
        return;
    }

    result = parentheses( n/2, n/2, 0, "" );
}

void output()
{
    REP(i, result.size())
    {
        cout << result[i-1] << endl;
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

