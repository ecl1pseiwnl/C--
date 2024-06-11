#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	getline(cin, s);
	reverse(s.begin(), s.end());
	cout << s;
	return 0;
}