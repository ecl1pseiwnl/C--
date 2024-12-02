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
			a[i][stoi(num)] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; i <= n; j++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}