#include <bits/stdc++.h>
#include <numeric>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define endl "\n"
#define mp make_pair
#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll temp = 1;
    for (int i = 0; i < n; i++) {
        temp = temp * a[i] / (__gcd(temp, a[i]));
    }
    cout << temp << endl;
    for (ll x : a) {
        cout << temp / x << " ";
    }
}