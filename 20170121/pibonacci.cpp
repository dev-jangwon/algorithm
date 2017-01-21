# include <iostream>

using namespace std;

int main(void) {
  int N, first = 0, second = 1, fibo = 0;

  cin >> N;

  if (N == 0 || N == 1) {
    cout << first;
  } else if (N == 2) {
    cout << second;
  } else {
    for (int i = 2; i < N; i++) {
      fibo = first + second;
      first = second;
      second = fibo;
    }
    cout << fibo;
  }

  return 0;
}
