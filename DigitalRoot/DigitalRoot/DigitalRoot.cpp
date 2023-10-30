#include <iostream> 
using namespace std;

int main() {
	long long n;
	cin >> n;
	long long tong = 0;
	while (n != 0) {
		n % 10;
		tong += n;
		n /= 10;
	}
	cout << tong;
	return 0;
}