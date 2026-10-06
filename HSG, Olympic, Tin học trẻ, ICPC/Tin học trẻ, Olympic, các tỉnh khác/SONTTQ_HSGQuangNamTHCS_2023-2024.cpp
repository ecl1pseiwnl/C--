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

const int N = 25;
vector<int> a(N,1);

void snt() {
    a[0] = a[1] = 0;
    for (int i = 2; i <= N; i++) {
        if (a[i]) {
            for (int j = i*i; j <= N; j += i) {
                a[j] = 0;
            }
        }
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    snt();
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<int> v;
    for (auto it : s) v.push_back(int(it-'0'));
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end()) - v.begin());
    if (v.size() >= n) {
        cout << v[n-1] << " " << (a[v[n-1]] == 1 ? "Yes" : "No");
    } else cout << "-1";
    return 0;
}
