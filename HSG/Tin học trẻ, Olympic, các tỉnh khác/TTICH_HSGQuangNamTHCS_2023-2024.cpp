#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> si;
typedef map<int, int> mii;
#define MOD 10000000007
#define endl "\n";
#define mp make_pair
#define pb push_back

const int N = 1e7+7;
vector<int> v(N,1);

void snt() {
    v[0] = v[1] = 0;
    for (int i = 2; i*i <= N; i++) {
        if (v[i]) {
            for (int j = i*i; j <= N; j+=i) {
                v[j] = 0;
            }
        }
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    snt();
    int t;
    cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m;
        map<int,int> mp,np;
        for (int i = 0, x; i < n; i++) {
            cin >> x;
            if (v[x]) {
                mp[x]++;
            } else {
                for (int i = 2; i*i <= x; i++) {
                    if (x % i == 0) {
                        mp[i]++;
                        x/=i;
                    }
                }
                if (x > 1) mp[x]++;
            }
        }
        for (int i = 0, x; i < m; i++) {
            cin >> x;
            if (v[x]) {
                np[x]++;
            } else {
                for (int i = 2; i*i <= x; i++) {
                    if (x % i == 0) {
                        np[i]++;
                        x/=i;
                    }
                }
                if (x > 1) np[x]++;
            }
        }
        bool tf = 0;
        for (auto it : mp) {
            if (it.second != np[it.first] || np.find(it.first) == np.end()) {
                tf = 1;
            }
        }
        cout << (tf == 1 ? "NO\n" : "YES\n");
    }
    return 0;
}
