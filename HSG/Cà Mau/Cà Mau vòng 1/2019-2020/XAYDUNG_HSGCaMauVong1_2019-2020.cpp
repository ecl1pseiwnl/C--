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

const int N = 1e5 + 7;
int n, m, par[N], d[N];
vector<pi> v[N];
bool used[N];

void inp() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, w, z;
        cin >> x >> y >> w >> z;
        int temp = z - w;
        v[x].pb({ y,temp });
        v[y].pb({ x,temp });
    }
    memset(used, false, sizeof(used));
    for (int i = 1; i <= n; i++) {
        d[i] = INT_MIN;
    }
}

void PRIM(int u) {
    priority_queue<pi, vector<pi>> q;
    int res = 0;
    q.push({ 0,u });
    while (!q.empty()) {
        pi top = q.top();
        q.pop();
        int vert = top.second, leng = top.first;
        if (used[vert]) continue;
        res += leng;
        used[vert] = true;
        for (auto it : v[vert]) {
            int x = it.first, y = it.second;
            if (!used[x] && y > d[x]) {
                q.push({ y,x });
                d[x] = y;
                par[x] = vert;
            }
        }
    }
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    inp();
    PRIM(1);
    return 0;
}
