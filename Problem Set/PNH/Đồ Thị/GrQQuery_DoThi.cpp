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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	queue<int> q;
	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		if (x == 1) {
			int a;
			cin >> a;
			q.push(a);
		}
		else if (x == 2) {
			if (q.empty()) continue;
			q.pop();
		}
		else if (x == 3) {
			if (!q.empty()) {
				cout << q.front() << endl;
			}
			else cout << "Empty!" << endl;
		}
	}
	return 0;
}