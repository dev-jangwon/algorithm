# include <cstdio>
# include <cstring>
# include <vector>
# include <queue>
# include <algorithm>

using namespace std;

vector<int> a[1001];
bool visited[1001];

void dfs(int now) {
  visited[now] = true;
  for (int i = 0; i < a[now].size(); i++) {
    int next = a[now][i];
    if (!visited[next]) {
      dfs(next);
    }
  }
}

int main() {
    int N, M, start;
    scanf("%d %d", &N, &M);

    for(int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        sort(a[i].begin(), a[i].end());
    }

    int cnt = 0;

    for(int i = 1; i <= N; i++) {
        if(visited[i] == false) {
            dfs(i);
            cnt++;
        }
    }

    printf("%d", cnt);
    return 0;
}
