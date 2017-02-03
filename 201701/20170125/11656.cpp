# include <iostream>
# include <string>
# include <vector>
# include <algorithm>

using namespace std;

int main(void) {
  string input;
  vector<string> list;
  int length;

  cin >> input;
  length = input.length();
  list.push_back(input);

  for (int i = 0; i < length - 1; i++) {
    reverse(input.begin(), input.end());
    input.pop_back();
    reverse(input.begin(), input.end());
    list.push_back(input);
  }

  sort(list.begin(), list.end());

  for (int i = 0; i < length; i++) {
    cout << list[i] << "\n";
  }

  return 0;
}
