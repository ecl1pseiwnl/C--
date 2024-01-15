#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define endl "\n"
#define mp make_pair
#define pb push_back
const int Max = 8;
int a[Max][Max] = { 0 };
int X[Max] = {2,2,-2,-2,-1,1,-1,1}, Y[Max] = {1,2,-2,-1,1,2,-1,-2};
int n, dem = 0;

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void backtrack(int x, int y) {
    ++dem;
    a[x][y] = dem;
    for (int i = 0; i < 8; i++) {
        if (dem == n * n) {
            print();
        }
        int u = x + X[i], v = y + Y[i];
        if (u >= 0 && u < n && v >= 0 && v < n && a[u][v] == 0) {
            backtrack(u, v);
        }
    }
    --dem;
    a[x][y] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    int x, y;
    cin >> x >> y;
    backtrack(x, y);
}