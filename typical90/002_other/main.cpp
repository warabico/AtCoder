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

/* methods ********************************************************************/
void input()
{
    cin >> n;
}

bool check(string s)
{
    int depth = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if( s[i] == '(' )
        {
            depth++;
        }
        if( s[i] == ')' )
        {
            depth--;
        }
        if( depth < 0 )
        {
            return false;
        }
    }
    if( depth == 0 )
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve()
{
    for( int i = 0; i < ( 0x01 << n ); i++ )
    {
        string candidate = "";
        for( int j = n - 1; j >= 0; j-- )
        {
            if( (i & ( 0x01 << j )) == 0 )
            {
                candidate += "(";
            }
            else
            {
                candidate += ")";
            }
        }
        bool check_result = check(candidate);
        if( check_result )
        {
            cout << candidate << endl;
        }
    }
}

void output()
{
    
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

