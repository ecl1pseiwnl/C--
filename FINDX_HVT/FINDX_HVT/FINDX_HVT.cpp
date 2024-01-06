#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	char x;
	cin >> x;

	string s;
	cin.ignore();
	getline(cin, s);

	int dem = 0;
	string d;
	for (int i = 0; i < s.size();i++) {
		if (s[i] == x) {
			dem++;
			d += to_string(i) + " ";
		}
	}
	cout << dem << endl << d;
}