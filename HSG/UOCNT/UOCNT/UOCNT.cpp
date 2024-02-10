#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define endl "\n"
#define mp make_pair
#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, s = 0, i = 2;
    cin >> n;
    set<int> se;
    while (i <= sqrt(n)) {
        while (n % i == 0) {
            se.insert(i);
            n /= i;
        }
        i++;
    }
    if (n != 1) {
        se.insert(n);
    }
    for (auto x : se) {
        s += x;
    }
    cout << s;
}