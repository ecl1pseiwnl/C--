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

const int N = 1e5+7;
int n, q, a[N], ma[4*N], t[4*N];

void build(int id, int l, int r) {
    if (l == r) {
        t[id] = ma[id] = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    t[id] = t[id*2] + t[id*2+1];
    ma[id] = max(ma[id*2], ma[id*2+1]);
}

int get(int id, int l, int r,int u, int v) {
	if (r < u || l > v) return -1e9;
	if (u <= l && r <= v) return ma[id];
	int mid = (l + r) / 2;
	ll t1 = get(id * 2, l, mid, u, v);
	ll t2 = get(id * 2 + 1, mid + 1, r, u, v);
	return max(t1, t2);
}

void update(int id, int l, int r, int p, int val) {
	if (p < l || p > r) return;
	if (l == r) {
        t[id] = val;
        ma[id] = val;
        return;
	}
	int mid = (l + r) / 2;
	update(id * 2, l, mid, p, val);
	update(id * 2 + 1, mid + 1, r, p, val);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    a[0] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1,1,n);
    cin >> q;
    while(q--) {
        int x,y,z;
        cin >> x >> y >> z;
        if (x == 2) {
            cout << get(1,1,n,y,z) << "\n";
        } else if (x == 1) {
            update(1,1,n,y,z);
        }
    }
    return 0;
}
