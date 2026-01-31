#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
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

string sampleStr = "abcdefghijklmnopqrstuvwxyz";

void makefile(ofstream &inp) {
    int n = 89792, k = 523976;
    inp << n << " " << k << "\n";
    for (int i = 1; i <= n; i++) {
        inp << 523976 << " ";
    }
}


signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int test = 1;
    string input,output, testName = "test";
    for (int i = 1; i <= test; i++) {
        string curTest = "test";
        curTest += (i < 10 ? "0" : "") + to_string(i);
        system(("mkdir " + curTest).c_str());
        input  = curTest + "\\" + testName + ".INP";
        output = curTest + "\\" + testName + ".OUT";
        ofstream Input(input.c_str());
        makefile(Input);
        Input.close();
        system(("chinh.exe < " + input + " > " + output).c_str());
    }
    return 0;
}
