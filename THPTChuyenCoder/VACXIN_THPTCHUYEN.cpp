#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> se;
typedef map<int, int> mp;
#define endl "\n"
#define mp make_pair
#define pb push_back

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, m, Pa, Pb, cnt = 0;
	cin >> n >> m >> Pa >> Pb;
	while (m < n) {
		m += Pa + Pb;
		cnt++;
	}
	cout << cnt;
}