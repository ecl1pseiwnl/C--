#include <bits/stdc++.h>
#include <windows.h>
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
#define rand(l, r) uniform_int_distribution< int64_t > (l, r)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9+7;
const int INF_INT = 2e9;
const ll INF_LL = 2e18;

vi v;
void snt(int n) {
    int a[n];
    ms(a,1);
    a[0] = a[1] = 0;
    for (int i = 2; i*i <= n; i++) {
        if (a[i]) {
            for (int j = i*i; j <= n; j+=i) {
                a[j] = 0;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (a[i]) {
            v.pb(i);
        }
    }
}

void makefile(ofstream &inp) {
    int n = rand(1,1e5);
    inp << n << "\n";
    vi u;
    snt(n);
    int sz = v.size(), _ = n * 0.99, __ = n*0.01;
    for (int i = 1; i <= n; i++) {
        if (u.size() <= _) {
            int x = v[rand(0,sz)];
            u.pb(x);
        } else if (u.size() > _) {
            int x = rand(1,1e5);
            u.pb(x);
        }
    }
    shuffle(u.begin(),u.end(),default_random_engine(0));
    for (auto it : u) {
        inp << it << " ";
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int test = 15;
    string input,output;
    for (int i = 1; i <= test; i++) {
        system(("mkdir test" + to_string(i+35)).c_str());
        input = "test" + to_string(i+35) + ".INP";
        output = "test" + to_string(i+35) + ".OUT";
        ofstream Input(input.c_str());
        makefile(Input);
        Input.close();
        system(("chinh.exe < " + input + " > " + output).c_str());
    }
    return 0;
}
