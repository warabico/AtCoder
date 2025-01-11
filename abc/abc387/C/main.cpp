/* includes *******************************************************************/
#include <algorithm>
#include <cmath>
#include <iomanip>
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

#define PI         ((double)3.14159265358979323846)

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
ll l, r;
ll cnt[10][29] = {{0}};
ll cnt_sum[10][29] = {{0}};

ll cnt_l = 0;
ll cnt_r = 0;
ll offset = 1;

/* methods ********************************************************************/
void input()
{
    cin >> l >> r;
}

ll int_pow(ll a, ll t)
{
    ll res = 1;
    for(int i=0;i<t;i++)
    {
        res *= a;
    }
    return res;
}

ll count(ll r)
{
    vi digits;
    while(r) {
        digits.push_back(r%10);
        r /= 10;
    }
    reverse(digits.begin(), digits.end());

    int n = digits.size();
    ll res = 0;

    // 最上位の桁を固定したままの検証
    for(int i=1; i<=n; i++)
    {
        if(i==n){
            // 元の数がヘビ数だった
            res++;
            break;
        }
        // 最上位の桁が固定なのでそれを考慮してi桁目の数と最上位桁の数のうち最小のものに制約を受ける
        res += int_pow(digits[0], n-1-i) * min(digits[0], digits[i]);
        if(digits[i] >= digits[0]) break;
    }

    // 最上位の桁を条件から外した検証
    for(int i=0; i<n; i++)
    {
        // n桁の数の場合のみ最上位桁を考慮し、それ以下であれば1〜9で考える
        int mx = (i ? 9: digits[0]-1);
        for(int j=1; j <= mx; j++)
        {
            res += int_pow(j, n-1-i);
        }
    }

    return res;
}

void solve()
{
    cnt_r = count(r);
    cnt_l = count(l-1);
}

void output()
{
    cout << cnt_r - cnt_l << endl;
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
