#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string s;
	getline(cin, s);
	int a[10];
	for (int i = 0; i < 10; i++) {
		a[i] = 0;
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 48 && s[i] <= 57) {
			switch (s[i]) {
				case 48: {
					a[0]++;
					break;
				}
				case 49: {
					a[1]++;
					break;
				}
				case 50: {
					a[2]++;
					break;
				}
				case 51: {
					a[3]++;
					break;
				}
				case 52: {
					a[4]++;
					break;
				}
				case 53: {
					a[5]++;
					break;
				}
				case 54: {
					a[6]++;
					break;
				}
				case 55: {
					a[7]++;
					break;
				}
				case 56: {
					a[8]++;
					break;
				}
				case 57: {
					a[9]++;
					break;
				}
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		cout << a[i] << ' ';
	}
}