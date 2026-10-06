#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct pr {
	int x, y, z, w;
};

int main() {
	string s;
	int q;
	cin >> s;
	cin >> q;
	vector<pr> v(q);
	for (int i = 0; i < q; i++) {
		cin >> v[i].x >> v[i].y;
		v[i].x--;
		v[i].y--;
		v[i].z = -1;
		v[i].w = v[i].y - v[i].x + 1; 
	}
	int n = s.length();
	for (int i = 0; i < v.size();) { 
		char h = s[v[i].x], t = s[v[i].y];
			if (v[i].x < n && v[i].y < n) {
				for (int j = 0; j < v[i].w / 2; j++) {
					if (h != t) {
						v[i].z = 0;
						break;
					}
					h = s[v[i].x++];
					t = s[v[i].y--];
					v[i].z = 1;
				}
			}
			else {
				v[i].z = 0;
			}
		i++;
	}
	for (int i = 0; i < v.size(); i++) {
		cout <<"\n" << v[i].z;
	}
}

//Cach 2
bool check(string s, int x, int y) {
	int l = x - 1, r = y - 1;
	while (l <= r) {
		if (s[l] != s[r]) {
			return false;
		}
		else {
			l++;
			r--;
		}
	}
	return true;
}

int main() {
	//freopen("SACH.inp", "r", stdin);
	//freopen("SACH.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string s;
	getline(cin, s);
	int n;
	cin >> n;
	while (n--) {
		int x, y;
		cin >> x >> y;
		if (check(s, x, y)) {
			cout << "1" << endl;
		}
		else {
			cout << "0" << endl;
		}
	}
	return 0;
}
