#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long n, m, maxArr = INT_MIN, minArr = INT_MAX, minrow, mincol, maxrow, maxcol;
    cin >> n >> m;
    int a[102][102];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (minArr > a[i][j]) {
                minArr = a[i][j];
                minrow = i + 1;
                mincol = j + 1;
            }
            if (maxArr < a[i][j]) {
                maxArr = a[i][j];
                maxrow = i + 1;
                maxcol = j + 1;
            }
        }
    }
    cout << minArr << " " << minrow << " " << mincol << endl;
    cout << maxArr << " " << maxrow << " " << maxcol;
}
