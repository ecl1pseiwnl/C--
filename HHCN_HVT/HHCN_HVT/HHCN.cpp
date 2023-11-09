#include <iostream>
using namespace std;

int HHCN(int a, int b, int c) {
	int c1 = a * b;
	int c2 = b * c;
	int c3 = a * c;
	return c1 + c2 + c3;
}
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << HHCN(a, b, c);
}