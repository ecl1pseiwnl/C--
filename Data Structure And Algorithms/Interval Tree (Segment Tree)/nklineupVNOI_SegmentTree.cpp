#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> si;
typedef map<int, int> mii;
#define MOD 1000000007
#define endl "\n"
#define mp make_pair
#define pb push_back

const int N = 1e4+5;
int n, q, a[N], ma[4*N], mi[4*N];
void build(int id, int l, int r) {
    if (l == r) {
        ma[id] = mi[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    ma[id] = max(ma[id * 2], ma[id * 2 + 1]);
    mi[id] = min(mi[id * 2], mi[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v, bool s) {
    if (r < u || l > v) {
        if (!s) return INT_MIN;
        if (s) return INT_MAX;
    }
    if (u <= l && r <= v) {
        if (!s) return ma[id];
        if (s) return mi[id];
    }
    int mid = (l + r) / 2;
    int t1 = get(id * 2, l, mid, u, v, s);
    int t2 = get(id * 2 + 1, mid + 1, r, u, v, s);
    if (!s) {
        return max(t1, t2);
    } else if (s) return min(t1, t2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build( 1, 1, n);
    while(q--) {
        int l,r;
        cin >> l >> r;
        int get_max = get( 1, 1, n, l, r, 0);
        int get_min = get( 1, 1, n, l, r, 1);
        cout << get_max - get_min << endl;
    }
    return 0;
}
