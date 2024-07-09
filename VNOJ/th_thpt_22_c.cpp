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
#define name "MATMA"
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
    freopen(name ".INP","r",stdin);
    freopen(name ".OUT","w",stdout);
    string s;
    cin >> s;
    int sz = s.size();
    bool tf = false;
    auto pos = s.find("0");
    if (pos != string::npos) {
        tf = true;
    }
    if ((tf && sz == 1) || (!tf)) {
        cout << "-1";
    } else {
        sort(s.begin(),s.end(),greater<int> ());
        cout << s;
    }
    return 0;
}
