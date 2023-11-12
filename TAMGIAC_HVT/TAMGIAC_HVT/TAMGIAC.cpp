#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a*a + b * b == c * c) {
		cout << "vuong";
	}
	else if (a == b && b == c && a == c) {
		cout << "deu";
	}
	else if (a * b == a * c || b * c == a * b|| b*c == a*c) {
		cout << "can";
	}
	else if (a>0 && b >0 && c > 0) {
		cout << "thuong";
	}
	else {
		cout << "0";
	}
}