#include <iostream>
#include <vector>
using namespace std;

int a, b;
const int N = 20;
vector<int> e[N];
bool vis[N];

void dfs(int u, int fa)
{
	vis[u] = true;
	for (auto v : e[u])
	{
		if (vis[v]) continue;	
		cout << u << " " << v << endl;
		dfs(v, u);
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	dfs(1, 0);
	return 0;
}