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
    ll x, y, cnt = 0;
    cin >> x >> y;
    string s = "";
    for (ll i = x; i <= y; i++) {
        string tmp = to_string(i * i);
        s += tmp;
    }
    for (int i = 0; i < s.size(); i++) {
        cnt++;
    }
    cout << cnt;
    return 0;
}