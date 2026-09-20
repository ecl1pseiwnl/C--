#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;
    double a[1000];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) swap(a[i], a[j]);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << setprecision(2) << fixed << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) swap(a[i], a[j]);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << setprecision(2) << fixed << a[i] << " ";
    }
}
