#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<mii> viii;
#define name "TASK"
#define fi first
#define sec second
#define mp make_pair
#define pb push_back
#define endl "\n"
#define MOD 10000007

int n;
string s = "";

void backtrack(int i) {
    if (i > n) {
        cout << s << "\n";
        return;
    }
    for (char j = '0'; j <= '1'; j++) {
        s.push_back(j);
        backtrack(i+1);
        s.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    backtrack(1);
    return 0;
}
