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

bool cp(int n) {
    int can = sqrt(n);
    if (1ll * can * can == n) {
        return true;
    }
    return false;
}

int reverse1(int n) {
    int ans = 0;
    while (n != 0) {
        int temp = n % 10;
        ans = ans * 10 + temp;
        n /= 10;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int l, r, cnt = 0;
    cin >> l >> r;
    for (int i = l; i <= r; i++) {
        if (cp(i + reverse1(i)) && (i + reverse1(i)) % 3 == 0) {
            cout << i << endl;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
