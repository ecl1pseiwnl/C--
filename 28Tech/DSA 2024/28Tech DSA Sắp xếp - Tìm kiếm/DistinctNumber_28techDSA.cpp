#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef map<int, int> mii;
#define mp make_pair
#define pb push_back
#define endl "\n"
#define MOD 10000007

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int a[n];
    set<int> se;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        se.insert(a[i]);
    }
    cout << se.size();
    return 0;
}
