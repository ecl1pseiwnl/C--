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

const int N = 1e6 + 7;
bool a[N];

void snt() {
    memset(a, true, sizeof(a));
    a[0] = a[1] = false;
    for (int i = 2; i <= sqrt(N); i++) {
        if (a[i]) {
            for (int j = i * i; j <= N; j += i) {
                a[j] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    snt();
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (a[i]) {
            cout << i << " ";
        }
    }
    return 0;
}
