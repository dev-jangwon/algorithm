# include <cstdio>
# include <vector>
# include <algorithm>

using namespace std;

int main(void) {
  int N, answer = 0;
  vector<pair<int,int> > v;
  scanf("%d", &N);
  v.resize(N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &v[i].first);
    v[i].second = i;
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < N; i++) {
    answer = max(answer, v[i].second - i);
  }
  printf("%d", answer + 1);
  return 0;
}
