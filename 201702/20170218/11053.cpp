# include <cstdio>
# include <vector>
# include <algorithm>

using namespace std;

int main(void) {
  int N;
  vector<int> v;
  vector<int> d;
  scanf("%d", &N);

  v.resize(N);
  d.resize(N);

  for (int i = 0; i < N; i++) {
    scanf("%d", &v[i]);
    d[i] = 1;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++) {
      if (v[j] < v[i] && d[i] < d[j] + 1) {
        d[i] = d[j] + 1;
      }
    }
  }

  printf("%d", *max_element(d.begin(),d.end()));

  return 0;
}
