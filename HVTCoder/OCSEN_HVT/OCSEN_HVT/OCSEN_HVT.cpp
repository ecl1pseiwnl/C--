#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	ll a, b, v, cnt = 0, s = 1;
	cin >> a >> b >> v;
	cout << (v >= a ? (ll)ceil((double)(v - a) / (a - b)) + 1 : 1);
}