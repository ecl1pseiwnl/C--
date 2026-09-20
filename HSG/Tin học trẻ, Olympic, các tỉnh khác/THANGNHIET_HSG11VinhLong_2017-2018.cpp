#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> si;
typedef map<int, int> mii;
#define MOD 10000000007
#define endl "\n";
#define mp make_pair
#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    double t;
    char x, y;
    cin >> x >> t >> y;
    if (x == 'C') {
        if (y == 'F') {
            cout << fixed << setprecision(2) << (1.8 * t) + 32;
        }
        else if (y == 'K') {
            double temp = (1.8 * t) + 32;
            cout << fixed << setprecision(2) << (temp + 459.67) / 1.8;
        }
    }
    else if (x == 'F') {
        if (y == 'C') {
            cout << fixed << setprecision(2) << (t - 32) / 1.8;
        }
        else if (y == 'K') {
            cout << fixed << setprecision(2) << (t + 459.67) / 1.8;
        }
    }
    else {
        if (y == 'C') {
            double temp = (t - 273.15) * 1.8 + 32;
            cout << fixed << setprecision(2) << (temp - 32) / 1.8;
        }
    }
    return 0;
}