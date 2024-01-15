#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define endl "\n"
#define mp make_pair
#define pb push_back

bool check(int u, int v, int x, int y) {
    return (u == x + 1) || u == x - 1 || (v == y + 1 && u == x - 1) || (v == y - 1 && u == x + 1) || (v == y + 1 && u == x + 1) || v == y - 1 || v == y + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int x, y, u = 0, v = 0, t = 0;
    int n;
    string s, time;
    cin >> x >> y;
    cin >> n;
    cin >> s;
    //R U L D
    for (int i = 0; i < n; i++) {
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
        if (check(u,v,x,y)) {
            time += i + "\n";
            t++;
        }
    }
    if (t > 0) {
        cout << time;
    }
    else {
        cout << "-1";
    }

}
