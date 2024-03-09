#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define endl "\n"
#define mp make_pair
#define pb push_back

bool check1(int x, int y, int u, int v) {
    return (u == x && v == y + 1) || (u == x && v == y - 1) || (u == x - 1 && v == y) || (u == x + 1 && v == y) || (u == x - 1 && v == y - 1) || (u == x - 1 && v == y + 1) || (u == x + 1 && v == y - 1) || (u == x + 1 && v == y + 1) || (x == u && y == v);
}

int main() {
    //freopen("DATA.INP","r",stdin);
    //freopen("DATA.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int x, y, u = 0, v = 0, check;
    int n;
    string s, time;
    cin >> x >> y;
    cin >> n;
    cin >> s;
    //R U L D
    for (int i = 0; i <= n; i++) {
        if (check1(x, y, u, v)) {
            check = 1;
            time += to_string(i) + "\n";
        }
        if (s[i] == 'R') {
            u++;
        }
        else if (s[i] == 'U') {
            v++;
        }
        else if (s[i] == 'L') {
            u--;
        }
        else if (s[i] == 'D') {
            v--;
        }
    }
    if (check == 1) {
        cout << time;
    }
    else {
        cout << "-1";
    }
}
