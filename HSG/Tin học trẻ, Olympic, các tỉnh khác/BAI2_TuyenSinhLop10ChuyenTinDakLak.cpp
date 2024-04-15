#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> si;
typedef map<int, int> mii;
#define MOD 10000000007
#define endl "\n";
#define mp make_pair
#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, b, cnt = 0;
    cin >> a >> b;
    ll x = sqrt(a), y = sqrt(b);
    if (x * x != a) {
        x++;
    }
    for (int i = x; i <= y; i++) {
        cnt++;
    }
    cout << cnt;
    return 0;
}