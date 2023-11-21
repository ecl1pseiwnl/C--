#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n,i=2; cin >> n;
	if (n == 1) {
		cout << n;
		return 0;
	}
	while (n != 1) {
		while (n % i == 0) {
			cout << i << " ";
			n /= i;
		}
		i++;
	}
	return 0;
}