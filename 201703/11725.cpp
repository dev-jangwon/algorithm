#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> adj[100000];
int parent[100000];

// 아직 탐색하지 않은 이웃 노드만을 DFS하며 부모를 자신으로 설정
void DFS(int cur) {
  for(int next: adj[cur])
    if(parent[next] == -1) {
      parent[next] = cur;
      DFS(next);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }
    // parent 배열 초기화 후 DFS 1회 실행
    memset(parent, -1, sizeof(parent));
    DFS(0);

    for(int i = 1; i < N; i++) {
      printf("%d\n", parent[i] + 1);
    }
    return 0;
}
