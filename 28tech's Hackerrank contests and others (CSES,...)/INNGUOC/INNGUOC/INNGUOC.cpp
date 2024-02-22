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
	int n;
	cin >> n;
	stack<int> st;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		st.push(x);
	}
	for (int i = 1; i <= n; i++) {
		cout << st.top() << endl;
		st.pop();
	}
	return 0;
}