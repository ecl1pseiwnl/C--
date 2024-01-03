#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string s;
	getline(cin, s);
	vector<int> v;
	for (int i = 0; i <= s.size(); i++) {
		if (s[i] == ' ') {
			cout << i << ' ';
			break;
		}
	}
	for (int i = s.size(); i >= 0; i--) {
		if (s[i] == ' ') {
			cout << i << ' ';
			break;
		}
	}
}
