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
#define pb push_back
#define endl "\n"
const int MOD = 1e9+7;
const int32_t INF32 = 0x3f3f3f3f;
const int64_t INF64 = 0x3f3f3f3f3f3f3f3f;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<string> c1(n),c2(n);
    for (auto & it : c1) cin >> it;
    for (auto & it : c2) cin >> it;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                unordered_map<string,bool> check;
                bool tf = true;
                for (auto &it : c1) {
                    check[{it[i],it[j],it[k]}] = true;
                }
                for (auto &it : c2) {
                    if (check.count({it[i],it[j],it[k]})) {
                        tf = false;
                        break;
                    }
                }
                cnt += tf;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
