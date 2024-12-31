/* includes *******************************************************************/
#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <utility>
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
typedef vector<ll> vll;
typedef vector<string> vs;

/* library definitions ********************************************************/
void input_vector(vi  *v, int size);
void input_vector(vll *v, int size);
void input_vector(vs  *v, int size);

/* variable definitions *******************************************************/
int n;
int a, b, c;
vi coins(3);
int result;

/* methods ********************************************************************/
void input()
{
    cin >> n;
    cin >> coins[0] >> coins[1] >> coins[2];
    sort(coins.begin(), coins.end());
    a = coins[2];
    b = coins[1];
    c = coins[0];
}

void solve()
{
    int temp_sum;
    int temp_left;
    int temp_result;
    int max_na;
    int max_nb;

    result = 10000;
    max_na = n / a;
    for( int i = max_na; i >= 0; i-- )
    {
        temp_sum  = a * i;
        temp_left = n - temp_sum;
        max_nb    = temp_left / b;
        for( int j = max_nb; j >= 0; j-- )
        {
            temp_sum  = a * i + b * j;
            temp_left = n - temp_sum;
            if( temp_left % c == 0 )
            {
                int k = temp_left / c;
                temp_result = i + j + k;

                if( temp_result < result )
                {
                    result = temp_result;
                }
            }
        }
    }
}

void output()
{
    cout << result << endl;
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
void input_vector(vi *v, int size)
{
    int element;
    for( int i = 0; i < size; i++ )
    {
        cin >> element;
        v->push_back(element);
    }
}

void input_vector(vll *v, int size)
{
    ll element;
    for( int i = 0; i < size; i++ )
    {
        cin >> element;
        v->push_back(element);
    }
}

void input_vector(vs *v, int size)
{
    string element;
    for( int i = 0; i < size; i++ )
    {
        cin >> element;
        v->push_back(element);
    }
}
