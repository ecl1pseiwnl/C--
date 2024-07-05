#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef map<int, int> mii;
#define mp make_pair
#define pb push_back
#define endl "\n"
#define MOD 10000007

const int N = 1e6 + 7;
struct dt {
    int s, t;
};

dt a[N];

bool cmp(dt x, dt y) {
    if (x.t == y.t) {
        return x.s < y.s;
    }
    return x.t < y.t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, i = 0;
    cin >> n;
    while (i < n) {
        cin >> a[i].s >> a[i].t;
        i++;
    }
    sort(a, a + n, cmp);
    int d = 1, nht = a[0].t;
    for (int i = 1; i < n; i++) {
        if (a[i].s > nht) {
            d++;
            nht = a[i].t;
        }
    }
    cout << d << endl;
    return 0;
}
