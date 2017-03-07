# include <cstdio>
# include <vector>
# include <algorithm>

using namespace std;

int main(void) {
  int N;
  vector<int> v;
  int sum = 0;
  scanf("%d", &N);
  v.resize(N + 1);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &v[i]);
  }
  sort(v.begin(), v.end());
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= i; j++) {
      sum = sum + v[j];
    }
    printf("%d\n", sum);
  }

  printf("sum: %d", sum);
  return 0;
}
