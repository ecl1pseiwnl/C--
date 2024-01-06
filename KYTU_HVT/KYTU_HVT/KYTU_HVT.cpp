#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	char c;
	cin >> c;
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
		cout << "1"; 
	}
	else {
		cout << "0";
	}
}