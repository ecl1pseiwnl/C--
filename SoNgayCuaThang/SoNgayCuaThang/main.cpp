#include <iostream>
using namespace std;

int main() {
    int t, n;
    cin >> t >> n;
    if (n > 0 && t <= 12 && t > 0) {
        if (t == 1 || t == 3 || t == 5 || t == 7 || t == 8 || t == 10 || t == 12) {
            cout << "31" << endl;
        }
        else if (t == 4 || t == 6 || t == 9 || t == 11) {
            cout << "30" << endl;
        }
        else if (t == 2) {
            if ((n >= 0 && n <= 5000 && n % 400 == 0) || (n >= 0 && n <= 5000 && n % 4 == 0 && n % 100 != 1)) {
                cout << "29" << endl;
            }
            else {
                cout << "28" << endl;
            }
        }
    }
    else {
        cout << "INVALID" << endl;
    }
}
