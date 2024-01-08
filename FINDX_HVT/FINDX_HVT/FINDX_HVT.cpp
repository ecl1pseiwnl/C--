#include <iostream>
#include <string>
using namespace std;

bool check(char c) {
	return c == ' ';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s, m;
	getline(cin, m);
	char x = m[0];
	getline(cin, s);

	int dem = 0;
	string d;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == x) {
			dem++;
			d += to_string(i) + " ";
		}
	}
	cout << dem << "\n" << d;
}