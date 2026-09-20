#include <iostream>
#include <cmath>

using namespace std;

double ViTriCay(int x) {
	return sqrt(2 * x + 1 / 4 - 1 / 2);
}

int main() {
	int x;
	cin >> x;
	cout << round(ViTriCay(x));
}

int main2() {
	int x;
	cin >> x;
	double n = sqrt(2*x + 1 / 4 - 1 / 2);
	cout << round(n) << endl;
}

int main3() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (i * (i - 1) / 2 >= n) {
			cout << i - 1;
			break;
		}
	}
}