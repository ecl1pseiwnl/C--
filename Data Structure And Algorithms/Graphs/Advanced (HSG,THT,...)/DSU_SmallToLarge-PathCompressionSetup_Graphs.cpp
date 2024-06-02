#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<mii> viii;
#define fi first
#define sec second
#define mp make_pair
#define pb push_back
#define endl "\n"
#define MOD 10000007

const int N = 1005;
int n,m, par[N], sz[N];
vector<int> v[N];

void make_set() {
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
}

int find_set(int u) {
    if (u == par[u]) return u;
    int p = find_set(par[u]);
    return p;
}

bool Union(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a,b);
    par[b] = a;
    sz[a] += sz[b];
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    make_set();
    return 0;
}
