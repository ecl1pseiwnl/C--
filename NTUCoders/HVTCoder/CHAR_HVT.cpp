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
    string s, s1;
    getline(cin, s);
    map<char, int> m;
    for (int i = 0; i < s.size(); i++) {
        s1 += tolower(s[i]);
    }
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != ' ') {
            m[s1[i]]++;
        }
    }
    for (auto i : m) {
        cout << i.first << " " << i.second << endl;
    }
}
