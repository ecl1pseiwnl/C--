#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> se;
typedef map<int, int> mii;
#define endl "\n";
#define mp make_pair
#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    getline(cin, s);
    int sum = 0;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == 'c' || c == 'f' || c == 'i' || c == 'l' || c == 'o' || c == 'r' || c == 'u' || c == 'x' || c == '!') {
            sum = sum + 3;
        }
        else if (c == 'b' || c == 'e' || c == 'h' || c == 'k' || c == 'n' || c == 'q' || c == 't' || c == 'w' || c == 'z' || c == ',') {
            sum = sum + 2;
        }
        else if (c == 'a' || c == 'd' || c == 'g' || c == 'j' || c == 'm' || c == 'p' || c == 's' || c == 'v' || c == 'y' || c == '.' || c == ' ') {
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}
