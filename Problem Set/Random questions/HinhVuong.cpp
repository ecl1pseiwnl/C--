#include <iostream>
using namespace std;

int main() {
	long long n;
	cin >> n;
	long long x, y;
	long long maxx = INT_MIN, maxy = INT_MIN, minx = INT_MAX, miny = INT_MAX;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		if (maxx < x) {
			maxx = x;
		}
		if (maxy < y) {
			maxy = y;
		}
		if (minx > x) {
			minx = x;
		}
		if (miny > y) {	
			miny = y;
		}
	}
	long long sum = max(maxx - minx, maxy - miny);
	cout << sum * sum;
}