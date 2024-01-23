#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> se;
typedef map<int, int> mp;
#define endl "\n"
#define mp make_pair
#define pb push_back

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll m1, m2, m3, c1, c2, c3, temp = 0;
    cin >> m1 >> c1 >> m2 >> c2 >> m3 >> c3;
    int i = 0;
    while (i < 100) {
        i++;
        temp = c1;
        if (c1 + c2 <= m2) {
            c2 += c1;
            c1 -= temp;
        }
        ////////////
        temp = c2;
        if (c2 + c3 <= m3) {
            c3 += temp;
            c2 -= temp;
        }
        ////////////
        temp = c3;
        if (c3 <= m1) {
            c1 += temp;
            c3 -= temp;
        }
        else {
            c3 -= m1;
            c1 += m1;
        }
        temp = 0;
    }
    cout << c1 << endl << c2 << endl << c3;
    return 0;
}