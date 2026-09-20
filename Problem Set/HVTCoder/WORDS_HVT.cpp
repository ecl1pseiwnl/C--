#include <bits/stdc++.h>
using namespace std;

void change(string s) {
	string temp;
	stringstream ss(s);
	while (ss >> temp) {
		cout << temp << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string s, temp, ans;
	getline(cin, s);
	stringstream ss(s);
	int cnt = 0;
	while (ss >> temp) {
		cnt++;
	}
	cout << cnt << endl;
	change(s);
}