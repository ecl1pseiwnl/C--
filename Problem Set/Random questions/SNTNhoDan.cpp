#include <iostream>
using namespace std;
typedef long long ll;

bool snt(int n) {
	if (n == 1) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	for (int i = 2; i < n; i++) {
		if (snt(i) == true) {
			cout << i << " ";
		}
	}
	return 0;
}