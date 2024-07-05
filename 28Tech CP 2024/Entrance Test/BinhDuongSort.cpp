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

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    while(n--) {
        int x;
        bool tf = false;
        cin >> x;
        vi a(x);
        for (auto& it : a) cin >> it;
        for (int i = 0; i + 1 < x; i++) {
            if (a[i] >= a[i+1] && a[i+1] <= 1) {
                tf = true;
            }
        }
        if (tf) {
            cout << "YES\n";
        } else cout << "NO\n";
    }
    return 0;
}
