#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef map<int,int> mii;
#define mp make_pair
#define pb push_back
#define endl "\n"
#define MOD 10000007

const int N = 1005;
vector<pair<int,pair<int,int>>> v[N];
int n, a[N][N], dx[2] = {1,0}, dy[2] = {0,1};

void inp() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
}

bool isvalid(int i,int j,int n,int m) {
    if(i<0 || i>=n || j<0 || j>=m)
        return false;
    return true;
}

int dijkstra() {
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;
    q.push({a[0][0],{0,0}});
    vector<vector<int>> d(n, vector<int>(n, INT_MAX));
    d[0][0] = a[0][0];
    while(!q.empty()) {
        auto top = q.top();
        q.pop();
        int len = top.first;
        int currX = top.second.first;
        int currY = top.second.second;
        if (currX == n-1 && currY == n-1) return d[n-1][n-1];
        for (int i = 0; i < 2; i++) {
            int x = currX + dx[i], y = currY + dy[i];
                if (isvalid(x,y,n,n)) {
                    if (d[currX][currY] + a[x][y] < d[x][y]) {
                        d[x][y] = d[currX][currY] + a[x][y];
                        q.push({d[x][y],{x,y}});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    inp();
    cout << dijkstra();
    return 0;
}
