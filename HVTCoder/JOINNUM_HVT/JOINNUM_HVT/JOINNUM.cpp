#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define endl "\n"
#define mp make_pair
#define pb push_back
bool cmp(string a, string b) {
    if (a + b > a)
        return a + b > b + a;
    return a > b;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    vector<string>v;
    while (cin >> s) {
        v.push_back(s);
    }
    sort(v.begin(), v.end(), cmp);
    for (auto it : v){
        cout << it;
    }
    return 0;
}
