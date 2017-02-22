#include <iostream>
#include <stack>
#include <queue>
#include <string.h>
using namespace std;

bool chk[1020];
void dfs(int v);
void bfs(int v);
int n, m, v;
int arr[1020][1020];
queue<int>q;
int main()
{
	int a, b;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		arr[a][b] = arr[b][a] = 1;
	}
	dfs(v);
	memset(chk, false, 1020);
	cout << endl;
	bfs(v);
	return 0;
}

void dfs(int v)
{
	chk[v] = true;
	cout << v << " ";
	for (int i = 1; i <= n; i++)
		if (arr[v][i] == 1 && !chk[i])
			dfs(i);
}

void bfs(int v)
{
	chk[v] = true;
	q.push(v);
	int now;
	while (!q.empty())
	{
		now = q.front();
		cout << now << " ";
		q.pop();
		for (int i = 1; i <= n; i++)
			if (arr[now][i] == 1 && !chk[i])
			{
				chk[i] = true;
				q.push(i);
			}
	}
}
