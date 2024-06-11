#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n/2; j++) {
			if (i % 2 == 1) {
				cout << "B" << "W";
			}
			
			if (i % 2 == 0) {
				cout << "W" << "B";
			}
			
		}
		if (n % 2 == 1 && i % 2 == 1) {
			cout << "B";
		}
		else if (n % 2 == 1 && i % 2 == 0) {
			cout << "W";
		}
		cout << endl;
	}
}