#include <iostream>
using namespace std;

const int N = 100002;
int a[N];

int main() {
    int n, m;
    cin >> n >> m;
    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
    }
    while (m--) {
        int l, r, a1 = 0, a2 = 0, a3 = 0;
        cin >> l >> r;
        for (int i = l; i <= r; i++) {
            if (a[i] == 1) {
                a1++;

            }
            else if (a[i] == 2) {
                a2++;

            }
            else {
                a3++;
            }
        } 
        cout << a1 << " " << a2 << " " << a3 << endl;
    }
    return 0;
}