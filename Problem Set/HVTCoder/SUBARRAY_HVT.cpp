#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> se;
typedef map<int, int> mp;
#define endl "\n"
#define mp make_pair
#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long s, sum = 0;
    cin >> n >> s;
    int a[1000], minn = n, pos = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        pos++;
        while (sum >= s)
        {
            minn = min(minn, pos);
            pos--;
            sum -= a[i - pos];
        }
        if (a[i] >= s)
        {
            cout << 1;
            return 0;
        }
    }
    cout << minn;
    return 0;
}