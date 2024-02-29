#include <iostream>
#include <algorithm>
using namespace std;

int x[1000];
int n, check = 0;
void kt() {
	for (int i = 1; i <= n; i++) {
		x[i] = i;
	}
}
void sinh() {
	int i = n - 1;
	while (i >= 1 && x[i] > x[i + 1]) {
		i--;
	}
	if (i == 0) {
		check = 1;
	}
	else {
		int j = n;
		while (x[i] > x[j]) {
			j--;
		}
		swap(x[i], x[j]);
		reverse(x + i + 1, x + n + 1);
	}
}

int main() {
	cin >> n;
	kt();
	while (check == 0) {
		for (int i = 1; i <= n; i++) {
			cout << x[i] << " ";
		}
		cout << endl;
		sinh();
	}
}