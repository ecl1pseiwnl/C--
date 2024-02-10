#include <iostream>
#include <algorithm>
using namespace std;

int a[100];

int main() {
	for (int i = 0; i < 4; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 4; j++) {
			if (a[i] > a[j]) swap(a[i], a[j]);
		}
	}
	cout << a[0] << " " << a[3];
}