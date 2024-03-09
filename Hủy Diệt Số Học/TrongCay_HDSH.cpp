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
const int N = 1e7 + 7;
int a[N];

void snt() {
	memset(a, 1, sizeof(a));
	a[0] = a[1] = 0;
	for (int i = 2; i <= sqrt(N); i++) {
		if (a[i]) {
			for (int j = i * i; j <= N; j += i) {
				a[j] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	snt();
	deque<int> q;
	int n, check = 0;
	cin >> n;
	int A[n];
	for (int& it : A) cin >> it;
	sort(A, A + n, greater<int>());
	for (int i = 1; i <= n; i++) {
		if (a[A[i]]) {
			if (check == 0) {
				q.push_back(A[i]);
				check = 1;
			}
			else if (check == 1) {
				q.push_front(A[i]);
				check = 0;
			}
		}
	}
	if (q.empty()) {
		cout << "-1";
		return 0;
	}
	for (auto it : q) {
		cout << it << " ";
	}
	return 0;
}
