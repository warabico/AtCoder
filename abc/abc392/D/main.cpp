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
        int n;
        vll ks;
        vector<map<ll,ll>> dices;

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
    cin >> n;
    rep(i, n) {
        ll k;
        cin >> k;
        ks.push_back(k);
        dices.push_back(map<ll,ll>());
        rep(j,k) {
            ll a;
            cin >> a;
            if( dices[i].find(a) != dices[i].end() ) {
                dices[i][a]++;
            } else {
                dices[i][a] = 1;
            }
        }
    }
}

void Solver::solve()
{
    long double result = 0.0;
    rep(i,n) {
        for( ll j=i+1; j<n; j++ ) {
            ll sum = 0;
            long double temp = 0.0;
            if( dices[i].size() > dices[j].size() ) {
                for( auto [key, val] : dices[i] ) {
                    if( dices[j].find(key) != dices[j].end() ) {
                        sum += dices[i][key] * dices[j][key];
                    }
                }
            } else {
                for( auto [key, val] : dices[j] ) {
                    if( dices[i].find(key) != dices[i].end() ) {
                        sum += dices[i][key] * dices[j][key];
                    }
                }
            }
            temp = (long double)sum / ( (long double)(ks[i] * ks[j]) );
            chmax(result, temp);
        }
    }
    ss << fixed << setprecision(30) << result << endl;
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
