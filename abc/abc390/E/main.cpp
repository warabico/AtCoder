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
using vi   = vector<int>;
using vll  = vector<ll>;
using vs   = vector<string>;
using vvi  = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvs  = vector<vector<string>>;

/* Macro Definitions **********************************************************/
#define rep(i,n) for(ll i=0; i<(n); i++)

/* Const Definitions **********************************************************/
const string YES = "YES";
const string NO  = "NO";
const string Yes = "Yes";
const string No  = "No";

const double PI  = 3.14159265358979323846;

/* Class Definition ***********************************************************/
class Solver {
    private:
        /* String Stream ******************************************************/
        stringstream ss;
        int n, x;
        vector<vector<pair<ll,ll>>> foods;

        /* User Dedfined Variables ========================================== */
        bool judge(ll r, vector<vector<ll>> dps);
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
        template <typename T> void cin_v(vector<T>& v, int size);
        template <typename T> void cin_vv(vector<vector<T>>& v, int rows, int cols);
        template <typename T> void chmax(T& a, T b);
        template <typename T> void chmin(T& a, T b);
};
/* Methods ================================================================== */
void Solver::input()
{
    cin >> n >> x;
    foods.push_back({});
    foods.push_back({});
    foods.push_back({});
    rep(i,n) {
        ll v, a, c;
        cin >> v >> a >> c;
        v--;
        foods[v].emplace_back(a,c);
    }
}

void Solver::solve()
{
    vector<vector<ll>> dps(3, vector<ll>(x+1));
    rep(v,3) {
        vector<ll> dp(x+1);
        for( auto [a,c] : foods[v] ) {
            for(int i=x; i >= c; i--) {
                chmax(dp[i], dp[i-c]+a);
            }
        }
        dps[v] = dp;
    }

    ll ac = 0;
    ll wa = 1001001001;
    while( ac+1 < wa ) {
        ll wj = (ac+wa)/2;
        if( judge(wj, dps) ) {
            ac = wj;
        } else {
            wa = wj;
        }
    }
    ss << ac << endl;
}

bool Solver::judge(ll r, vector<vector<ll>> dps) {
    ll tot = 0;
    rep(v,3) {
        if( dps[v][x] < r ) return false;
        ll need = lower_bound(dps[v].begin(), dps[v].end(), r) - dps[v].begin();
        tot += need;
    }
    return tot <= x;
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
    cout << ss.str();
}

template <typename T>
void Solver::cin_v(vector<T>& v, int size)
{
    T element;
    for( int i = 0; i < size; i++ )
    {
        cin >> element;
        v.push_back(element);
    }
}

template <typename T>
void Solver::cin_vv(vector<vector<T>>& v, int rows, int cols)
{
    T element;
    for( int i = 0; i < rows; i++ )
    {
        v.push_back(vector<T>());
        for( int j = 0; j < cols; j++ )
        {
            cin >> element;
            v[i].push_back(element);
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
