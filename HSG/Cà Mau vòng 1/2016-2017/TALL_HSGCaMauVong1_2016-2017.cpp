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

bool cmp(pair<string, double> a, pair<string, double> b) {
    if (a.second != b.second) {
        return a.second > b.second;
    }
    else {
        return a.first < b.first;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    pair<string, double> p[n];
    for (int i = 0; i < n; i++) {
        string t; cin >> t;
        double x; cin >> x;
        string d; cin >> d;
        if (d == "dm") {
            x = x / 10;
        }
        else if (d == "cm") {
            x = x / 100;
        }
        else if (d == "mm") {
            x = x / 1000;
        }
        p[i] = make_pair(t, x);
    }
    sort(p, p + n, cmp);
    for (int i = 0; i < k; i++) {
        cout << p[i].first << endl;
    }
    return 0;
}
