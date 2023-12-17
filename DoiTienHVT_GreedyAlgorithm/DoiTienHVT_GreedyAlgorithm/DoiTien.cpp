#include <iostream>
using namespace std;

int main() {
	long long n, dem = 0;
	cin >> n;
	int a[3] = {50 ,20 ,10 };
	for (int i = 0; i < 3; i++) {
		dem += n / a[i];
		n %= a[i];
	}
	cout << dem;
}