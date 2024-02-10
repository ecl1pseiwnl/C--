#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n, dem = 0;
	cin >> n;
	int a[4] = {50 ,20 ,10 };
	for (int i = 0; i < 4; i++) {
		dem += n / a[i];
		n %= a[i];
	}
	cout << dem;
}