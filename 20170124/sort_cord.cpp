# include <iostream>
# include <algorithm>
# include <cstdio>

using namespace std;

struct POS {
  int x;
  int y;
} pos[100005];

bool cmpx(POS p1, POS p2) {
  return p1.x < p2.x;
}

bool cmpy(POS p1, POS p2) {
  return p1.y < p2.y;
}

int main(void) {
  int N;
  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    scanf("%d %d", &pos[i].x, &pos[i].y);
  }

  stable_sort(pos, pos + N, cmpy);
  stable_sort(pos, pos + N, cmpx);

  for (int i = 0; i < N; i++) {
    printf("%d %d\n", pos[i].x, pos[i].y);
  }

  return 0;
}
