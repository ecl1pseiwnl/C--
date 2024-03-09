#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int c = 0;
	if (n < 20 && m < 0) {
		cout << "-1";
	}
	else {
		while (2*m != n) {
			n++;
			m++;
			c++;
		}
		cout << c;
	}
}