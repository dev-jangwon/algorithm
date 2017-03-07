# include <cstdio>
# include <cstring>
# include <stack>

using namespace std;

int main(void) {
  int size, result = 0;
  char bracket[35];
  int multiple = 1;
  stack<char> st; // 괄호 스택

  scanf("%s", bracket);
  size = (int)strlen(bracket);

  for (int i = 0; i < size; i++) {
    if (bracket[i] == '(') {
      st.push(bracket[i]);
      multiple *= 2;
      if (bracket[i + 1] == ')') {
        result += multiple;
      }
    } else if (bracket[i] == '[') {
      st.push(bracket[i]);
      multiple *= 3;
      if (bracket[i + 1] == ']') {
        result += multiple;
      }
    } else if (!st.empty() && bracket[i] == ')') {
      multiple /= 2;
      st.pop();
    } else if (!st.empty() && bracket[i] == ']') {
      multiple /= 3;
      st.pop();
    }
  }
  if (st.empty()) {
    printf("%d", result);
  } else {
    printf("%d", 0);
  }
  return 0;
}
