#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	int dem = n, a[101];
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