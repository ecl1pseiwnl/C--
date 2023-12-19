#include <iostream>
using namespace std;
double a[102][102];

int doixung(double a[102][102], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] != a[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, temp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    if (doixung(a, n) == 1) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    temp = a[0][0];
    if (temp % 2 == 1 && doixung(a, n) == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                cout << double(a[i][j]) << " ";
            }
            cout << endl;
        }
    }
    else if (temp % 2 == 1 && doixung(a, n) == 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = a[j][i];
                cout << double(a[i][j]) << " ";
            }
            cout << endl;
        }
    }
    else if (temp % 2 != 1 && doixung(a, n) == 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = a[j][i];
                cout << double(a[i][j]) << " ";
            }
            cout << endl;
        }
    }
}
