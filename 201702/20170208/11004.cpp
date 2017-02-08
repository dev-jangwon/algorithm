# include <cstdio>
# include <vector>
# include <algorithm>

using namespace std;

int main(void) {
  int N, K;
  scanf("%d %d", &N, &K);
  vector<int> v;
  v.resize(N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &v[i]);
  }
  nth_element(v.begin(), v.begin() + (K - 1), v.end());
  printf("%d", v[K - 1]);
  return 0;
}
