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

const int N = 1e4+7;
int a[N];

void snt() {
    memset(a,1,sizeof(a));
    a[0] = a[1] = 0;
    for (int i = 2; i*i <= N; i++) {
        if (a[i]) {
            for (int j = i*i; j <= N; j += i) {
                a[j] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    snt();
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) v.pb(i);
    }
    for (int i = sqrt(n); i >= 1; i--) {
        if (n % i == 0 && n / i != i) v.pb(n/i);
    }
    cout << "- Cac uoc la: ";
    for (auto it : v) cout << it << " ";
    cout << endl << "- Cac uoc nguyen to: ";
    for (auto it : v) {
        if (a[it]) cout << it << " ";
    }
    return 0;
}
