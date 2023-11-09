#include <iostream>
#include <cmath>

using namespace std;

bool check(long n) {
	if (n == 1 || n == 0) {
		return false;
	}
	for (long long i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	long long n;
	cin >> n;
	while (n > 0) {
		if (check(n)) {
			cout << n << endl;
		}
		n /= 10;
	}
	return 0;
}

//Cach 2: Su dung sang so nguyen to
const long long N = 1e8;
long long a[N];
void snt() {
	for (int i = 0; i < N; i++) {
		a[i] = 1;
		if (i == 0 || i == 1) a[i] = 0;
	}
	for (int i = 2; i <= sqrt(N); i++) {
		for (int j = i * i; i < N; j += i) {
			a[i] = 0;
		}
	}
}