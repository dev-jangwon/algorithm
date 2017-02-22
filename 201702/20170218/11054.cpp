# include <cstdio>
# include <cstring>
# include <vector>

using namespace std;

int main(void) {
  int N;
  vector<int> v, dUp, dDown;
  scanf("%d", &N);
  v.resize(N);
  dUp.resize(N);
  dDown.resize(N);

  for(int i = 0; i < N; i++) {
    scanf("%d", &v[i]);
    dUp[i] = 1;
    dDown[i] = 1;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++) {
      if (v[j] < v[i] && dUp[i] < dUp[j] + 1) {
        dUp[i] = dUp[j] + 1;
      }
    }
  }
  for (int i = N - 1; i >= 0; i--) {
    for (int j = N - 1; j > i; j--) {
      if (v[j] < v[i] && dDown[i] < dDown[j] + 1) {
        dDown[i] = dDown[j] + 1;
      }
    }
  }

  int max = 0;

  for (int i = 0; i < N; i++) {
    int temp = dUp[i] + dDown[i] - 1;
    if (temp > max) {
      max = temp;
    }
  }
  printf("%d", max);
  return 0;
}
