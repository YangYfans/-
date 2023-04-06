#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 6000;
int n, x, y;
int w[N], fa[N];
int vis[N];
int a[N][N];
int b[N];
int f[N][2];
void dfs(int u)
{
    f[u][1] = w[u];
    for (int i = 0; i < b[u]; i++)
    {
        int v = a[u][i];
        dfs(v);
        f[u][0] += max(f[v][0], f[v][1]);
        f[u][1] += f[v][0];
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        a[y][b[y]++] = x;
        fa[x] = 1;
    }

    int root = 1;
    while (fa[root]) root++;
    dfs(root);
    cout << max(f[root][0], f[root][1]) << endl;
}