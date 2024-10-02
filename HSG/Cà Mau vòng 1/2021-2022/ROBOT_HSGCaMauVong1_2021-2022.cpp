#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<mii> viii;
#define ms(a,n) memset(a, n,sizeof(a))
#define all(x) (x).begin(),(x).end
#define ins insert
#define sz(x) (int)(x.size())
#define name "TASK"
#define fi first
#define sec second
#define mp make_pair
#define pb push_back
#define endl "\n"
const int MOD = 1e9+7;
const int INF_INT = 2e9;
const ll INF_LL = 2e18;

const int N = 1e3+5;
int n, m, a[N][N],d[N][N], dx[] = {1,0,1}, dy[] = {0,1,1};

void bfs() {
    ms(visited,0);
    queue<pair<int,int>> q;
    d[1][1] = a[1][1];
    visited[1][1] = 1;
    q.push({1,1});
    while(!q.empty()) {
        auto [x,y] = q.front(); q.pop();
        if (x == n && y == m) return;
        for (int i = 0; i < 3; i++) {
            int nx = dx[i] + x, ny = dy[i] + y;
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !visited[nx][ny] &&a[nx][ny] != -1) {
                d[nx][ny] = d[x][y] + a[nx][ny];
                visited[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
    }
}


signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    bfs();
    cout << d[n][m];
    return 0;
}
