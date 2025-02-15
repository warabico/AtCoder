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
        ll n, m;
        vector<set<ll>> graph;
        ll ans;
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
    cin >> n >> m;
}

// #define DEBUG
void Solver::solve()
{
    ans = 0;
    graph.assign(n+1,set<ll>());
    rep(i,m) {
        ll v1, v2;
        cin >> v1 >> v2;
        if( v1 == v2 ) {
            ans++;
        }
        else {
            if( v1 < v2 ) {
                if( graph[v1].find(v2) == graph[v1].end() ) {
                    graph[v1].emplace(v2);
                }
                else {
                    ans++;
                }
            }
            else {
                if( graph[v2].find(v1) == graph[v2].end() ) {
                    graph[v2].emplace(v1);
                }
                else {
                    ans++;
                }
            }
        }
    }
    ss << ans << endl;
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
