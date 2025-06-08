#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define endl "\n"
#define mp make_pair
#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vi L(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                L[i] = max(L[i], L[j] + 1);
            }
        }
    }
    cout << *max_element(L.begin(), L.end());
}