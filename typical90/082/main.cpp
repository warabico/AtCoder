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
        ull l,r;
        vector<ull> power10;
        ll answer;
        /* ================================================================== */

        /* Common Functions */
        void input();
        void solve();
        void output();

        /* User Dedfined Functions ========================================== */
        ll partialSum(ll n);
        ll div(ll a, ll b, ll m);
        ll modpow(ll a, ll b, ll m);
        ll modinv(ll a, ll m);
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
    cin >> l >> r;
    power10.assign(20, 1);
    range(i,1,19) {
        power10[i] = power10[i-1] * (ull)10;
    }
    answer = 0;
}

// #define DEBUG
void Solver::solve()
{
    range(i,1,19) {
        ll vl = max(l, power10[i-1]);
        ll vr = min(r, power10[i] - (ull)1);
        if( vl > vr ) continue;
        ll val = (partialSum(vr) - partialSum(vl-1) + MOD) % MOD;
        answer += (ll)1 * i * val;
        answer %= MOD;
    }
    ss << answer << endl;
}

ll Solver::partialSum(ll n) {
    ull v1 = n % MOD;
    ull v2 = (n+1) % MOD;
    ull v  = v1 * v2 % MOD;
    return div(v,2,MOD);
}

ll Solver::div(ll a, ll b, ll m) {
    // mod p の世界における割り算
    // Fermat’s Little Theorem (フェルマーの小定理)
    return ( a * modinv(b, m) ) % m;
}

ll Solver::modpow(ll a, ll b, ll m) {
    // Exponentiation by Squaring (繰り返し二乗法)
    ll p = 1;
    ll q = a;
    rep(i, 30) {
        if( ( b & ((ll)1 << i) ) != 0 ) {
            p *= q;
            p %= m;
        }
        q *= q;
        q %= m;
    }
    return p;
}

ll Solver::modinv(ll a, ll m) {
    // Modular Multiplicative Inverse (逆元)
    // Extended Euclidean Algorithm (拡張ユークリッドの互除法)
    ll b = m;
    ll u = 1;
    ll v = 0;
    while(b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if( u < 0 ) u += m;
    return u;
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
