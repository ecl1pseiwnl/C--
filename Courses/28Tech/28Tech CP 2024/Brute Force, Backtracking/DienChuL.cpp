#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<mii> viii;
ll lcm(ll x, ll y) { return 1ll*(x / __gcd(x,y))*y;}
#define ms(a,n) memset(a, n,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define ins insert
#define sz(x) (int)(x.size())
#define name "TASK"
#define fi first
#define sec second
#define mp make_pair
#define ep emplace_back
#define pb push_back
#define endl "\n"
const int MOD = 1e9+7;
const int32_t INF32 = 0x3f3f3f3f;
const int64_t INF64 = 0x3f3f3f3f3f3f3f3f;

const int N = 18;
int a[N][N],n,m;

void check() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!a[i][j]) return;
        }
    }
    cout << "YES";
    exit(0);
}

void bt() {
    check();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m-1; j++) {
            if (a[i][j] == 0 && a[i+1][j] == 0 && a[i+1][j+1] == 0) {
                a[i][j] = a[i+1][j] = a[i+1][j+1] = 1;
                bt();
                a[i][j] = a[i+1][j] = a[i+1][j+1] = 0;
            }
            if (a[i][j+1] == 0 && a[i+1][j] == 0 && a[i+1][j+1] == 0) {
                a[i][j+1] = a[i+1][j] = a[i+1][j+1] = 1;
                bt();
                a[i][j+1] = a[i+1][j] = a[i+1][j+1] = 0;
            }
        }
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == '#') a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
    bt();
    cout << "NO";
    return 0;
}
