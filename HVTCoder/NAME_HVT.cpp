#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector<string> v;
    string s, temp;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        s[i] = tolower(s[i]);
    }
    stringstream ss(s);
    while (ss >> temp) {
        v.push_back(temp);
    }
    for (int i = 0; i < v.size(); i++) {
        v[i][0] = toupper(v[i][0]);
        cout << v[i] << " ";
    }
}