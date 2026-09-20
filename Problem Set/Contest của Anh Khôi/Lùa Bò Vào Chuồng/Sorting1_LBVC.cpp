#include <bits/stdc++.h>
#include <unordered_map>
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
	int n;
	cin >> n;
	mii m;
	while (n--) {
		int x;
		cin >> x;
		m[x]++;
		if (m[x] > 1) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}