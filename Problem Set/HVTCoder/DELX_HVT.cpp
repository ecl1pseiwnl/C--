#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define mp make_pair
#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    char x;
    cin >> x;
    string s;
    cin.ignore();
    getline(cin, s);

    for (int i = 0; i < s.size(); i++) {
        if (s[i] != x) {
            cout << s[i];
        }
    }
}
