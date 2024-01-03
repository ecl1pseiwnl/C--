#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int dem = 0;
	char x;
	string s;
	cin >> x;
	cin.ignore();
	getline(cin, s);
	for (auto a : s) {
		if (a == x) {
			dem++;
		}
	}
	cout << dem << endl;
	for (int i = 0; i <= s.size();i++) {
		if (s[i] == x) {
			cout << i << ' ';
		}
	}
}