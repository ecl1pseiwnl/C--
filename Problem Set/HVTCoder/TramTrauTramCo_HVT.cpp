#include <iostream>


using namespace std;

int main() {
    int n, m, x, y, z;
    cin >> n >> m;
    int dem = 0;
    int a = ( - 3 * m + 9 * n) / 8, b = ( - 3 * m + 15 * n) / 14;
    if (b > 0 && a < b) {
        for (int i = a; i <= b; i++) {
            if (i % 3 == 0) {
                z = i;
                x = (3 * m - 9 * n + 8 * z) / 6;
                y = (-3 * m + 15 * n - 14 * z) / 6;
                if (x > 0 && y > 0 && z > 0) {
                    cout << x << " " << y << " " << z << endl;
                    dem++;
                }
            }
        }
        if (dem == 0) {
            cout << "-1";
        }
    }
    else {
        cout << "-1";
    }
}
