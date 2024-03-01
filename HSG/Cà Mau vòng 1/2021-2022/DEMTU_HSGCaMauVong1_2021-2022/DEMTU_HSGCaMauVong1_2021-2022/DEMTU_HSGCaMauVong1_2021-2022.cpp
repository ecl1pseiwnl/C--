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
	string s, temp;
	int cnt = 0;
	getline(cin, s);
	stringstream ss(s);
	while (ss >> temp) {
		cnt++;
	}
	cout << cnt;
	return 0;
}