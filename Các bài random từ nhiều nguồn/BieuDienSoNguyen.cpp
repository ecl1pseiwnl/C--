#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int sl = 0;
    if (n <= 1) {
        cout << "-1";
    }
    else {
        if (n % 2 == 1) {
            sl += (n - 3) / 2 + 1;
            cout << sl << endl;
            sl--;
            while (sl--) {
                cout << "2" << " ";
            }
            cout << "3";
        }
        else {
            sl += n / 2;
            cout << sl << endl;
            while (sl--) {
                cout << "2" << " ";
            }
        }
    }
}
