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

bool cmp(int b, int c) {
    if (abs(b) == abs(c)) {
        return abs(b) < abs(c);
    }
    return abs(b) < abs(c);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    stable_sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
