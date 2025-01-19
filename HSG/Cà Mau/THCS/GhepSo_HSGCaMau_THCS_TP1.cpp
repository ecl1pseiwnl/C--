#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr) ->sync_with_stdio(false);
    //freopen("GhepSo.inp","r",stdin);
    //freopen("GhepSo.out","w",stdout);
    string s,t,ans = "";
    cin >> s;
    cin >> t;
    int n = s.size(), m = t.size(), l = 0, r = 0;
    while (ans.size() != n+m) {
        if (s[l] == t[r]) {
            ans += s[l];
            ans += t[r];
            l++; r++;
        }else if (s[l] > t[r]) {
            ans += t[r];
            r++;
        } else if (s[l] < t[r]) {
            ans += s[l];
            l++;
        }
        if (!t[r] && s[l]) {
            ans += s[l];
            l++;
        } else if (!s[l] && t[r]) { ans += t[r]; r++;}
    }
    if (r < m) {
        for (int i = r; i < m; i++) {
            ans += t[i];
        }
    } else if (l < n) {
        for (int i = l; i < n; i++) {
            ans += s[i];
        }
    }
    cout << ans;
    return 0;
}
