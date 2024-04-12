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
    int n, ans = 0, a[10] = { 1000, 500,200, 100,50,20,10,5,2,1 };
    cin >> n;
    for (int i = 0; i < 10; i++) {
        ans += n / a[i];
        n %= a[i];
    }
    cout << ans;
    return 0;
}
