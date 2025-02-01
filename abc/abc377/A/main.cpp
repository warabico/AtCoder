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
        string s;
        vi counts;

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
    cin >> s;
}

void Solver::solve()
{
    counts.assign(3,0);
    rep(i,s.size()) {
        if( s[i] == 'A' ) counts[0]++;
        if( s[i] == 'B' ) counts[1]++;
        if( s[i] == 'C' ) counts[2]++;
    }

    if( ( counts[0] == 1 ) &&
        ( counts[1] == 1 ) &&
        ( counts[2] == 1 ) )
    {
        ss << Yes << endl;
    }
    else
    {
        ss << No << endl;
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
