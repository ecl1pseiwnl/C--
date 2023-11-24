#include <iostream> 
using namespace std;

int snt(int n) {
	if (n < 2) return 0;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}
int main() {
	int n;
	cin >> n;
	if (n == 2) cout << "-1";
	if (n < 10 && snt(n) == 0) {
		cout << "-1";
	}
	else {
		for (int i = 3; i <= n; i += 2) {
			if (n == 5) {
				cout << n - 2 << " " << n << endl;
				break;
			}
			if (snt(i) == 1 && snt(i + 2) == 1) {
				cout << i << " " << i + 2 << endl;
			}
		}
	}
}