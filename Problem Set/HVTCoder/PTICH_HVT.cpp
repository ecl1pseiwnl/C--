#include <iostream>
#include <cmath>
using namespace std;
int snt(int n)
{
    if (n < 2)
        return 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
int main() {
    int n;
    cin >> n;
    int m = n;
    for (int i = 2; i <= sqrt(m); i++)
    {
        if (snt(i))
        {
            while (n % i == 0)
            {
                cout << i << " ";
                n /= i;
            }
        }
    }
    if (n != 1)
        cout << n;
    return 0;
}
