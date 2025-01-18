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
        int h, w, p, q;
        ll x;

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
};

/* Methods ================================================================== */
void Solver::input()
{
    cin >> h >> w >> x;
    cin >> p >> q;
}

void Solver::solve()
{
    vector<vector<ll>> world(h+2, vector<ll>(w+2, 250000000000000000UL));
    for( int i=1; i<=h; i++ ) {
        for( int j=1; j<=w; j++ ) {
            cin >> world[i][j];
        }
    }

    ll myStrength = world[p][q];
    vector<vector<bool>> history(h+2, vector<bool>(w+2, false));

    using SLIME = tuple<ll, ll,ll>;
    priority_queue<SLIME, vector<SLIME>, greater<SLIME>> slimes;
    slimes.emplace(0, p, q);
    history[p][q] = true;

    vector<pair<int, int>> dir{{1,0}, {-1,0}, {0,1}, {0,-1}};

    while( !slimes.empty() ) {
        const auto [strength, i, j] = slimes.top();
        slimes.pop();

        if( strength >= ( ( myStrength + x - 1 ) / x ) ) {
            break;
        }

        myStrength += strength;

        for( const auto &[dx, dy] : dir ) {
            if( !history[i+dx][j+dy] ) {
                history[i+dx][j+dy] = true;
                slimes.emplace( world[i+dx][j+dy], i+dx, j+dy );
            }
        }
    }

    ss << myStrength << endl;
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
