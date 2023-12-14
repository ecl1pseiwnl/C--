#include <iostream>
using namespace std;

bool check(int a[101][101], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i][i] != 1) return false;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((a[i][j] != 0) || (a[j][i] != 0)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, dem = 0;
    cin >> n;
    int a[101][101];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    if (check(a, n) == true) {
        cout << "1" << endl;
    }
    else cout << "0" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 0) {
                dem++;
            }
        }
    }
    cout << dem;
}
