# include <cstdio>
# include <algorithm>
# include <vector>

using namespace std;

int main(void) {
  int N;
  scanf("%d", &N);

  vector<int> v;

  for (int i = 0; i < N; i++) {
    scanf("%d", v[i]);
  }

  for (int i = 0; i < N; i++) {
    printf("%d", v.at(i));
  }

  return 0;
}
