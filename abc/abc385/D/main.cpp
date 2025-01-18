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
        ll n, m;
        ll sx, sy;
        using D = map<ll, set<ll>>;
        D xs, ys;

        ll ans;

        /* User Dedfined Variables ========================================== */
        /* ================================================================== */

        /* Common Functions */
        void input();
        void solve();
        void output();

        /* User Dedfined Functions ========================================== */
        void present(D& xs, D& ys, ll y, ll l, ll r);
        /* ================================================================== */

    public:
        /* Common Functions */
        void run();

        /* Libraries */
        template <typename T> void cin_v(vector<T>& v, int size);
        template <typename T> void cin_vv(vector<vector<T>>& v, int rows, int cols);
};

/* Methods ================================================================== */
void Solver::input()
{
    cin >> n >> m >> sx >> sy;
    for( int i = 0; i < n; i++ )
    {
        ll x, y;
        cin >> x >> y;
        xs[y].insert(x);
        ys[x].insert(y);
    }
}

void Solver::solve()
{
    ans = 0;

    for( int i = 0; i < m; i++ )
    {
        char d;
        ll c;
        cin >> d >> c;
        ll nx = sx, ny = sy;

        if( d == 'U' ) { ny += c; }
        if( d == 'D' ) { ny -= c; }
        if( d == 'R' ) { nx += c; }
        if( d == 'L' ) { nx -= c; }

        if( sy == ny ) {
            present(xs, ys, sy, sx, nx);
        } else {
            present(ys, xs, sx, sy, ny);
        }

        sx = nx; sy = ny;
    }

    ss << sx << " " << sy << " " << ans << endl;
}

void Solver::present(D& xs, D& ys, ll y, ll l, ll r)
{
    if(l > r) { swap(l,r); }

    auto& st = xs[y];
    auto it = st.lower_bound(l);
    while(it != st.end() && *it <= r) {
        ys[*it].erase(y);
        it = st.erase(it);
        ans++;
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

/* main ***********************************************************************/
int main()
{
    Solver solver;
    solver.run();
    return 0;
}
