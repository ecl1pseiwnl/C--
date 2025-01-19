#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr) ->sync_with_stdio(false);
    //freopen("GhepSo.inp","r",stdin);
    //freopen("GhepSo.out","w",stdout);
    string s,t,ans = "";
    cin >> s;
    cin >> t;
    int n = s.size()+1, m = t.size()+1;
    int l = 0, r = 0;
    while (l < n && r < m) {
        if (s[l] > t[r]) {
            ans += t[r];
            r++;
        } else if (s[l] < t[r]) {
            ans += s[l];
            l++;
        } else if (s[l] == t[r]) {
            ans += s[l];
            ans += t[r];
            l++; r++;
        }
    }
    if (l < n-1) {
        ans += s[l];
    } else if (r < m-1) {
        ans += t[r];
    }
    cout << ans;
}
