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
	int m = n;
	cout << n << " ";
	while (m != 1) {
        if (m % 2 == 0) {
            m /= 2;
        } else {
            m = (m * 3) + 1;
        }
        cout << m << " ";
	}
	return 0;
}
