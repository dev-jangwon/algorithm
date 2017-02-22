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
    d[i] = v[i];
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++) {
      if (v[j] < v[i] && d[j] + v[i] > d[i]) {
        d[i] = d[j] + v[i];
      }
    }
  }

  printf("%d", *max_element(d.begin(),d.end()));

  return 0;
}
