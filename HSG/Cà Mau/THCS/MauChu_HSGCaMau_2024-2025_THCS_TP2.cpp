#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<mii> viii;
const double PI = 3.141592653589793238463;
#define bmask(x,i) (((x) >> (i)) & 1)
#define ms(a,n) memset(a, n,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define uniquev(v) sort(all(v)), (v).resize(unique(all(v)) - (v).begin())
#define ins insert
#define sz(x) (int)(x.size())
#define name "TASK"
#define fi first
#define sec second
#define mp make_pair
#define ep emplace_back
#define pb push_back
#define endl "\n"
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
ll __lcm(ll x, ll y) { return 1ll*(x / __gcd(x,y))*y;}
constexpr int MOD = 1e9+7;
constexpr int32_t IINF = 0x3f3f3f3f;
constexpr int64_t LLINF = 0x3f3f3f3f3f3f3f3f;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    //freopen("MauChu.inp","r",stdin);
    //freopen("MauChu.out","w",stdout);
    string s = "#HOCSINHGIOITHANHPHOCAMAU", t[5] ={"TIM","DO","VANG","CAM","TRANG"};
    int sz = s.size()-1;
    int n;
    cin >> n;
    if (n <= sz) {
        cout << s[n] << "-" << t[n%5];
    } else {
        cout << s[n%sz] << "-" << t[n%5];
    }
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
