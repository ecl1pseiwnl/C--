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

const int N = 1005;
int n, a[N][N];
vector<pi> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    cin.ignore();
    for (int i = 1; i <= n; i++) {
        string s, num;
        getline(cin, s);
        stringstream ss(s);
        while (ss >> num) {
            if (stoi(num) > i) {
                v.pb({ i,stoi(num) });
            }
        }
    }
    for (auto it : v) {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}
