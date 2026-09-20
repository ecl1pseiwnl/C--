#include <iostream>
using namespace std;
typedef long long ll;
int main() {
	ll n, res, s = 0, temp;
	cin >> n;
	temp = n;
	while (n != 0) {
		res = n % 10;
		s = (s * 10) + res;
		n /= 10;
	}
	if (temp == s) {
		cout << "1";
	}
	else {
		cout << "0";
	}
}

//dung ham kiem tra co phai chuoi palindrome hay khong

int checkPalindrome(ll n) {
	int res, temp;
	ll s = 0;
	temp = n;
	while (n != 0) {
		res = n % 10;
		s = (s * 10) + res;
		n /= 10;
	}
	if (temp == n) {
		return 1;
	}
	else return 0;
}