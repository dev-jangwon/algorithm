# include <cstdio>
# include <vector>
# include <algorithm>

using namespace std;

int main(void) {
  int N;
  scanf("%d", &N);
  int count, max;
  long long ans;

  vector<long long> cards;
  cards.resize(N);

  for (int i = 0; i < N; i++) {
    scanf("%lld", &cards[i]);
  }

  sort(cards.begin(), cards.end());

  ans = cards[0];
  count = 1, max = 1;

  for (int i = 1; i < N; i++) {
    if (cards[i - 1] == cards[i]) {
      count++;
    } else {
      count = 1;
    }
    if (count > max) {
      max = count;
      ans = cards[i];
    }
  }

  printf("%lld", ans);

  return 0;
}
