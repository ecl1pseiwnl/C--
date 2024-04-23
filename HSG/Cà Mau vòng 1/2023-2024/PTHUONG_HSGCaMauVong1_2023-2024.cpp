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

int ptich(int n) {
	int s = 0;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			s += i;
		}
	}
	for (int i = sqrt(n); i >= 1; i--) {
		if (n % i == 0 && n / i != i) {
			s += n / i;
		}
	}
	return s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	priority_queue < pair<int, int>, vector<pair<int, int>>> q;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		q.push({ ptich(x),x });
	}
	auto it = q.top();
	cout << it.second;
	return 0;
}