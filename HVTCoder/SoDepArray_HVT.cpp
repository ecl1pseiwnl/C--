#include <iostream>
using namespace std;

int soDep(int n) {
    int dem = 0, t;
    while (n != 0) {
        t = n % 10;
        if (t == 8 || t == 6) {
            dem++;
        }
        else {
            dem = 0;
            break;
        }
        n /= 10;
    }
    if (dem >= 1) {
        return 1;
    }
    else if (dem < 1) {
        return 0;
    }
}

int main() {
    int n, cnt = 0;
    cin >> n;
    int a[1000];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        if (soDep(a[i]) == 1) {
            cnt++;
        }
    }
    cout << cnt;
}
