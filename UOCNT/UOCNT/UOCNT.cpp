#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// cach 1: O(logn)
const ll N = 1e14;
ll a[N];

void sang() {
    for (ll i = 2; i <= N; i++) {
        a[i] = 1;
    }
    a[0] = a[1] = 0;
    for (ll i = 2; i <= sqrt(N); i++) {
        if (a[i] == 1) {
            for (ll j = i * i; j < N; j += i) {
                a[j] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n, s = 0;
    cin >> n;
    sang();
    for (ll i = 2; i <= sqrt(n); i++) {
        if (n % i == 0 && a[i] == 1) {
            s += i;
        }
    }
    cout << s;
}
// Cach 2
int main2() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    long long n;
    cin >> n;
    int cnt;
    long long sum = 0;
    for (int i = 2; i <= n; i++) {
        cnt = 0;
        while (n % i == 0) {
            cnt++;
            if (cnt == 1) {
                sum += i;
            }
            n /= i;
        }
    }
    cout << sum << endl;
}

// cach 3:
int snt(int N) {
    if (N < 2) return 0;
    for (int i = 2; i * i <= N; i++) {
        if (N % i == 0) return 0;
    }
    return 1;
}

int main2() {
    int N, s = 0;
    cin >> N;
    for (int i = 2; i <= N; i++) {
        if (N % i == 0 && snt(N)) {
            s += i;
        }
    }
    cout << s;
}