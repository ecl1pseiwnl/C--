#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    int cnt;
    long long sum = 0;
    for (int i = 2; i <= n; i++) {
        cnt = 0;
        while (n % i == 0) {
            cnt++;
            if (cnt == 1) {
                sum += i;
            }
            n /= i;
        }
    }
    cout << sum << endl;
}
// cach 2:

int snt(int N) {
    if (N < 2) return 0;
    for (int i = 2; i * i <= N; i++) {
        if (N % i == 0) return 0;
    }
    return 1;
}

int main2() {
    int N, s = 0;
    cin >> N;
    for (int i = 2; i <= N; i++) {
        if (N % i == 0 && snt(N)) {
            s += i;
        }
    }
    cout << s;
}