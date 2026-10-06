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
    int n;
    string s, temp = "";
    vector<string> v;
    vector<char> u;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1' || s[i] == '2') u.pb(s[i]);
        if (s[i] >= 'a' && s[i] <= 'z') {
            temp += s[i];
            if (s[i + 1] == '1' || s[i + 1] == '2' || i + 1 == n) {
                v.pb(temp);
                temp = "";
            }
        }
    }
    for (int i = 0; i < v.size(); i++) {
        if (u[i] == '1') {
            cout << v[i] << " ";
        }
        else if (u[i] == '2') {
            reverse(v[i].begin(), v[i].end());
            cout << v[i] << " ";
        }
    }
    return 0;
}
