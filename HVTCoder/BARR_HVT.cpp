#include <iostream>
using namespace std;
int a[102][102];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, n, maxrow = INT_MIN, minrow = INT_MAX, maxpos, minpos;
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        int s = 0;
        for (int j = 0; j < n; j++) {
            s += a[i][j];
        }
        if (maxrow < s) {
            maxrow = s;
            maxpos = i + 1;
        }
        if (minrow > s) {
            minrow = s;
            minpos = i + 1;
        }
        cout << s << " ";
    }
    cout << endl << maxpos << " " << minpos;
    return 0;
}
