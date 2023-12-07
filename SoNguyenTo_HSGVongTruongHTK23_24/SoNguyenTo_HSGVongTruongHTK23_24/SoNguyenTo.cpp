#include <iostream>
using namespace std;

int SNT(int n) {
	if (n < 2) return 0;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int main() {
	long long n;
	cin >> n;
	for (long long i = 1; i <= n; i++) {
		if (SNT(i)) {
			cout << i << " ";
		}
	}
}