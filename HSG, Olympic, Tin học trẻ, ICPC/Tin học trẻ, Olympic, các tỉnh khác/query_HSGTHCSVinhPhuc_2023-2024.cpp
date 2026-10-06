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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, p, cnt, res;
	char s;
	deque<int> q;
	cin >> n >> k >> p;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		q.push_back(x);
	}
	while (p--) {
		cin >> s;
		if (s == '!') {
			auto x = q.back();
			q.push_front(x);
			q.pop_back();
		}
		else if (s == '?') {
			cnt = 0;
			for (int i = 0; i < k; i++) {
				cnt += q[i];
			}
			res = cnt;
			for (int i = k; i < n; i++) {
				cnt = cnt - q[i - k] + q[k];
				if (cnt > res) {
					res = cnt;
				}
			}
			cout << res << endl;
		}
	}
	return 0;
}