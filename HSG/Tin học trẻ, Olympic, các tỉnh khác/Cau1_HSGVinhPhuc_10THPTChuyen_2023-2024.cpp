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

const int N = 1e6 + 7;
int a[N];

void snt() {
    for (int i = 2; i * i <= N; i++) {
        if (a[i] == 0) {
            for (int j = i * i; j <= N; j += i) {
                if (a[j] == 0) {
                    a[j] = i;
                }
            }
        }
    }
    for (int i = 2; i <= N; i++) {
        if (a[i] == 0) {
            a[i] = i;
        }
    }
}

int ptich(int n) {
    vi se;
    while (n != 1) {
        se.pb(a[n]);
        n /= a[n];
    }
    return se.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    snt();
    int n;
    cin >> n;
    while (n--) {
        int l, r, cnt = 0;
        cin >> l >> r;
        for (int i = l; i <= r; i++) {
            if (ptich(i) == 3) {
                cnt++;
            }
        }
    }
    return 0;
}
