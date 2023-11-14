#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;
    int sum = 0;
    for (int i = n; ; i--) {
        if (i != 0) {
            for (int j = 1; j <= n; j++) {
                cout << "*";
            }
            cout << endl;
            n--;
        }
        else {
            break;
        }
    }
}
