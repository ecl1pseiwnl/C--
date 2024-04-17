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

const int N = 1e6 + 7;
int a[N], F[N];

void snt() {
	memset(a, 1, sizeof(a));
	a[0] = a[1] = 0;
	for (int i = 2; i * i <= N; i++) {
		if (a[i]) {
			for (int j = i * i; j <= N; j += i) {
				a[j] = 0;
			}
		}
	}
	F[0] = F[1] = 0;
	for (int i = 2; i <= N; i++) {
		if (a[i]) {
			F[i] = F[i - 1] + 1;
		}
		else F[i] = F[i - 1];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	snt();
	int t;
	cin >> t;
	while (t--) {
		int l, r;
		cin >> l >> r;
		cout << F[r] - F[l - 1] << endl;
	}
}