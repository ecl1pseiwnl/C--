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

vector<bool> sieve(int n) {
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (prime[i] == true) {
            for (int j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }
    return prime;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int m = *max_element(a.begin(), a.end());
    vector<bool> prime = sieve(m);
    int ok = 0;
    for (int it : a) {
        if (prime[it] && it > ok) {
            ok = it;
        }
    }
    cout << ok;
    return 0;
}