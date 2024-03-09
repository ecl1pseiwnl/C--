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

int x[1000];
int n, cnt = 0, check = 0;
void kt() {
	for (int i = 1; i <= n; i++) {
		x[i] = i;
	}
}
void sinh() {
	int i = n - 1;
	while (i >= 1 && x[i] > x[i + 1]) {
		i--;
	}
	if (i == 0) {
		check = 1;
	}
	else {
		int j = n;
		while (x[i] > x[j]) {
			j--;
		}
		swap(x[i], x[j]);
		reverse(x + i + 1, x + n + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	kt();
	while (check == 0) {
		for (int i = 1; i <= n; i++) {
			cout << x[i];
		}
		cout << endl;
		sinh();
		cnt++;
	}
	cout <<"Co " << cnt << " hoan vi cua cac ki tu";
	return 0;
}