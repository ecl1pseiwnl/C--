#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> si;
typedef map<int, int> mii;
#define MOD 1000000007
#define endl "\n"
#define mp make_pair
#define pb push_back

bool cmp(string a, string b) {
    if (a + b > b + a) {
        return a + b > b + a;
    } else {
        return b + a > a + b;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string s;
    vector<string> v;
    for (int i = 0; i < n; i++) {
        cin >> s;
        v.pb(s);
    }
    sort(v.begin(), v.end(),cmp);
    for(auto it : v) cout << it;
    return 0;
}
