#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<mii> viii;
#define ms(a,n) memset(a, n,sizeof(a))
#define name "CAU1"
#define fi first
#define sec second
#define mp make_pair
#define pb push_back
#define endl "\n"
#define MOD 10000007

bool check(string s) {
    int d = 0;
    for (int i = 0;i < s.size();i++) {
        d += (s[i] - '0') * (i+1);
    }
    if (d % 7 == 0) return true;
    return false;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen(name ".inp","r",stdin);
    freopen(name ".out","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s, tmp = "";
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '?') {
            tmp += s[i];
        } else if (s[i] == '?') {
            for (int j = 0; j <= 9; j++) {
                if (i == 0 && j == 0) continue;
                string t = tmp + to_string(j);
                if (check(t)) return cout << j, 0;
            }
        }
    }
    cout << "-1";
    return 0;
}
