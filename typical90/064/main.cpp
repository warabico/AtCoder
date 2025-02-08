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
#define rep(i,n) for(ll i=0; i<n; i++)

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
        int n, q;
        vll a;
        vll e;

        /* User Dedfined Variables ========================================== */
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
    cin >> n >> q;
    a.assign(n, 0);
    e.assign(n-1, 0);
    rep(i,n) {
        cin >> a[i];
        if( i > 0 ) {
            e[i-1] = a[i-1] - a[i];
        }
    }
}

void Solver::solve()
{
    ll esum = 0;
    rep(i,n-1) {
        esum += abs(e[i]);
    }
    rep(i,q) {
        ll l, r, v;
        cin >> l >> r >> v;
        l--;
        r--;

        if( l > 0 ) {
            ll temp = e[l-1] - v;
            esum -= abs(e[l-1]) - abs(temp);
            e[l-1] = temp;
        }
        if( r <= n-2 ) {
            ll temp = e[r] + v;
            esum -= abs(e[r]) - abs(temp);
            e[r] = temp;
        }
        ss << esum << endl;
    }
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
    v.assign(size, T{});
    for( int i = 0; i < size; i++ )
    {
        cin >> v[i];
    }
}

template <typename T>
void Solver::cin_vv(vector<vector<T>>& v, int rows, int cols)
{
    v.assign(rows, vector<T>(cols, T{}));
    for( int i = 0; i < rows; i++ )
    {
        for( int j = 0; j < cols; j++ )
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
