/* includes *******************************************************************/
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

/* namespaces *****************************************************************/
using namespace std;

/* Type Definitions ***********************************************************/
using ll   = long long;
using ull  = unsigned long long;
using vll  = vector<ll>;
using vs   = vector<string>;
using vvll = vector<vector<ll>>;
using vvs  = vector<vector<string>>;

/* Macro Definitions **********************************************************/
#define rep(i,n) for(ll i=0; i<n; i++)
#define range(i,a,b) for(ll i=a; i<=b; i++)
#define step(i,a,b,c) for(ll i=a; i<=b; i+=c)

/* Const Definitions **********************************************************/
const string YES = "YES";
const string NO  = "NO";
const string Yes = "Yes";
const string No  = "No";

const ll MOD = 1000000007;
const ll INF = 1001001001;
const double PI = 3.14159265358979323846;

/* Class Definition ***********************************************************/
class Solver {
    private:
        /* String Stream ******************************************************/
        stringstream ss;
        stringstream debug;

        /* User Dedfined Variables ========================================== */
        ll n;
        string s;
        vvll dp;
        /* ================================================================== */

        /* Common Functions */
        void input();
        void solve();
        void output();

        /* User Dedfined Functions ========================================== */
        /* ================================================================== */

    public:
        /* Common Functions */
        void run();

        /* Libraries */
        template <typename T> void cin_v(vector<T>& v, ll size);
        template <typename T> void cin_vv(vector<vector<T>>& v, ll rows, ll cols);
        template <typename T> void chmax(T& a, T b);
        template <typename T> void chmin(T& a, T b);
};

/* Methods ================================================================== */
void Solver::input()
{
    cin >> n;
    cin >> s;
    dp.assign(n+1,vll(8,0));
}

// #define DEBUG
void Solver::solve()
{
    dp[0][0] = 1;
    rep(i,n) {
        range(j,0,7) {
            dp[i+1][j] += dp[i][j];
            if( s[i] == 'a' && j == 0 ) dp[i+1][j+1] += dp[i][j];
            if( s[i] == 't' && j == 1 ) dp[i+1][j+1] += dp[i][j];
            if( s[i] == 'c' && j == 2 ) dp[i+1][j+1] += dp[i][j];
            if( s[i] == 'o' && j == 3 ) dp[i+1][j+1] += dp[i][j];
            if( s[i] == 'd' && j == 4 ) dp[i+1][j+1] += dp[i][j];
            if( s[i] == 'e' && j == 5 ) dp[i+1][j+1] += dp[i][j];
            if( s[i] == 'r' && j == 6 ) dp[i+1][j+1] += dp[i][j];
        }
        range(j,0,7) {
            dp[i+1][j] %= MOD;
        }
    }
    ss << dp[n][7] << endl;
}
/* ========================================================================== */

/* Common Methods and Libraries ***********************************************/
void Solver::run()
{
    input();
    solve();
    output();
}

void Solver::output()
{
#ifdef DEBUG
    cout << "* DEBUG ********************************" << endl;
    cout << debug.str();
    cout << "* DEBUG ********************************" << endl;
#endif
    cout << ss.str();
}

template <typename T>
void Solver::cin_v(vector<T>& v, ll size)
{
    v.assign(size, T{});
    for( ll i = 0; i < size; i++ )
    {
        cin >> v[i];
    }
}

template <typename T>
void Solver::cin_vv(vector<vector<T>>& v, ll rows, ll cols)
{
    v.assign(rows, vector<T>(cols, T{}));
    for( ll i = 0; i < rows; i++ )
    {
        for( ll j = 0; j < cols; j++ )
        {
            cin >> v[i][j];
        }
    }
}

template <typename T>
void Solver::chmax(T& a, T b) {
    if( a < b ) {
        a = b;
    }
}

template <typename T>
void Solver::chmin(T& a, T b) {
    if( a > b ) {
        a = b;
    }
}

/* main ***********************************************************************/
int main()
{
    Solver solver;
    solver.run();
    return 0;
}
