#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define endl "\n"
#define mp make_pair
#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, a = 0, x = 0, y = 0;
    cin >> n;
    string s;
    cin.ignore();
    getline(cin, s);
    for (int i = 0; i < n; i++) {
        // (a) G = 1, B = 2, R = 3, L = 4
        // (b) duong = 1, am = -1
        if (a == 1) {
            if (s[i] == 'G') {
                y++;
                a = 1;
            }
            else if (s[i] == 'B') {
                y--;
                a = 2;
            }
            else if (s[i] == 'R') {
                x++;
                a = 3;
            }
            else if (s[i] == 'L') {
                x--;
                a = 4;
            }
        }
        else if (a == 2) {
            if (s[i] == 'G') {
                y++;
                a = 1;
            }
            else if (s[i] == 'B') {
                y--;
                a = 2;
            }
            else if (s[i] == 'R') {
                x--;
                a = 3;
            }
            else if (s[i] == 'L') {
                x++;
                a = 4;
            }
        }
        else if (a == 3) {
            if (s[i] == 'G') {
                x++;
                a = 1;
            }
            else if (s[i] == 'B') {
                x--;
                a = 2;
            }
            else if (s[i] == 'R') {
                y--;
                a = 3;
            }
            else if (s[i] == 'L') {
                y++;
                a = 4;
            }
        }
        else if (a == 4) {
            if (s[i] == 'G') {
                y++;
                a = 1;
            }
            else if (s[i] == 'B') {
                y--;
                a = 2;
            }
            else if (s[i] == 'R') {
                x++;
                a = 3;
            }
            else if (s[i] == 'L') {
                x--;
                a = 4;
            }
        }
        else {
            if (s[i] == 'G') {
                y++;
                a = 1;
            }
            else if (s[i] == 'B') {
                y--;
                a = 2;
                
            }
            else if (s[i] == 'R') {
                x++;
                a = 3;
            }
            else if (s[i] == 'L') {
                x--;
                a = 4;
            }
        }
    }
    cout << x << " " << y;
}