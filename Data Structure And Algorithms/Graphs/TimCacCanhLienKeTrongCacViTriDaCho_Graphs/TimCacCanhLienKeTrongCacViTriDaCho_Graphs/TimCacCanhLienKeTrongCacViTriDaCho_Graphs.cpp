#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> se;
typedef map<int, int> mp;
#define endl cout << "\n";
#define mp make_pair
#define pb push_back

int n, a[1001][1001];
vi v[1001];
vector<pair<int, int>> edge;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	cin.ignore();
	for (int i = 1; i <= n; i++) {
		string s, num;
		getline(cin, s);
		stringstream ss(s);
		while (ss >> num) {
			if (stoi(num) > i) {
				edge.pb({ i,stoi(num) });
			}
		}
	}
	for (auto x : edge) {
		cout << x.first << " " << x.second;
		endl
	}
	return 0;
}