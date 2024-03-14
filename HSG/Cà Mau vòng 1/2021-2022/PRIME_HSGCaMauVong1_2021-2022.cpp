#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> se;
typedef map<int, int> mii;
#define MOD 1000000007
#define endl "\n"
#define mp make_pair
#define pb push_back

vector<bool> snt(int n) {
    vector<bool> p(n+1,true);
    p[0] = p[1] = false;
    for (int i = 2; i <= sqrt(n);i++) {
        if (p[i]) {
            for (int j = i*i; j <= n; j+= i) {
                p[j] = false;
            }
        }
    }
    return p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, cnt = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int m = *max_element(a.begin(),a.end());
    vector<bool> pr = snt(m);
    int r, l;
    for (l = 0; l < n;) {
        if (pr[a[l]]) {
            for (r = l + 1; r < n; r++) {
                if (a[r] == a[l]) {
                    cnt++;
                }
            }
        }
        l++;
    }
    cout << cnt;
    return 0;
}
