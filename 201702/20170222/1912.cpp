# include <cstdio>
# define MAX 1000005

using namespace std;

int main(void) {
  int N;
  int number[MAX];
  int dp[MAX];
  int max;

  scanf("%d", &N);

  for (int i = 1; i <= N; i++) {
    scanf("%d", &number[i]);
  }

  for (int i = 1; i <= N; i++) {
    if (dp[i - 1] + number[i] > number[i]) {
      dp[i] = dp[i - 1] + number[i];
    } else {
      dp[i] = number[i];
    }
  }
  max = dp[1];
  for (int i = 2; i <= N; i++) {
    if (max < dp[i]) {
      max = dp[i];
    }
  }
  printf("%d\n", max);
}
