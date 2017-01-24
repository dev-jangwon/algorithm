# include <iostream>
# include <algorithm>
# include <vector>

using namespace std;

int main(void) {
  int N;
  scanf("%d", &N);

  vector<int> v;
  int num;

  while(N--) {
    scanf("%d", &num);
    v.push_back(num);
  }

  sort(v.begin(), v.end());

  int N2, num2;
  scanf("%d", &N2);

  while(N2--) {
    scanf("%d", &num2);
    if (binary_search(v.begin(), v.end(), num2)) {
      printf("1 ");
    } else {
      printf("0 ");
    }
  }

  return 0;
}
