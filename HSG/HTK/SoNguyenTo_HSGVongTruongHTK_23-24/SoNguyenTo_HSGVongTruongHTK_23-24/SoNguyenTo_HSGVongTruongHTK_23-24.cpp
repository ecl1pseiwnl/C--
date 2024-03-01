#include <iostream>
#include <cmath>
using namespace std;
//Cach 1: Su dung sang so nguyen to Eratosthenes O(nlogn)
const int N = 1e8;
bool a[N + 1];

void sangSNT(int n) {
	for (int i = 0; i <= n; i++) {
		a[i] = 1;
		a[0] = 0; a[1] = 0;
	}
	for (int i = 2; i <= sqrt(n); i++) {
		for (int j = i * i; j <= n; j += i) {
			a[j] = 0;
		}
	}
}

int main() {
	int n;
	cin >> n;
	sangSNT(n);
	for (int i = 0; i <= n; i++) {
		if (a[i] == 1) {
			cout << i << " ";
		}
	}
	return 0;
}

//Cach 2: Su dung ham kiem tra so nguyen to O(n)

int SNT(int m) {
	if (m < 2) {
		return 0;
	}
	for (int i = 2; i * i <= m; i++) {
		if (m % i == 0) return 0;
	}
	return 1;
}

int main2() {
	int m;
	cin >> m;
	for (int i = 0; i <= m; i++) {
		if (SNT(i) == 1) {
			cout << i << " ";
		}
	}
	return 0;
}