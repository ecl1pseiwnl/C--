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

int n, a[1001], k;
bool kt[1001][1001];

void tryy(int i, int j) {
    for (int y = j + 1; y < n; y++) {
        if (a[i] + a[j] == a[y]) {
            k++;
            tryy(j, y);
            break;
        }

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int maxx = 0;
    memset(kt, false, sizeof(kt));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            k = 1;
            tryy(i, j);
            maxx = max(maxx, k);
        }
    }
    if (maxx <= 1)
        cout << 0;
    else
        cout << maxx + 1;
    return 0;
}
