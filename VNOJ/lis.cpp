#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<mii> viii;
#define name "TASK"
#define fi first
#define sec second
#define mp make_pair
#define pb push_back
#define endl "\n"
#define MOD 10000007

int n, maxv;
vector<int> a(30005), b(30005);

int bi(int x) {
    int ans = 0, l = 1, r = maxv;
    while(l <= r) {
        int m = (l+r)/2;
        if (b[m] < x) {
            ans = m;
            l = m + 1;
        } else r = m - 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        int j = bi(a[i]); // int j = lower_bound(b+1,b+ma+1,a[i]) - b - 1;
        b[j+1] = a[i];
        maxv = max(maxv,j+1);
    }
    cout << maxv;
    return 0;
}
