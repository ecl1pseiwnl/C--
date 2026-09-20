#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef map<int, int> mii;
#define mp make_pair
#define pb push_back
#define endl "\n"
#define MOD 10000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a[n], maxv = INT_MIN;
    mii mp;
    vi v;
    for (auto& it : a) {
        cin >> it;
        mp[it]++;
    }
    for (auto it : mp) {
        maxv = max(maxv, it.second);
    }
    for (auto it : mp) {
        if (it.second == maxv) {
            cout << it.first << " " << maxv;
            return 0;
        }
    }
    return 0;
}
