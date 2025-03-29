#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> se;
typedef map<int, int> mp;
#define endl "\n"
#define mp make_pair
#define pb push_back

ll n, k, cnt = 0;
const int N = 10000005;
vector<ll> v;
int a[N];

void snt() {
	memset(a, 1, sizeof(a));
	a[1] = a[0] = 0;
	for (int i = 2; i <= sqrt(N); i++) {
		if (a[i]) {
			for (int j = i * i; j <= N; j += i) {
				a[j] = 0;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (a[i]) {
			v.pb(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	snt();
    for (auto it : v) {
        if (binary_search(v.begin(),v.end(),it-k)) {
            cnt++;
            cout << it-k << " " << it << endl;
        }
    }
	cout << cnt;
	return 0;
}
