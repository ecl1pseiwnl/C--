#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<mii> viii;
#define fi first
#define sec second
#define mp make_pair
#define pb push_back
#define endl "\n"
#define MOD 10000007

string check(int x, int y) {
    if ((2 * x - y) % 3 || (2 * x - y) < 0 || (2 * y - x) % 3 || (2 * y - x) < 0) return "NO\n";
    return "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    while(n--) {
        int x,y;
        cin >> x >> y;
        cout << check(x,y);
    }
    return 0;
}
