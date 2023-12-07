#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {

    int n;
    cin >> n;
    double a[1000];
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    double tbc = sum / n;
    cout << fixed << setprecision(2) << tbc << endl;
    double t = abs(a[0] - tbc);
    double x = a[0];
    for (int i = 1; i < n; ++i) {
        double d = abs(a[i] - tbc);
        if (d < t) {
            t = d;
            x = a[i];
        }
    }
    cout << x << endl;
    return 0;
}
