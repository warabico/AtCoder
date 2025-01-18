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
        ll n;

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
    cin >> n;
}

void Solver::solve()
{
    ll ans = 0;

    ll m = 1;
    while( m*m <= n ) { m++; }
    m--;

    vll primes;
    vector<bool> isprime(m, true);
    isprime[0] = false;
    isprime[1] = false;
    for( ll i=2; i<m; i++ ) {
        if( isprime[i] ) {
            primes.push_back(i);
            for( ll j=i*2; j<m; j+=i ) {
                isprime[j] = false;
            }
        }
    }

    for( ll p: primes ) {
        if( p*p*p*p > n ) {
            break;
        }

        if( p < 100 ) {
            if( p*p*p*p*p*p*p*p <= n ) {
                ans++;
            }
        }
        for( ll q: primes ) {
            if( q <= p ) {
                continue;
            }

            if( p*p*q*q <= n ) {
                ans++;
            } else {
                break;
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
