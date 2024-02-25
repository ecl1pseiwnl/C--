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

const int N = 1e7 + 7;
int A[N];

void snt() {
    memset(A, 1, sizeof(A));
    A[0] = A[1] = 0;
    for (int i = 2; i <= sqrt(N); i++) {
        if (A[i]) {
            for (int j = i * i; j <= N; j += i) {
                A[j] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n, cnt = 0, Max; char c; string s;
    cin >> n >> c;
    int a[n];
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> s;
    snt();
    vector<ll> v;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == c && A[i]) {
            v.pb(a[i]);
        }
    }
    if (v.empty()) {
        cout << "0 0";
        return 0;
    }
    Max = *max_element(v.begin(), v.end());
    for (auto it : v) {
        if (it == Max) {
            cnt++;
        }
    }
    cout << cnt << " " << Max;
    return 0;
}
