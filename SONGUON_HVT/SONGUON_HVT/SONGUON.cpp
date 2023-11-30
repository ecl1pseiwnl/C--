#include <iostream>
typedef long long ll;

using namespace std;

int shh(ll k)
{
    int tong = 0;
    while (k > 0)
    {
        tong += k % 10;
        k /= 10;
    }
    return tong;
}
int main()
{
    long long n, ans = -1;
    cin >> n;
    for (int i = 1; i <= 81; i++) {
        if (i == shh(n - i)) ans = n - i;
    }
    cout << ans;
}