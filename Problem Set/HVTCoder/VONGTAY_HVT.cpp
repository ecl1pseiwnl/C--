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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, l = 7, r = 0, check = 0;
	cin >> n;
	while(n--) {
        if (l+1 > 7 && r == 0) {
            check = 1;
        } else if (r+1 > 7 && l == 0) {
            check = 0;
        }
        if (!check) {
            r--;
            l++;
        } else {
            r++;
            l--;
        }
	}
	cout << l << ' ' << r;
	return 0;
}
