#include <iostream>
#include <math.h>
using namespace std;

int pagesNumbering(int n)
{
    int result = 0;
    int exponent = 1;
    while (n > 0) {
        int pow9 = pow(10, exponent) - pow(10, exponent - 1);
        if (n >= pow9) result += pow9 * exponent++;
        else result += n * exponent++;
        n -= pow9;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    cout << pagesNumbering(n);
}
