#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 1e8;
int a[N];

int main() {
	ll n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	map <ll, ll> mp;
	sort(a + 1, a + n + 1);
	ll s = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > k) {
			s += mp[a[i] - k];
			mp[a[i]]++;
		}
	}
	cout << s;
	return 0;
}