#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> se;
typedef map<int, int> mii;
#define endl "\n";
#define mp make_pair
#define pb push_back

const int MOD = 1e9 + 7;
map<ll, ll> F;

ll fib(ll n) {
	if (F.count(n)) {
		return F[n];
	}
	ll k = n / 2;
	if (n % 2 == 0) {
		return F[n] = (fib(k) * fib(k) + fib(k - 1) * fib(k - 1)) % MOD;
	}
	return F[n] = (fib(k) * fib(k - 1) + fib(k) * fib(k + 1)) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n;
	F[0] = F[1] = 1;
	cout << (n == 0 ? 0 : fib(n - 1));
	return 0;
}

/*
struct matrix {
    ll x[2][2];
    friend matrix operator * (matrix a, matrix b) {
        matrix c;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c.x[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    c.x[i][j] += a.x[i][k] * b.x[k][j];
                    c.x[i][j] %= MOD;
                }
            }
        }
        return c;
    }
};

matrix Pow(matrix T, ll n) {
    if (n == 1) {
        return T;
    }
    matrix tmp = Pow(T, n / 2);

    if (n % 2 == 1) {
        return tmp * tmp * T;
    }
    else {
        return tmp * tmp;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    if (n <= 1) return cout << n, 0;
    matrix T;
    T.x[0][0] = T.x[0][1] = T.x[1][0] = 1;
    T.x[1][1] = 0;
    matrix ans = Pow(T, n);
    cout << ans.x[0][1];
    return 0;
}
*/