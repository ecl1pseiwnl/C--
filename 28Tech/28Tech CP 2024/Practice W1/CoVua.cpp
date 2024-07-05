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
const int MOD = 1e7;
const int INF_INT = 2e9;
const ll INF_LL = 2e18;

const int N = 8;
int d[N+2][N+2], dx[]={2,2,1,1,-1,-1,-2,-2}, dy[]={1,-1,2,-2,-2,2,1,-1};

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        ms(d,-1);
        string st,en;
        cin >> st >> en;
        pair<int,int> s,t;
        s = {st[0] - 'a'+1,st[1]-'0'};
        t = {en[0] - 'a'+1,en[1]-'0'};
        queue<pair<int,int>> q;
        q.push(s);
        d[s.fi][s.sec] = 0;
        while(!q.empty()) {
            auto [x,y] = q.front(); q.pop();
            for (int i = 0; i < 8; i++) {
                int x1 = dx[i] + x, y1 = dy[i] + y;
                if (x1 >= 1 && x1 <= N && y1 >= 1 && y1 <= N && d[x1][y1] == -1) {
                    d[x1][y1] = d[x][y] + 1;
                    q.push({x1,y1});
                }
            }
        }
        if (d[t.fi][t.sec] == -1) {
            cout << "HETCUU\n";
            continue;
        } else cout << d[t.fi][t.sec] << "\n";
    }
    return 0;
}
