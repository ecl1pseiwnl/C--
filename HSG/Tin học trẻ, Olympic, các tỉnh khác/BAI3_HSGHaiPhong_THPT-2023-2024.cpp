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
    int n, maxv = INT_MIN;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int l = 0, r = l + 1;
    while (l < n - 1) {
        int sum = a[l];
        while(r < n) {
            sum += a[r];
            maxv = max(sum,maxv);
            r++;
        }
        l++;
        r = l + 1;
    }
    cout << maxv;
    return 0;
}
