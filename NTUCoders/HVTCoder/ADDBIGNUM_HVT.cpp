#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef map<int, int> mii;
#define mp make_pair
#define pb push_back
#define endl "\n"
#define MOD 10000007

string a, b;
string csl(string a, string b) {
    int du = 0;
    int mid = 0;
    string res = "";
    a.insert(0, max(0, (int)(b.length() - a.length())), '0');
    b.insert(0, max(0, (int)(a.length() - b.length())), '0');
    for (int i = a.length() - 1; i >= 0; --i)
    {
        mid = ((int)a[i] - 48) + ((int)b[i] - 48) + du;
        du = mid / 10;
        res = (char)(mid % 10 + 48) + res;
    }
    if (du > 0) res = "1" + res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    cout << csl(a, b);
    return 0;
}
