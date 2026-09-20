#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<mii> viii;
#define ms(a,n) memset(a, n,sizeof(a))
#define name "TASK"
#define fi first
#define sec second
#define mp make_pair
#define pb push_back
#define endl "\n"
#define MOD 10000007

const int N = 1e6+7;
int a[N], l, r;

void snt() {
    ms(a,1);
    a[0] = a[1] = 0;
    for (int i = 2; i*i <= N; i++) {
        if (a[i]) {
            for (int j = i*i; j <= N; j += i) {
                a[j] = 0;
            }
        }
    }
    for (int i = l; i <= r; i++) {
        if (a[i]) cout << i << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> l >> r;
    snt();
    return 0;
}
