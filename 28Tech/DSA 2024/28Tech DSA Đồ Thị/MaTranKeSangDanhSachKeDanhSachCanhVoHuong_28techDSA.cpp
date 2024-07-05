#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef map<int, int> mii;
#define mp make_pair
#define pb push_back
#define endl "\n"
#define MOD 10000007

const int N = 1005;
int n, a[N][N];
vi v[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] && i > j) {
                cout << i << " " << j << endl;
                v[i].pb(j);
                v[j].pb(i);
            }
        }
    }
    cout << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << " : ";
        for (auto it : v[i]) {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}
