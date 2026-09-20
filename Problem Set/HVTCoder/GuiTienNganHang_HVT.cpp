#include <iostream>

using namespace std;

int main() {
	double n, m;
	cin >> n >> m;
	int count = 0;
	while (n < m) {
		ceil(n = n + (n / 10));
		count++;
	}
	cout << count;
}
