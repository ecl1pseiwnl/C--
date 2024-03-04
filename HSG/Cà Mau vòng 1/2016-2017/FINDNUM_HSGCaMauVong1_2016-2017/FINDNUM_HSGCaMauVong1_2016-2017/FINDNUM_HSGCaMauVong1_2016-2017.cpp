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

int tong(int n) {
	int sum = 0;
	while (n != 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int reverse(int n) {
	int res = 0, s;
	while (n != 0) {
		s = n % 10;
		res = res * 10 + s;
		n /= 10;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int l, r, cnt = 0;
	cin >> l >> r;
	int a = sqrt(l), b = sqrt(r);
	
	cout << cnt;
	return 0;
}