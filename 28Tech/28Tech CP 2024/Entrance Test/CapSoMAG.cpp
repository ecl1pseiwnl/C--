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

const int N = 2*1e5+7;
int a[N];

void sang() {
    for (int i = 1; i < N; i++) a[i] = i;
    for (int i = 2; i*i <= N; i++) {
        if (p[i] == i) {
            for (int j = i*i; j <= N; j+=i) {
                p[j] = i;
            }
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    sang();
    int n;
    cin >> n;
    vi a(n), cnt (N,0);
    ll ans =0;
    for (auto& it : a) cin >> it;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        int q = x;
        mii mp;
        if (x>1) {
            while(x!=1) {
                mp[a[x]]++;
                x/=a[x];
            }
        }
        q = 1;
        for (auto [j,k] : mp) {
            if (k%2) q*=j;
        }
        ans+= cnt[q];
        cnt[q]++;
    }
    ans+=1ll*cnt[0]*(n-cnt[0]);
    cout << ans;
    return 0;
}
