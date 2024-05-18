#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> si;
typedef map<int, int> mii;
#define MOD 1000000007
#define endl "\n"
#define mp make_pair
#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    while(q--) {
        int a, b;
        cin >> a >> b;
        if ((a == 1 && b == 2) || (a == 2 && b == 1)) {
            cout << "YES\n";
        }
        else if (a % 2 == 1 && b % 2 == 1) {
            if (a == 1 && b == 1) {
                cout << "NO\n";
            }
            cout << "YES\n";
        } else if ((a % 2 == 0 && b % 2 == 1) || (a % 2 == 1 && b % 2 == 0)) {
            if ((a > b && a % b == 0) || (a < b && b % a == 0)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else if (a % 2 == 0 && b % 2 == 0) cout << "NO\n";
    }
    return 0;
}
