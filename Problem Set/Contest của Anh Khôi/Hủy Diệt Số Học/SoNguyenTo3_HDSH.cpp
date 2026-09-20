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

const int N = 1e7+7;
int a[N];

void snt() {
	memset(a, 1, sizeof(a));
	a[0] = a[1] = 0;
	for (int i = 2; i <= sqrt(N); i++) {
		if (a[i]) {
			for (int j = i * i; j <= N; j += i) {
				a[j] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	snt();
	for (int i = 2; i <= n; i++) {
		if (a[i]) {
			cout << i << " ";
		}
	}
	return 0;
}