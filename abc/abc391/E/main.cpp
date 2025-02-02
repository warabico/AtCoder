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
#define rep(i,n) for(ll i=0; i<(ll)(n); i++)

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
        ll n;
        string s;

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
        ll power(ll base, unsigned int exponent);
        int popcount(int value);
};

/* Methods ================================================================== */
void Solver::input()
{
    cin >> n;
    cin >> s;

}

void Solver::solve()
{
    vvi dp(s.size(), vi(2,1));

    rep(i,s.size()) {
        dp[i][s[i]-'0'] = 0;
    }

    const int INF = 1001001001;
    while(dp.size() > 1) {
        // Reduce the dp tree to one-third of its original size.
        vvi old(dp.size()/3, vi(2,INF));
        swap(dp,old);

        // Calculate conversion costs.
        for(ll l=0; l<old.size(); l+=3) {
            // l represents the start index of three votes.
            rep(s,8) {
                // Check 0b000 to 0b111
                int cost = 0;
                rep(i,3) {
                    cost += old[l+i][(s>>i)&1];
                }
                int x = ( popcount(s) >= 2 ? 1 : 0 );
                chmin(dp[l/3][x], cost);
            }
        }
    }

    ss << max(dp[0][0], dp[0][1]) << endl;
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

ll Solver::power(ll base, unsigned int exponent) {
    ll result = 1;
    rep(i, exponent) {
        result *= base;
    }
    return result;
}

int Solver::popcount(int value) {
    int ones = 0;

    while( value != 0 ) {
        if( value & 1 ) {
            ones++;
        }
        value = value >> 1;
    }
    
    return ones;
}

/* main ***********************************************************************/
int main()
{
    Solver solver;
    solver.run();
    return 0;
}
