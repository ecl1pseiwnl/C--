#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define endl "\n"
#define mp make_pair
#define pb push_back
int n, x[100], cot[100], d1[100], d2[100];

void print() {
    for (int i = 1; i <= n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

void backtrack(int i) {
    for (int j = 1; j <= n; j++) {
        if (cot[j] == 1 && d1[i - j + n] == 1 && d2[i + j - 1] == 1) {
            x[i] = j;
            cot[j] = d1[i - j + n] = d2[i + j - 1] = 0;
            if (i == n) {
                print();
            }
            else {
                backtrack(i + 1);
            }
            cot[j] = d1[i - j + n] = d2[i + j - 1] = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= 98; i++) {
        cot[i] = d1[i] = d2[i] = 1;
    }
    backtrack(1);
}