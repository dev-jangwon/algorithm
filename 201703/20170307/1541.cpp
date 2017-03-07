# include <iostream>
# include <string>

using namespace std;

int main(void) {
  string s;
  cin >> s;

  int length = s.length();

  int sum = 0;
  string temp = "";
  int result = 0;
  bool flag = false;

  for (int i = 0; i < length + 1; i++) {
    if (s[i] == '+' || s[i] == '-' || i == (length)) {
      if (!flag) {
          result = result + atoi(temp.c_str());
      } else {
        result = result - atoi(temp.c_str());
      }
      if (s[i] == '-') {
        flag = true;
      }
      temp = "";
      continue;
    }
    temp += s[i];
  }
  cout << result;
  return 0;
}
