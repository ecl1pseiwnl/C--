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
    if ((a + b > c) && (a + c > b) && (b + c > a) && (a > 0 && b > 0 && c > 0)) {
        if (a*a == b*b + c*c || b*b == a*a + c*c || c*c == a*a + b*b) {
            return cout << "vuong", 0;
        } else if (a == b && b == c || a == c && c == b) {
            return cout << "deu",0;
        } else if (a == b || a == c || b == c) {
            return cout << "can", 0;
        } else {
            return cout << "thuong",0;
        }
    } else cout << "0";
    return 0;
}
