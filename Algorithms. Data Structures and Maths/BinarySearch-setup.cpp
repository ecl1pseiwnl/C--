#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<mii> viii;
#define fi first
#define sec second
#define mp make_pair
#define pb push_back
#define endl "\n"
#define MOD 10000007

bool Binary_search(int a[], int l, int r, int x) {
    if (l > r) return false;
    int mid = (l+r)/2;
    if (a[mid] == x) {
        return true;
    } else if (a[mid] < x) {
        return Binary_search(a, mid+1, r, x);
    } else Binary_search(a,l,mid-1,x);
}

bool BS(int a[], int n, int x) {
    int l = 0, r = n - 1;
    while(l <= r) {
        int m = (l+r)/2;
        if (a[m] == x) {
            return true;
        } else (a[m] < x) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (Binary_search(a,0,n-1,x)) {
        cout << "1";
    } else cout << "0";
    return 0;
}
