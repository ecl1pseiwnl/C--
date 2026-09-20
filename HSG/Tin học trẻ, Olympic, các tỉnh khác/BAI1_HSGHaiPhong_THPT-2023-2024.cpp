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
    ll l, r, a, b;
    cin >> l >> r >> a >> b;
    cout << ((r / a) - (l / a)) + ((r / b) - (l / b));
    return 0;
}
