#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> se;
typedef map<int, int> mii;
#define endl "\n";
#define mp make_pair
#define pb push_back

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	while (n != 1 && n > 0) {
		cout << n << " ";
		if (n % 2 == 0) {
			n /= 2;
		}
		else {
			n *= 3;
			n += 1;
		}
	}
	cout << "1";
	return 0;
}