#include <iostream>
using namespace std;

const int maxN = 1e5+5;
int a[maxN], a1[maxN], a2[maxN], a3[maxN];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a1[i] = a1[i - 1] + (a[i] == 1);
        a2[i] = a2[i - 1] + (a[i] == 2);
        a3[i] = a3[i - 1] + (a[i] == 3);
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << a1[r] - a1[l - 1] << " " << a2[r] - a2[l - 1] << " " << a3[r] - a3[l - 1] << endl;
    }
}
