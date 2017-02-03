# include <cstdio>
# include <cstring>
# include <stack>

using namespace std;

int main(void) {
  char st[100005];
  scanf("%s", st);

  int N;
  scanf("%d", &N);

  stack<char> lst, rst;

  for (int i = 0; i < (int)strlen(st); i++) { // lst 초기화
    lst.push(st[i]);
  }

  while(N--) {
    char op;
    scanf(" %c", &op); // 반복문 안의 scanf -> 공백 추가
    if (op == 'P') {
      char add;
      scanf(" %c", &add);
      lst.push(add);
    } else if (op == 'L') {
      if (!lst.empty()) {
          char data = lst.top();
          rst.push(data);
          lst.pop();
      }
    } else if (op == 'D') {
      if (!rst.empty()) {
        char data = rst.top();
        lst.push(data);
        rst.pop();
      }
    } else if (op == 'B') {
      if (!lst.empty()) {
        lst.pop();
      }
    }
  }

  while(!lst.empty()) { // lst -> rst
    char top = lst.top();
    rst.push(top);
    lst.pop();
  }

  while(!rst.empty()) { // rst 출력
    char top = rst.top();
    printf("%c", top);
    rst.pop();
  }

  return 0;
}
