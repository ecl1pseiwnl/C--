#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;
    double a[10000];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) swap(a[i], a[j]);
        }
    }
    cout << setprecision(2) << fixed << a[n - 1] << " " << a[0];
}
