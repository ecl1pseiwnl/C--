#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    getline(cin, s);
    set<char> c;
    for (int i = 0; i < s.size(); i++) {
        c.insert(s[i]);
    }
    if (c.size() % 2 == 1) {
        cout << "IGNORE HIM!";
    }
    else if (c.size() % 2 == 0) {
        cout << "CHAT WITH HER!";
    }
}