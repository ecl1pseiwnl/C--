#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ll a, b, c;
	cin >> a >> b >> c;
	ll s1 = (a*c)/b, s2 = (b*c)/a, s3 = (a*b)/c;
	cout << 4 * (s1+s2+s3);
}
