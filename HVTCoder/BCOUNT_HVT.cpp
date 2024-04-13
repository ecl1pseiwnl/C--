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

int a[10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, temp;
    getline(cin,s);
    stringstream ss(s);
    while (ss >> temp) {
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] >= '0' && temp[i] <= '9') {
                a[temp[i] -'0']++;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
