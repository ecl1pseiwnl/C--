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

int n,m,ans=0;
vector<int> adj[4005];
vector<int> path;
bool visited[4005];
 void nhap(){
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
 }
void dfs(int u)
{
    visited[u] = true;
    path.push_back(u);
    for (int v : adj[u])
    {
        if (!visited[v]) dfs(v);
        else
        {
            int d = path.size() - (find(path.begin(), path.end(), v) - path.begin());
            if (d > ans)  ans = d;
        }
    }

    path.pop_back();
    visited[u] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    nhap();
    for (int i=1;i<=n;i++) dfs(i);
    cout << ans << endl;
    return 0;
}

