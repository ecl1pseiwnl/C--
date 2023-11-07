#include <iostream>
#include <cmath>

using namespace std;

int main() {
	long long n;
	cin >> n;
	bool isPrime = true;
	for (int i = 2; i <= n/2; ++i) {
		if (n % i == 0) {
			isPrime = false;
			break;
		}
	}
	if (isPrime == false) {
		cout << "NO";
	}
	else {
		cout << "YES";
	}
}