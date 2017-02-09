# include <cstdio>
# include <vector>
# include <algorithm>

using namespace std;

int main(void) {
  int N;
  vector<pair<int , int> > point;
  scanf("%d", &N);
  point.resize(N);
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &point[i].second, &point[i].first);
  }
  sort(point.begin(), point.end());
  for (int i = 0; i < N; i++) {
    printf("%d %d\n", point[i].first, point[i].second);
  }
  return 0;
}
