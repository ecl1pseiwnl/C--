#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
	double a, b, c;
	cin >> a >> b >> c;
	cout << fixed << setprecision(2) <<(a + b + c) / 3 << endl << cbrt(a*b*c);
}