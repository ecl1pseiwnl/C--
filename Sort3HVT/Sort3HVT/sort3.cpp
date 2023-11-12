#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a[1000];
	for (int i = 0; i < 3; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < 3; j++) {
			if (a[i] > a[j]) swap(a[i], a[j]);
		}
	}
	for (int i = 0; i < 3; i++) {
		cout << a[i] << " ";
	}
}