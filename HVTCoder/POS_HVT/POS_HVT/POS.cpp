#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    double x;
    double a[1000];
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            cout << setprecision(2) << fixed << a[i] << " ";
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] > 0) {
            cout << setprecision(2) << fixed << a[i] << endl;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            cout << i + 1 << " "; break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == x) {
            cout << i + 1 << " "; break;
        }
    }
}
