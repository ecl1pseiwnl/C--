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

const int N = 1005;
int n, m;
vi v[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
    }
    for (int i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end());
    }
    for (int i = 1; i <= n; i++) {
        cout << i << " : ";
        for (auto it : v[i]) {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}
