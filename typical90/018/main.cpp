/* includes *******************************************************************/
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

/* namespaces *****************************************************************/
using namespace std;

/* macro definitions **********************************************************/
#define YES        "YES"
#define NO         "NO"
#define Yes        "Yes"
#define No         "No"

#define PI         ((double)3.141592653589793)

/* type definitions ***********************************************************/
typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;

/* library definitions ********************************************************/
void input_vector(vi  *v, int size);
void input_vector(vll *v, int size);
void input_vector(vs  *v, int size);

/* variable definitions *******************************************************/
double t;
double l, x, y;
double r;
int q;
vi e;

/* methods ********************************************************************/
void input()
{
    cin >> t;
    cin >> l >> x >> y;
    cin >> q;
    input_vector(&e, q);
}

void solve()
{
    double ferris_wheel_angle_rad;
    double px, py, pz;
    double horizontal_distance;
    double angle;

    // Calculate radius or ferris wheel
    r = l / (double)2.0;

    for( int i = 0; i < q; i++ )
    {
        // Calculate angle of ferris wheel at time e[i]
        ferris_wheel_angle_rad = e[i] * (double)2.0 * PI / t;

        // Calculate coordinates of E869210-kun
        px = (double)0.0;
        py = (double)-1.0 * r * sin(ferris_wheel_angle_rad);
        pz = r - r * cos(ferris_wheel_angle_rad);

        // Calculate horizontal distance between the statue and E869210-kun
        horizontal_distance = sqrt((x - px) * (x - px) + (y - py) * (y - py));

        // Calculate and output the angle
        angle = atan2( pz, horizontal_distance ) * (double)180.0 / PI;
        cout << fixed << setprecision(16) << angle << endl;
    }
}

void output()
{
    
}

/* main ***********************************************************************/
int main()
{
    input();
    solve();
    output();
    return 0;
}

/* libraries ******************************************************************/
void input_vector(vi *v, int size)
{
    int element;
    for( int i = 0; i < size; i++ )
    {
        cin >> element;
        v->push_back(element);
    }
}

void input_vector(vll *v, int size)
{
    ll element;
    for( int i = 0; i < size; i++ )
    {
        cin >> element;
        v->push_back(element);
    }
}

void input_vector(vs *v, int size)
{
    string element;
    for( int i = 0; i < size; i++ )
    {
        cin >> element;
        v->push_back(element);
    }
}
