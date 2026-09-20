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

int phi(int n) {
    int res = n;
    for (int i = 2; i*i <= n; i++) {
        if (n%i == 0) {
            while(n%i==0) n /= i;
            res -= res / i;
        }
    }
    if (n > 1) res -= res / n;
    return res;
}

void phi_1_to_n(int n) {
    vi p(n+1);
    p[0] = 0;
    p[1] = 1;
    for (int i = 2; i <= n; i++) {
        p[i] = i;
    }
    for (int i = 2; i <= n; i++) {
        if (p[i] == i) {
            for (int j = i; j <= n; j++) {
                p[j] -= p[j] / i;
            }
        }
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    return 0;
}
