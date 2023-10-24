#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;
    int sumBP = 0;
    int sum2 = 0;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    for (int i = 1; i <= n; i++) {
        sumBP += pow(i, 2);
    }
    for (int i = 1; i <= n; i++) {
        while (i % 3 == 0) {
            count++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0) {
            sum2 += i;
        }
    }
    cout << sum << endl << sumBP << endl << count << endl << sum2 << endl;
}