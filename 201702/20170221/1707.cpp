# include <cstdio>
# include <vector>
# include <queue>

# define MAX 20005

using namespace std;

vector<int> graph[MAX];
bool color[MAX];

bool BFS(int root) {
  queue<int> q;
  q.push(root);
  color[root] = 1;

  while(!q.empty()) {
    int now = q.front();
    q.pop();

    for (int i = 0; i < graph[now].size(); i++) {
      int next = graph[now][i];

      if (color[next] == 0) {
        color[next] = ~color[now];
        q.push(next);
      } else {
        if (color[next] == color[now]) {
          return false;
        }
      }
    }
  }
  return true;
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int V, E;
    bool res = true;
    scanf("%d %d", &V, &E);

    for (int i = 1; i <= V; i++) {
      graph[i].clear();
      color[i] = 0;
    }

    for (int i = 0; i < E; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    for (int i = 1; i <= V; i++) {
      if (color[i] == 0) {
        res &= BFS(i);
      }
    }

    if (res == true) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
