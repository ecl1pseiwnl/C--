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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll a,b,c;
    cin >> a >> b >> c;
    if (a < b + c || b < a + c || c < a + b) {
        if (a*a == b*b + c*c || b*b == a*a + c*c || c*c == a*a + b*b) {
            cout << "vuong";
        } else if (a == b && b == c) {
            cout << "deu";
        } else if (a == b || a == c || b == c) {
            cout << "can";
        } else cout << "thuong";
    } else cout << "0";
    return 0;
}
