#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define endl "\n"
#define mp make_pair
#define pb push_back
int a[9][9], row[9], col[9];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int x1, x2, dem = 0;
    char y1, y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    int x11 = 9 - x1, x22 = 9 - x2;
    char y11 = int(y1) - 96, y22 = int(y2) - 96;
    a[x11][y11] = 1;
    a[x22][y22] = 1;
    for (int i = 1; i <= 8; i++) {
        a[y22][i] = 1;
        a[i][x11] = 1;
    }
    for (int i = 1; i <= 8; i++) {
        if (x22 + row[i] >= 0 && y22 + col[i] >= 0) {
            a[x22 + row[i]][y22 + col[i]] = 1;
        }
    }
    for (int i = 1; i <= 8; i++) {
        if (x11 + row[i] >= 0 && y11 + col[i] >= 0) {
            a[y11 + row[i]][x11 + col[i]] = 1;
        }
    }

    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            if (a[i][j] == 0) dem++;
        }
    }
    cout << dem;
}