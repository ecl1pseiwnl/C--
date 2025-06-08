#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<mii> viii;
#define fi first
#define sec second
#define mp make_pair
#define pb push_back
#define endl "\n"
#define MOD 10000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s;
    int ans = 1, cnt = 1;
    cin >> s;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i-1]) {
            cnt++;
            ans = max(cnt,ans);
        } else {
            cnt = 1;
            ans = max(cnt,ans);
        }
    }
    cout << ans;
    return 0;
}
