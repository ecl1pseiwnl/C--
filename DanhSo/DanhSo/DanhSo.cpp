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