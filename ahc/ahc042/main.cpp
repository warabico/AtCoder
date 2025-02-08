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

#include <fstream>

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
        ofstream ofs;
        ll n;
        vvi board;
        ll oni;
        ll ope;

        /* User Dedfined Variables ========================================== */
        /* ================================================================== */

        /* Common Functions */
        void input();
        void solve();
        void output();

        /* User Dedfined Functions ========================================== */
        bool moveL(int row);
        bool moveR(int row);
        bool moveU(int col);
        bool moveD(int col);
        bool incMoveCount();
        void flush(string d, int p);
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
    board.assign(n, vi(n,0));

    oni = 0;
    rep(i,n) {
        string s;
        cin >> s;
        rep(j,n) {
            if(s[j]=='x') {
                board[i][j] = -1;
                oni++;
            }
            if(s[j]=='o') {
                board[i][j] =  1;
            }
        }
    }
}

// #define DEBUG
void Solver::solve()
{
#ifdef DEBUG
    ofs.open("output.txt");
#endif

    ope = 0;
    bool next = true;
    int rangeCoef = 10;
    while( oni > 0 && rangeCoef > -100 )
    {
        next = false;
        int coef = max(1,rangeCoef);
        int range = n / coef;

        // Left
        rep(i,n) {
            int cnt = -1;
            rep(j,range) {
                if( board[i][j] == -1 ) { cnt = j; next = true; }
                if( board[i][j] == 1 ) break;
            }
            rep(j,cnt+1) {
                if( moveL(i) ) return;
            }
        }

        // Up
        rep(i,n) {
            int cnt = -1;
            rep(j,range) {
                if( board[j][i] == -1 ) { cnt = j; next = true; }
                if( board[j][i] == 1 ) break;
            }
            rep(j,cnt+1) {
                if( moveU(i) ) return;
            }
        }

        // Right
        rep(i,n) {
            int cnt = -1;
            rep(j,range) {
                if( board[i][n-1-j] == -1 ) { cnt = j; next = true; }
                if( board[i][n-1-j] == 1 ) break;
            }
            rep(j,cnt+1) {
                if( moveR(i) ) return;
            }
        }

        // Down
        rep(i,n) {
            int cnt = 0;
            rep(j,range) {
                if( board[n-1-j][i] == -1 ) { cnt = j; next = true; }
                if( board[n-1-j][i] == 1 ) break;
            }
            rep(j,cnt) {
                if( moveD(i) ) return;
            }
        }

        // Right
        rep(i,n) {
            int cnt = -1;
            rep(j,range) {
                if( board[i][n-1-j] == -1 ) { cnt = j; next = true; }
                if( board[i][n-1-j] == 1 ) break;
            }
            rep(j,cnt+1) {
                if( moveR(i) ) return;
            }
        }

        // Down
        rep(i,n) {
            int cnt = 0;
            rep(j,range) {
                if( board[n-1-j][i] == -1 ) { cnt = j; next = true; }
                if( board[n-1-j][i] == 1 ) break;
            }
            rep(j,cnt) {
                if( moveD(i) ) return;
            }
        }

        // Left
        rep(i,n) {
            int cnt = -1;
            rep(j,range) {
                if( board[i][j] == -1 ) { cnt = j; next = true; }
                if( board[i][j] == 1 ) break;
            }
            rep(j,cnt+1) {
                if( moveL(i) ) return;
            }
        }

        // Up
        rep(i,n) {
            int cnt = -1;
            rep(j,range) {
                if( board[j][i] == -1 ) { cnt = j; next = true; }
                if( board[j][i] == 1 ) break;
            }
            rep(j,cnt+1) {
                if( moveU(i) ) return;
            }
        }

        int y = 0;
        int x = 0;
        if( next == false && oni > 0 ) {
            rep(i,n) {
                rep(j,n) {
                    if( board[i][j] == -1 ) {
                        y = i;
                        x = j;
                    }
                }
            }
            if( board[y][0] != 1 ) {
                if( moveL(y) ) return;
            }
            else if( board[0][x] != 1 ) {
                if( moveU(x) ) return;
            }
            else if( board[y][n-1] != 1 ) {
                if( moveR(y) ) return;
            }
            else if( board[n-1][x] != 1 ) {
                if( moveD(x) ) return;
            }
        }

        rangeCoef--;
    }
}

bool Solver::moveL(int row) {
    flush("L",row);
    if( board[row][0] == -1 ) oni--;
    rep(k,n-1) {
        board[row][k] = board[row][k+1];
    }
    board[row][n-1] = 0;
    return incMoveCount();
}

bool Solver::moveR(int row) {
    flush("R",row);
    if( board[row][n-1] == -1 ) oni--;
    rep(k,n-1) {
        board[row][n-k-1] = board[row][n-k-2];
    }
    board[row][0] = 0;
    return incMoveCount();
}

bool Solver::moveU(int col) {
    flush("U",col);
    if( board[0][col] == -1 ) oni--;
    rep(k,n-1) {
        board[k][col] = board[k+1][col];
    }
    board[n-1][col] = 0;
    return incMoveCount();
}

bool Solver::moveD(int col) {
    flush("D",col);
    if( board[n-1][col] == -1 ) oni--;
    rep(k,n-1) {
        board[n-k-1][col] = board[n-k-2][col];
    }
    board[0][col] = 0;
    return incMoveCount();
}

bool Solver::incMoveCount() {
    ope++;
    if( ope >= 1600 ) {
        return true;
    } else {
        return false;
    }
}

void Solver::flush(string d, int p) {
    ss << d << " " << p << endl;
#ifdef DEBUG
    ofs << d << " " << p << endl;
#endif
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
