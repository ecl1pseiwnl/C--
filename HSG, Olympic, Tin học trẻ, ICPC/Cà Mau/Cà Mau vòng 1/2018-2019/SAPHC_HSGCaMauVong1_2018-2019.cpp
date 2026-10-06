#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> si;
typedef map<int, int> mii;
#define MOD 1000000007
#define endl "\n"
#define mp make_pair
#define pb push_back

struct dt {
    int va, ba, don, tong;
    string ten;
};

bool cmp(dt a, dt b) {
    if (a.va > b.va) {
        return a.va > b.va;
    }
    else if (a.va == b.va) {
        return a.ba > b.ba;
    }
    return a.tong > b.tong;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cin.ignore();
    dt doi[n];
    for (int i = 0; i < n; i++) {
        int a = 0, b = 0, c = 0, check = 0;
        string s, temp;
        getline(cin, s);
        stringstream ss(s);
        while (ss >> temp) {
            if (check) {
                for (int j = 0; j < temp.size(); j++) {
                    if (temp[j] == 'D') {
                        c++;
                    }
                    else if (temp[j] == 'B') {
                        b++;
                    }
                    else if (temp[j] == 'V') a++;
                }
            }
            else {
                doi[i].ten = temp;
            }
            check = 1;
        }
        doi[i].va = a;
        doi[i].ba = b;
        doi[i].don = c;
        doi[i].tong = a + b + c;
    }
    sort(doi, doi + n, cmp);
    for (auto it : doi) {
        cout << it.ten << " " << it.va << "V " << it.ba << "B " << it.don << "D" << "\n";
    }
    return 0;
}