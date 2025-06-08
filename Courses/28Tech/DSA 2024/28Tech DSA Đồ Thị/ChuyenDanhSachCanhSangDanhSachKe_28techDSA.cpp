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
int n, m, a[N][N];
vi v[N];
bool visit[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
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
