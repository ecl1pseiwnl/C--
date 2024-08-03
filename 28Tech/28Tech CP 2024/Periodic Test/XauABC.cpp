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

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int temp = 0;
    string s;
    cin >> s;
    deque<char> q;
    for (auto &it : s) {
        if(!q.empty() && q.back() != it) {
            temp++;
        }
        q.push_back(it);
        if (temp == 2) {
            q.pop_back();
            q.pop_back();
            q.pop_back();
            temp = 0;
        }
    }
    while(!q.empty()) {
            auto it = q.front(); q.pop_back();
            cout << it;
    }
    return 0;
}
