# include <cstdio>
# include <algorithm>

using namespace std;

int main(void) {
  int arr1[100001];
  int arr2[100001];

  int N, M;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &arr1[i]);
  }

  sort(arr1, arr + N);

  scanf("%d", &M);
  for (int i = 0; i < M; i++) {
    scanf("%d", &arr2[i]);
  }

  sort(arr2, arr2 + M);

  for (int i = 0; i < N; i++) {
    printf("%d\n", arr1[i]);
  }


  return 0;
}
