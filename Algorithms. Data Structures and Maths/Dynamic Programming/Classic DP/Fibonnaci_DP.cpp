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
int f[100];

int fibo(int n) {
	cout << f[n] << " ";
	if (n <= 1) return f[n];
	if (f[n] != 0) {
		return f[n];
	}
	f[n] = fibo(n - 1) + fibo(n - 2);
	return f[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	f[0] = f[1] = 1;
	cout << fibo(n);
	return 0;
}