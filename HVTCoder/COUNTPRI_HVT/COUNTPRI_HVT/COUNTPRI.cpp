#include <iostream>
#include <cmath>
using namespace std;

const int maxN = 1e6 + 1;
int a[maxN], F[maxN];

void sangsnt() {
    // a[i] = 1 => ko phai snt
    // a[i] = 0 => la snt
    a[1] = a[0] = 1;
    for (int i = 2; i <= sqrt(maxN); i++) {
        if (a[i] == 0) {
            for (int j = i * i; j < maxN; j += i) {
                a[j] = 1;
            }
        }
    }
    F[0] = F[1] = 0;
    for (int i = 2; i < maxN; i++) {
        if (a[i] == 0) {
            F[i] = F[i - 1] + 1;
        }
        else {
            F[i] = F[i - 1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    sangsnt();
    while (n--) {
        int l, r;
        cin >> l >> r;
        cout << F[r] - F[l - 1] << endl;
    }
}