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
        ll n, w;
        ll q;
        vector<set<pair<ll,ll>>> blocks;
        vector<ll> deleteTime;


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
    cin >> n >> w;
    blocks.assign(w+1, set<pair<ll,ll>>());
    rep(i,n) {
        ll x, y;
        cin >> x >> y;
        blocks[x].insert({y,i+1});
    }
    cin >> q;
}

void Solver::solve()
{
    deleteTime.assign(n+1,1001001000);
    bool search = true;
    ll time = 0;
    rep(i,1001001000) {
        ll max = 1;
        vll deleteBlocks;

        for(ll j=1; j<=w; j++) {
            if( blocks[j].empty() ) {
                search = false;
                break;
            } else {
                ll y = blocks[j].begin()->first;
                deleteBlocks.push_back(blocks[j].begin()->second);
                chmax(max,y);
                blocks[j].erase(blocks[j].begin());
            }
        }

        if( search == false ) {
            break;
        } else {
            if( time < max ) {
                time = max;
            } else {
                time = time + 1;
            }
            for(ll idx: deleteBlocks) {
                deleteTime[idx] = time;
            }
        }
    }

    vs ans(q,"");
    rep(i,q) {
        ll t, a;
        cin >> t >> a;
        if( deleteTime[a] > t ) {
            ans[i] = Yes;
        } else {
            ans[i] = No;
        }
    }

    for(string s: ans) {
        ss << s << endl;
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
