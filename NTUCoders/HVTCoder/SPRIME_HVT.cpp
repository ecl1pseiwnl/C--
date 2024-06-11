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

const int N = 1e7+7;
bool a[N];

void snt() {
    memset(a,true,sizeof(a));
    a[0] = a[1] = false;
    for (int i = 2; i*i <= N; i++) {
        if (a[i]) {
            for (int j = i*i; j <= N; j+=i) {
                a[j] = false;
            }
        }
    }
}

bool check(int n) {
    while (n > 0) {
        if (a[n] == false) return false;
        n % 10;
        n /= 10;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    snt();
    int l,r;
    cin >> l >> r;
    for (int i = l; i <= r; i++) {
        if (a[i] && check(i)) {
            cout << i << endl;
        }
    }
    return 0;
}
