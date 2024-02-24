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
	string s;
	getline(cin, s);
	stack<char> st;
	int sz = s.size() - 1;
	for (int i = 0; i <= sz; i++) {
		if (s[i] != ' ') {
			st.push(s[i]);
		}
	}
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
	return 0;
}