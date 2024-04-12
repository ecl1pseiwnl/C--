#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> si;
typedef map<int, int> mii;
#define MOD 10000000007
#define endl "\n";
#define mp make_pair
#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, temp;
    int cnt = 0;
    vector<string> v;
    getline(cin, s);
    stringstream ss(s);
    while (ss >> temp) {
        string ans;
        for (int i = 0; i < temp.size(); i++) {
            char c = temp[i];
            if (c >= '0' && c <= '9') {
                cnt += c - '0';
            }
            else {
                ans += c;
            }
        }
        reverse(ans.begin(), ans.end());
        v.pb(ans);
    }
    cout << cnt << " ";
    for (auto it : v) cout << it << " ";
    return 0;
}
