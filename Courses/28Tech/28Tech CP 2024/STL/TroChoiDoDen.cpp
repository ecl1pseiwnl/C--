#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<mii> viii;
ll lcm(ll x, ll y) { return 1ll*(x / __gcd(x,y))*y;}
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

void solve() {
    long long x,y;
    cin >> x >> y;
    if(y<=1 || x==0) {
        cout << "NO";
    }
    else {
        int a=x;
        long long b=x*(2*y-1);
        long long c=a+b;
        cout << "YES"<<"\n";
        cout << a << " " << b << " "<< c;
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        solve;
        cout << "\n";
    }
    return 0;
}
