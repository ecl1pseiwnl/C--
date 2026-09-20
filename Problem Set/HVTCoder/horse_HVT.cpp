#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define endl "\n"
#define mp make_pair
#define pb push_back
const int Max = 8;
int a[Max][Max];
int n, dem = 0, x, y;

void print() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int backtrack(int u, int v) {
    if (u > 0 && u <= n && v > 0 && v <= n) {
        if (a[u][v] == 0) {
            dem++;
            a[u][v] = dem;
            if (dem == n * n) {
                print();
            }
            else {
                backtrack(u - 1, v - 2);
                backtrack(u - 2, v - 1);
                backtrack(u - 2, v + 1);
                backtrack(u - 1, v + 2);
                backtrack(u + 1, v + 2);
                backtrack(u + 2, v + 1);
                backtrack(u + 2, v - 1);
                backtrack(u + 1, v - 2);
            }
            a[u][v] = 0;
            dem--;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> x >> y;
    backtrack(x, y);
    return 0;
}