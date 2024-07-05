#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<mii> viii;
#define ms(a,n) memset(a, n,sizeof(a))
#define name "TASK"
#define fi first
#define sec second
#define mp make_pair
#define pb push_back
#define endl "\n"
#define MOD 10000007

const int N = 105;
int d[N][N], dx[] = {2,1,2,1,-2,-1}, dy[] = {1,2,-1,-2,1,2};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int r,c,gr,gc,lr,lc;
    cin >> r >> c >> gr >> gc >> lr >> lc;
    ms(d,0);
    queue<pair<int,int>> q;
    q.push({gr,gc});
    d[gr][gc] = 0;
    while (!q.empty()) {
        auto it = q.front(); q.pop();
        auto x = it.fi, y = it.sec;
        for (int i = 0; i < 6; i++) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if (nx >= 1 && nx <= r && ny >= 1 && ny <= c && d[nx][ny] == 0) {
                d[nx][ny] = d[x][y] + 1;
                q.push({nx,ny});
            }
        }
    }
    if (d[lr][lc] == 0) {
        cout << "impossible";
    }
    else cout << d[lr][lc];
    return 0;
}
