# include <iostream>
# include <string>
# include <stack>

using namespace std;

int main(void) {
  string bin;
  stack<int> oct;

  cin >> bin;

  int len = bin.length();
  for (int i = len - 1; i >= 0; i-=3) {
    int sum = 0;
    if (i == 0) {
      sum += bin[0] - '0';
    } else if (i == 1) {
      sum += (bin[1] - '0') + (bin[0] - '0') * 2;
    } else {
      sum += (bin[i] - '0') + (bin[i - 1] - '0') * 2 + (bin[i - 2] - '0') * 4;
    }
    oct.push(sum);
  }
  while(!oct.empty()) {
    cout << oct.top();
    oct.pop();
  }
  return 0;
}
