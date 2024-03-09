#include <iostream>
using namespace std;
int a[102][102];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int hang = n, cot = m, cnt = 1, p = 0, i;

    while (cnt <= m*n) {
        for (int i = p; i < cot; i++) {
            a[p][i] = cnt++;
        }
        for (int i = p + 1; i < hang; i++) {
            a[i][cot - 1] = cnt++;
        }
        if (p != hang - 1) {
            for (int i = cot - 2; i >= p; i--) {
                a[hang - 1][i] = cnt++;
            }
        }
        if (p != cot - 1) {
            for (int i = hang - 2; i > p; i--) {
                a[i][p] = cnt++;
                cout << a[i][p] << endl;
            }
        }
        p++; hang--; cot--;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
