#include <iostream>
#include <string>

using namespace std;

bool DoiXung(string S) {
    long Q = S.size();
	for (int i = 0; i < Q; ++i) {
		if (S[i] != S[Q - i - 1]) {
			return false;
		}
	}
	return true;
}

int main() {
	string S;
	cin >> S;
	if (DoiXung(S)) {
		cout << "1" << endl;
	}
	else {
		cout << "0" << endl;
	}
}