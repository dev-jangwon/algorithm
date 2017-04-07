# include <cstdio>
# include <vector>
# include <algorithm>

using namespace std;

int main(void) {
  int N;
  vector<int> v[101];
  vector<int> island;

  int temp;
  int min = 0;
  int brk = 0;

  scanf("%d", &N);
  island.resize(N);

  for (int i = 0; i < N; i++) {
    v[i].resize(N);
    island[i] = i;
    for (int j = 0; j < N; j++) {
      scanf("%d", &v[i][j]);
    }
  }

  do {
    temp = 0;
    brk = 0;
    for (int i = 0; i < N - 1; i++) {
      if (v[island[i]][island[i + 1]] != 0) {
        temp = temp + v[island[i]][island[i + 1]];
      } else {
        brk = 1;
        break;
      }
    }
    if (brk == 1) continue;
    if (v[island[N - 1]][island[0]] != 0) {
      if (min == 0 || temp + v[island[N - 1]][island[0]] < min) {
        min = temp + v[island[N - 1]][island[0]];
      }
    } else {
      continue;
    }
  } while(next_permutation(island.begin(), island.end()));
  printf("%d", min);
  return 0;
}
