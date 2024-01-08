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
    string s, ans;
    char x;
    cin >> x;
    cin.ignore();
    getline(cin, s);
    remove(s.begin(), s.end(), x);
    for (int i = 0; i < s.size() - 1; i++) {
        if (i >= s.size() - 2) {
            break;
        }
        ans += s[i];
    }
    cout << ans;
}