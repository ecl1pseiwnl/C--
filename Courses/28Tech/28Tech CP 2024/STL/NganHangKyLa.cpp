#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> si;
typedef map<int, int> mii;
#define MOD 10000000007
#define endl "\n";
#define mp make_pair
#define pb push_back
bool snt(long long n)
{
    if(n<2) return false;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
         return false;
        }
    }
    return true;
}

int main() {
    #ifndef ONLINE_JUDGE

    #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n; cin >> n;
    if(snt(n))
    {
        cout << "1";
        return 0;
    }
    if(n%2==0)
    {
        cout <<"2";
        return 0;
    }
    if(snt(n-2)){ cout << "2"; return 0;}
    cout << "3";
    return 0;
}
