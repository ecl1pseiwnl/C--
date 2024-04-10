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

int n;
mii m;

void dem(int u) {
    while (u != 0) {
        m[u % 10]++;
        u /= 10;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dem(a[i]);
    }
    for (auto it : m) {
        cout << it.first << " ";
    }
    return 0;
}
