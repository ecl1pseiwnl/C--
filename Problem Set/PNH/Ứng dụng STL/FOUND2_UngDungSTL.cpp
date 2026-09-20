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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    mii ma;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ma[x]++;
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        cout << ma[x] << endl;
    }
    return 0;
}
