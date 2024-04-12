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

bool check(char c) {
    return c == '2' || c == '3' || c == '5' || c == '7';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int t;
    cin >> t;
    sort(s.begin(), s.end());
    cout << s[t - 1] << " ";
    if (check(s[t - 1])) {
        cout << "YES";
    }
    else cout << "NO";
    return 0;
}
