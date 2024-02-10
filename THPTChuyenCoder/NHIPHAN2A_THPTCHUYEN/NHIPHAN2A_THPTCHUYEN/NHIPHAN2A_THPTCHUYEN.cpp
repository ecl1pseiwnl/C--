#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define endl "\n"
#define mp make_pair
#define pb push_back
int n, x[100], cnt = 0, check = 0;

void print() {
    check = 0;
    for (int i = 1; i <= n; i++) {
        if (x[i] == 0 && x[i+1] == 1) {
            check++;
        }
    }
    if (check <= 1) {
        for (int i = 1; i <= n; i++) {
            cout << x[i];
        }
        cnt++;
        cout << endl;
    }
}

void backtrack(int i) {
    for (int j = 0; j <= 1; j++) {
        x[i] = j;
        if (i == n) {
            print();
        }
        else {
            backtrack(i + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    backtrack(1);
    cout << cnt;
}