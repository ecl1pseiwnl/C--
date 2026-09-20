#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef map<int,int> mii;
#define mp make_pair
#define pb push_back
#define endl "\n"
#define MOD 10000007

int uoc(int n) {
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (n / i != i) {
                cnt+=2;
            } else cnt++;
        }
    }
    return cnt;
}

int main() {
    freopen("CAU1.INP","r",stdin);
    freopen("CAU1.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int x,y;
    cin >> x >> y;
    int t = gcd(x,y);
    cout << uoc(t);
    return 0;
}
