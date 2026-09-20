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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n, s = 0;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a;
        cin >> a;
        s += a;
    }
    cout << n*(n+1)/2 - s;
    return 0;
}

/*
You are given all numbers between 1,2,. . .,n except one.
Your task is to find the missing number.

Input
The first input line contains an integer n.
The second line contains n-1 numbers. Each number is distinct and between 1 and n (inclusive).
Output
Print the missing number.
Constraints

2 <= n <= 2.10^5

Example
Input:
5
2 3 1 5
Output:
4
*/
