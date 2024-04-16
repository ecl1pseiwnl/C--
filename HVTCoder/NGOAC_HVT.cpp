#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> si;
typedef map<int, int> mii;
#define MOD 10000000007
#define endl "\n";
#define mp make_pair
#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    int cnt = 0;
    getline(cin, s);
    for (char c : s) {
        if (cnt < 0) {
            cout << "KHONG DUNG";
            return 0;
        }
        if (c == '(') {
            cnt++;
        }
        else if (c == ')') {
            cnt--;
        }
        else if (c != '(' && c != ')') {
            cout << "KHONG HOP LE";
            return 0;
        }
    }
    if (cnt != 0)
    {
        cout << "KHONG DUNG";
        return 0;
    }
    cout << "DUNG";
    return 0;
}
