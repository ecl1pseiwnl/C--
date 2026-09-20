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
    ll n, i = 2;
    cin >> n;
    map<ll, int> m;
    while (i <= sqrt(n)) {
        while (n % i == 0) {
            m[i]++;
            n /= i;
        }
        i++;
    }
    if (n != 1) {
        m[n]++;
    }
    cout << m.size() << endl;
    for (auto it : m) {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}
