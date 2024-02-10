#include <iostream>

using namespace std;

int main() {
    int n, f1 = 1, f2 = 1;
    cin >> n;
    cout << "1 1 ";
    for (int i = 3; i <= n; i++) {
        f1 = f1 + f2;
        f2 = f1 - f2;
        cout << f1 << " ";
    }
}
