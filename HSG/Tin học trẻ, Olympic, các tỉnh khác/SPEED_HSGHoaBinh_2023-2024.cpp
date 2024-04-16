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
	int a, b;
	cin >> a >> b;
	int mid = abs(a - b);
	if (mid < 10) {
		cout << "800";
	}
	else if (mid >= 10 && mid <= 20) {
		cout << "3000";
	}
	else if (mid > 20 && mid <= 35) {
		cout << "6000";
	}
	else if (mid > 35) {
		cout << "10000";
	}
	return 0;
}