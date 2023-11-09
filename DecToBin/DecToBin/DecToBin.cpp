#include<iostream>
using namespace std;
int main()
{
    int n, r, m = 1, binary = 0;
    cin >> n;
    while (n != 0)
    {
        r = n % 2;
        binary = binary + (r * m);
        m = m * 10;
        n = n / 2;
    }
    cout << binary;
    return 0;
}