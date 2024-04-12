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

const int N = 1e5 + 7;
struct dt {
    int id, time, profit;
};

dt a[N];

bool cmp(dt x, dt y) {
    return x.profit > y.profit;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].id >> a[i].time >> a[i].profit;
    }
    sort(a, a + n, cmp);
    int F[N] = { 0 };
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        while (F[a[i].time] && a[i].time > 0) a[i].time -= 1;
        if (!F[a[i].time] && a[i].time > 0) {
            F[a[i].time] = 1;
            ans += a[i].profit;
        }
    }
    cout << ans;
    return 0;
}
