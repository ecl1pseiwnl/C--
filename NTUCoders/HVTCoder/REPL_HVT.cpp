#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector<string> v;
    string s1, s2, s;

    cin >> s1 >> s2;
    cin.ignore();
    getline(cin, s);
    while (s.find(s1) != string::npos) {
        int k = s.find(s1);
        s.erase(k, s1.size());
        s.insert(k, s2);
    }
    cout << s;
}