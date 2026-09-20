#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<mii> viii;
#define ms(a,n) memset(a, n,sizeof(a))
#define all(x) (x).begin(),(x).end
#define ins insert
#define sz(x) (int)(x.size())
#define name "TASK"
#define fi first
#define sec second
#define mp make_pair
#define pb push_back
#define endl "\n"
const int MOD = 1e9+7;
const int INF_INT = 2e9;
const ll INF_LL = 2e18;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll a,b,c,k;
    cin >> a >> b >> c >> k;
    ll delta = pow(b,2) - (4*a*c);
    ll x1 = (-b + sqrt(delta))/(2*a), x2 = (-b - sqrt(delta))/(2*a);
    cout << delta << " " << x1 << " " << x2 << " " << (x1*x1) + (x2*x2) << endl;
    if (delta > 0 && (x1*x1) + (x2*x2) == k) {
        cout << "YES";
        return 0;
    } else {
        cout << "NO ";
        if ((x1*x1) + (x2*x2) != k) {
            cout << "1";
        } else if (delta <= 0) {
            cout << "2";
        }
    }
    return 0;
}
