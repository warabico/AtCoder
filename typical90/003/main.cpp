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
        vll a,b;
        vvll graph;
        vll costs;
        /* ================================================================== */

        /* Common Functions */
        void input();
        void solve();
        void output();

        /* User Dedfined Functions ========================================== */
        void bfs(ll start);
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
    a.assign(n-1,0);
    b.assign(n-1,0);
    graph.assign(n+1, vll());
    rep(i,n-1) {
        cin >> a[i] >> b[i];
        graph[a[i]].push_back(b[i]);
        graph[b[i]].push_back(a[i]);
    }
}

// #define DEBUG
void Solver::solve()
{
    // 1st search from the first node
    bfs(1);
    ll max_cost = -1;
    ll max_id = -1;
    range(i,1,n) {
        if( max_cost < costs[i] ) {
            max_cost = costs[i];
            max_id = i;
        }
    }

    // 2nd search from the farest point
    bfs(max_id);
    ll ans = -1;
    range(i,1,n) {
        chmax(ans, costs[i]);
    }

    ss << ans + 1 << endl;
}

void Solver::bfs(ll start)
{
    costs.assign(n+1,INF);

    queue<ll> q;
    q.push(start);
    costs[start] = 0;

    while(!q.empty()) {
        ll node = q.front();
        q.pop();
        for( ll dst: graph[node] ) {
            if( costs[dst] == INF ) {
                costs[dst] = costs[node] + 1;
                q.push(dst);
            }
        }
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
