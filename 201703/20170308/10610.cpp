# include <iostream>
# include <cstdio>
# include <string>
# include <queue>

using namespace std;

int main() {
  priority_queue<char> pq;
  char c;
  int sum = 0;
  string result;
  while(scanf("%c", &c) == 1 && c != 10) {
    pq.push(c);
  }
  while(!pq.empty()) {
    sum += pq.top() - '0';
    result += pq.top();
    pq.pop();
  }
  if (result[result.length() - 1] == '0' && (sum%3) == 0) {
    cout << result;
  } else {
    printf("-1");
  }
  return 0;
}
