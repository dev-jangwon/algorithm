# include <cstdio>
# define MAX 1000000000
using namespace std;

int main(void) {
    int num;
    int plusminus = 1;
    long long a = 0, b = 1, c = 1;
    long long result = 0;

    scanf("%d", &num);

    if (num < 0) {
      if (num % 2 == 0) {
        plusminus = -1;
      }
      num *= -1;
    } if (num == 0) {
      plusminus = 0;
    }

    for (int i = 0; i < num; i++) {
        if (i == 0) {
          result = 0;
        } if (i == 1) {
          result = 1;
        } else {
          c = (a + b) % MAX;
          a = b;
          b = c;
          result = c;
        }
    }
    printf("%d\n%lld\n", plusminus, result);
    return 0;
}
