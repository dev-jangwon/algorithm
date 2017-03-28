# include <cstdio>
# define MAX 1000000

using namespace std;

int left[MAX], right[MAX], result[MAX];

int main(void) {
  int N, M;
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    scanf("%d", &left[i]);
  }
  for (int i = 0; i < M; i++) {
    scanf("%d", &right[i]);
  }
  int i = 0, j = 0, k = 0;
  while(i < N && j < M) {
    if (left[i] <= right[j]) {
      result[k++] = left[i++];
    } else {
      result[k++] = right[j++];
    }
  }
  while(i < N) {
    result[k++] = left[i++];
  }
  while(i < M) {
    result[k++] = right[j++];
  }
  for (int i = 0; i < N + M; i++) {
    printf("%d ", result[i]);
  }
  return 0;
}
