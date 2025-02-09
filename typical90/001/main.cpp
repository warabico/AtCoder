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
        ll n,l;
        ll k;
        vll a;
        ll sum;
        ll ans;
        /* ================================================================== */

        /* Common Functions */
        void input();
        void solve();
        void output();

        /* User Dedfined Functions ========================================== */
        bool check(ll m);
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
    cin >> n >> l;
    cin >> k;
    a.assign(n+2,0);
    range(i,1,n) {
        cin >> a[i];
    }
    a[n+1] = l;
}

// #define DEBUG
void Solver::solve()
{
#if 0
    ll left = 0;
    ll right = l;
    ll offset = l / 2;
    ans = 0;
    while( left < right ) {
        debug << offset << "\t[ " << left << ",\t" << right << " ]\t";
        ans = left + offset;
        if( check(ans) ) {
            left += offset;
        } else {
            ans--;
            right = ans;
        }
        offset = max((ll)1, offset / 2);
    }
#else
    // めぐる式二分探索法
    ll left = -1;
    ll right = l + 1;
    while( right - left > 1 ) {
        ll mid = left + ( right - left ) / 2;
        if( check(mid) ) {
            left = mid;
        } else {
            right = mid;
        }
    }
    ans = left;
#endif
    ss << ans << endl;
}

bool Solver::check(ll m) {
    ll temp_sum = 0;
    ll remain = l;
    ll cut_num = 0;
    debug << " >> ";
    range(i,1,n+1) {
        temp_sum += a[i] - a[i-1];
        remain -= a[i] - a[i-1];
        if( temp_sum >= m ) {
            debug << temp_sum << ", ";
            temp_sum = 0;
            cut_num++;
            if( cut_num == k ) {
                if( remain >= m ) {
                    debug << "ok" << endl;
                    return true;
                } else {
                    debug << "ng" << endl;
                    return false;
                }
            }
        }
    }
    debug << "ng" << endl;
    return false;
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
