#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define endl "\n"
#define mp make_pair
#define pb push_back
int n, x[100];

void print() {
    for (int i = 1; i <= n; i++) {
        cout << x[i];
    }
    cout << endl;
}

void Backtrack(int i) {
    for (int j = 0; j <= 1; j++) {
        x[i] = j;
        if (i == n) {
            print();
        }
        else {
            Backtrack(i + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    Backtrack(1);
}