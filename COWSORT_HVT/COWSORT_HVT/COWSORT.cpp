#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int dem = n, a[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = n; i > 0; i--) {
		if (a[i] > a[i - 1]) {
			dem--;
		}
		else
		{
			break;
		}
	}
	cout << dem - 1;
	return 0;
}