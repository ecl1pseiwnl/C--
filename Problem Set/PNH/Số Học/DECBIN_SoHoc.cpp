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

string dectobin(ll n) {
    string s;
    while (n) {
        if (n & 1) {
            s += "1";
        }
        else {
            s += "0";
        }
        n >>= 1;
    }
    return s;
}

void rv(string s) {
    for (int i = s.size() - 1; i >= 0; i--) {
        cout << s[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while (n--) {
        ll x;
        cin >> x;
        rv(dectobin(x));
        cout << endl;
    }
    return 0;
}
