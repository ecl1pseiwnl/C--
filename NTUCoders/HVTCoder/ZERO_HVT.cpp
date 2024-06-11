#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> sii;
typedef map<int, int> mii;
#define endl "\n";
#define mp make_pair
#define pb push_back

const int N = 10005;
int n, d[N], ans, a[N];

void dfs(int n) {
    d[n] = 1;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            int j = n / i;
            int m = (i - 1) * (j + 1);
            if (!d[m]) {
                a[m] = 1, ans++;
                dfs(m);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    dfs(n);
    a[0] = 1;
    cout << ans + 1 << endl;
    for (int i = 0; i < N; i++) {
        if (a[i]) cout << i << " ";
    }
    return 0;
}
