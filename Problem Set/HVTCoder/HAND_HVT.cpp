#include <iostream>
using namespace std;

int main() {
    int m, k, dem = 0, phut = 0;
    cin >> m;
    int a[1000];
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    cin >> k;
    for (int i = 0; i < m; i++) {
        if (i < k - 1) {
            dem++;
            phut += a[i];
        }
    }
    cout << dem << endl << phut;
}
