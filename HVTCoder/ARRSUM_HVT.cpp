#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int n;
    double a[1000];
    cin >> n;
    double sd = 0, sa = 0, sdu = 0, sc = 0, sl = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        sd += a[i];
    }
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            sa += a[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0) {
            sdu += a[i];
        }
    }
    for (int i = 1; i < n; i += 2) {
        sc += a[i];
    }
    for (int i = 0; i < n; i += 2) {
        sl += a[i];
    }
    cout << setprecision(2) << fixed << sd << " " << sa << " " << sdu << " " << sc << " " << sl;
}
