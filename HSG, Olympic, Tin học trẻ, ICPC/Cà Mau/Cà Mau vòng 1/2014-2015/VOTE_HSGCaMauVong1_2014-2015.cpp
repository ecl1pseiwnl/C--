#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef map<int, int> mii;
#define mpi make_pair
#define pb push_back
#define endl "\n"
#define MOD 10000007

bool cmp(pair<char, int>& a, pair<char, int>& b) {
    return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    string s, z;
    cin >> n >> s >> m >> z;
    map<char, int> mp;
    for (int i = 0; i < s.size(); i++) {
        mp[s[i]] = 0;
    }
    for (int i = 0; i < z.size(); i++) {
        auto it = mp.find(z[i]);
        if (it != mp.end() && z[i] != '0') {
            mp[z[i]]++;
        }
    }
    vector<pair<char, int>> v;
    for (auto it : mp) {
        v.pb(it);
    }
    sort(v.begin(), v.end(), cmp);
    for (auto it : v) {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}
