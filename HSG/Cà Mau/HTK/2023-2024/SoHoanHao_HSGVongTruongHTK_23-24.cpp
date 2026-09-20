#include <iostream>
using namespace std;

int soHoanHao(int n) {
	int s = 0;
	if (n < 2) return 0;
	for (int i = 1; i <= n / 2; i++) {
		if (n % i == 0) {
			s += i;
		}
	}
	if (s == n) {
		return 1;
	}
	else return 0;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = n; i <= m; i++) {
		if (soHoanHao(i)) {
			cout << i << " ";
		}
	}
}