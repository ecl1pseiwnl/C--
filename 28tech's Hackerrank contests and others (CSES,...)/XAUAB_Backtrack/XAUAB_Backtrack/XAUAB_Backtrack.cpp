#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define endl "\n"
#define mp make_pair
#define pb push_back
int n, cnt = 0, x[100], check;

void Declare() {
    for (int i = 0; i < n; i++) {
        x[i] = 0;
    }
}

void Sinh() {
    int i = n;
    while (i >= 1 && x[i] == 1) {
        x[i] = 0;
        i--;
    }
    if (i == 0) {
        check = 0;
    }
    else {
        x[i] = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    check = 1;
    Declare();
    while (check) {
        for (int i = 0; i < n; i++) {
            if (x[i] == 1) {
                cout << "B";
            }
            else cout << "A";
        }
        cout << endl;
        Sinh();
    }
}